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

#ifndef INCLUDED_TESTBLOCKS_VEC_SELECT_IMPL_H
#define INCLUDED_TESTBLOCKS_VEC_SELECT_IMPL_H

#include <testblocks/vec_select.h>

namespace gr {
  namespace testblocks {

    class vec_select_impl : public vec_select
    {
     private:
      int my_vlen;
      int my_select;

     public:
      vec_select_impl(int vlen, float select);
      ~vec_select_impl();

      void set_select(float select) { my_select = select; }
      float select() { return my_select; }
      
      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace testblocks
} // namespace gr

#endif /* INCLUDED_TESTBLOCKS_VEC_SELECT_IMPL_H */

