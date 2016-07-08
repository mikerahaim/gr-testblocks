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
#include "vec_resize_impl.h"

namespace gr {
  namespace testblocks {

    vec_resize::sptr
    vec_resize::make(int in_len, int out_len)
    {
      return gnuradio::get_initial_sptr
        (new vec_resize_impl(in_len, out_len));
    }

    /*
     * The private constructor
     */
    vec_resize_impl::vec_resize_impl(int in_len, int out_len)
      : gr::sync_block("vec_resize",
              gr::io_signature::make(1, 1, in_len*sizeof(float)),
              gr::io_signature::make(1, 1, out_len*sizeof(float)))
    {
      vec_resize_impl::in_len = in_len;
      vec_resize_impl::out_len = out_len;
    }

    /*
     * Our virtual destructor.
     */
    vec_resize_impl::~vec_resize_impl()
    {
    }

    int
    vec_resize_impl::work(int noutput_items,
                          gr_vector_const_void_star &input_items,
                          gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];
      int vec_start_in;
      int vec_start_out;

      for(int i = 0; i < noutput_items; i++) {
        vec_start_in = i*vec_resize_impl::in_len;
        vec_start_out = i*vec_resize_impl::out_len;
        
        // Abbreviate if in_len >= out_len
        if(vec_resize_impl::in_len >= vec_resize_impl::out_len) {
          for(int j = 0; j < vec_resize_impl::out_len; j++) {
            out[vec_start_out + j] = in[vec_start_in + j];
          }
        } 
        // Append 0s if in_len < out_len
        else {
          for(int j = 0; j < vec_resize_impl::in_len; j++) {
            out[vec_start_out + j] = in[vec_start_in + j];
          }
          for(int j = vec_resize_impl::in_len; j < vec_resize_impl::out_len; j++) {
            out[vec_start_out + j] = 0;
          }
        }
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace testblocks */
} /* namespace gr */

