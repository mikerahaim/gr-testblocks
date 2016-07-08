/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "vec_shift_var_impl.h"

namespace gr {
  namespace testblocks {

    vec_shift_var::sptr
    vec_shift_var::make(int vec_len, int shift)
    {
      return gnuradio::get_initial_sptr
        (new vec_shift_var_impl(vec_len, shift));
    }

    /*
     * The private constructor
     */
    vec_shift_var_impl::vec_shift_var_impl(int vec_len, int shift)
      : gr::sync_block("vec_shift_var",
              gr::io_signature::make(1, 1, vec_len*sizeof(float)),
              gr::io_signature::make(1, 1, vec_len*sizeof(float)))
    {
      vec_shift_var_impl::my_vlen = vec_len;
      vec_shift_var_impl::my_shift = shift;
      while (vec_shift_var_impl::my_shift > vec_len)
      {
        vec_shift_var_impl::my_shift-=vec_len;
      }
    }

    /*
     * Our virtual destructor.
     */
    vec_shift_var_impl::~vec_shift_var_impl()
    {
    }

    int
    vec_shift_var_impl::work(int noutput_items,
                             gr_vector_const_void_star &input_items,
                             gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];
      int vec_start;
      int switch_point;

      /* For each vector length of N, shift the 1st N-1 values over,
       * then move the Nth value to the 1st position in the vector.
       */
      switch_point = vec_shift_var_impl::my_vlen-vec_shift_var_impl::my_shift;
      for(int i = 0; i < noutput_items; i++) {
        vec_start = i*vec_shift_var_impl::my_vlen;
        for(int j = 0; j < switch_point; j++) {
          out[vec_start + (j+vec_shift_var_impl::my_shift)] = in[vec_start + j];
        }
        for(int j = switch_point; j < vec_shift_var_impl::my_vlen; j++) {
          out[vec_start + j - switch_point] = in[vec_start+j];
        }
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace testblocks */
} /* namespace gr */

