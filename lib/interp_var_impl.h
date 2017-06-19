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

#ifndef INCLUDED_TESTBLOCKS_INTERP_VAR_IMPL_H
#define INCLUDED_TESTBLOCKS_INTERP_VAR_IMPL_H

#include <testblocks/interp_var.h>

namespace gr {
  namespace testblocks {

    class interp_var_impl : public interp_var
    {
     private:
      float my_interpolation;

     public:
      interp_var_impl(float interpolation);
      ~interp_var_impl();

      void d_interpolation(float interpolation) { my_interpolation = interpolation; }
      float interpolation() { return my_interpolation; }

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace testblocks
} // namespace gr

#endif /* INCLUDED_TESTBLOCKS_INTERP_VAR_IMPL_H */

