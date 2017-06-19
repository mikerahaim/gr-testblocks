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
#include "interp2_impl.h"

namespace gr {
  namespace testblocks {

    interp2::sptr
    interp2::make()
    {
      return gnuradio::get_initial_sptr
        (new interp2_impl());
    }

    /*
     * The private constructor
     */
    interp2_impl::interp2_impl()
      : gr::sync_interpolator("interp2",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)), 2)
    {}

    /*
     * Our virtual destructor.
     */
    interp2_impl::~interp2_impl()
    {
    }

    int
    interp2_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

      int i = 0;
      int j = 0;
      int ctr = 0;
      
      while(i < noutput_items) {
		  out[i++] = in[j];
		  ctr++;
		  if (ctr >= 2) {
			  ctr = 0;
			  j++;
		  }
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace testblocks */
} /* namespace gr */

