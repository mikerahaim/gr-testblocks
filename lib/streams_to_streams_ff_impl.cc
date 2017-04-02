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
#include "streams_to_streams_ff_impl.h"

namespace gr {
  namespace testblocks {

    streams_to_streams_ff::sptr
    streams_to_streams_ff::make(int num_streams)
    {
      return gnuradio::get_initial_sptr
        (new streams_to_streams_ff_impl(num_streams));
    }

    /*
     * The private constructor
     */
    streams_to_streams_ff_impl::streams_to_streams_ff_impl(int num_streams)
      : gr::sync_block("streams_to_streams_ff",
              gr::io_signature::make(1, -1, sizeof(float)),
              gr::io_signature::make(1, -1, sizeof(float)))
              //You need to set the MAX input/output streams to -1 so there is no limit on number of streams
    {}
    

    /*
     * Our virtual destructor.
     */
    streams_to_streams_ff_impl::~streams_to_streams_ff_impl()
    {
    }

    int
    streams_to_streams_ff_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float*) input_items[0];
      float **out = (float **) &output_items[0];
      int ninputs = input_items.size(); ///equal to number of input streams
      //this block then maps them to an output stream
      // treat this a useful template for making scaleable blocks
      
      for (int i = 0; i < noutput_items; i++){
      	for (int j = 0; j < ninputs; j++) {
      	// noutput items is the number of samples in the buffer
      	//ninputs is the number of streams
      	//This block will loop through each stream and output that sample
      	*out[j] = ((float *) input_items[j])[i];
      	out[j]++; //calling out[j]++ is safe in most cases
      	
	 }
	}
      	

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace testblocks */
} /* namespace gr */

