/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
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
#include "vec_select_impl.h"

namespace gr {
  namespace testblocks {

    vec_select::sptr
    vec_select::make(int vlen, float select)
    {
      return gnuradio::get_initial_sptr
        (new vec_select_impl(vlen, select));
    }

    /*
     * The private constructor
     */
    vec_select_impl::vec_select_impl(int vlen, float select)
      : gr::sync_block("vec_select",
              gr::io_signature::make(1, 1, vlen*sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
    {
      vec_select_impl::my_vlen = vlen;
      vec_select_impl::my_select = select;
      while (vec_select_impl::my_select > vlen)
      {
        vec_select_impl::my_select-=vlen;
      }
    }

    /*
     * Our virtual destructor.
     */
    vec_select_impl::~vec_select_impl()
    {
    }

    int
    vec_select_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];
      int vec_start;
      
      for(int i = 0; i < noutput_items; i++) {
        out[i] = in[i*vec_select_impl::my_vlen + vec_select_impl::my_select - 1];
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace testblocks */
} /* namespace gr */

