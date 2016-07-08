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


#ifndef INCLUDED_TESTBLOCKS_VEC_SHIFT_VAR_H
#define INCLUDED_TESTBLOCKS_VEC_SHIFT_VAR_H

#include <testblocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace testblocks {

    /*!
     * \brief <+description of block+>
     * \ingroup testblocks
     *
     */
    class TESTBLOCKS_API vec_shift_var : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<vec_shift_var> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of testblocks::vec_shift_var.
       *
       * To avoid accidental use of raw pointers, testblocks::vec_shift_var's
       * constructor is in a private implementation
       * class. testblocks::vec_shift_var::make is the public interface for
       * creating new instances.
       */
      static sptr make(int vec_len, int shift);
    };

  } // namespace testblocks
} // namespace gr

#endif /* INCLUDED_TESTBLOCKS_VEC_SHIFT_VAR_H */

