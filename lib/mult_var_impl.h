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

#ifndef INCLUDED_TESTBLOCKS_MULT_VAR_IMPL_H
#define INCLUDED_TESTBLOCKS_MULT_VAR_IMPL_H

#include <testblocks/mult_var.h>

namespace gr {
  namespace testblocks {

    class mult_var_impl : public mult_var
    {
     private:
      float d_mult;

     public:
      mult_var_impl(float mult);
      ~mult_var_impl();
      
      void set_mult(float mult) { d_mult = mult; }
      float mult() { return d_mult; }
      
      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace testblocks
} // namespace gr

#endif /* INCLUDED_TESTBLOCKS_MULT_VAR_IMPL_H */

