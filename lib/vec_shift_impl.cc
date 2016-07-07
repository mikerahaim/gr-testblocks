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
#include "vec_shift_impl.h"

namespace gr {
  namespace testblocks {

    vec_shift::sptr
    vec_shift::make()
    {
      return gnuradio::get_initial_sptr
        (new vec_shift_impl());
    }

    /*
     * The private constructor
     */
    vec_shift_impl::vec_shift_impl()
      : gr::sync_block("vec_shift",
              gr::io_signature::make(1, 1, 3*sizeof(float)),
              gr::io_signature::make(1, 1, 3*sizeof(float)))
    {}

    /*
     * Our virtual destructor.
     */
    vec_shift_impl::~vec_shift_impl()
    {
    }

    int
    vec_shift_impl::work(int noutput_items,
                         gr_vector_const_void_star &input_items,
                         gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];
      
      /* For each vector length of 3, shift the 1st and 2nd values over,
       * then move the 3rd value to the 1st position in the vector.
       */
      for(int i = 0; i < noutput_items; i++) {
        for(int j = 0; j < (3-1); j++) {
          out[i*3 + (j+1)] = in[i*3 + j];
        }
        out[i*3] = in[i*3+(3-1)];
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace testblocks */
} /* namespace gr */

