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


#ifndef INCLUDED_TESTBLOCKS_DECIM2_H
#define INCLUDED_TESTBLOCKS_DECIM2_H

#include <testblocks/api.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
  namespace testblocks {

    /*!
     * \brief <+description of block+>
     * \ingroup testblocks
     *
     */
    class TESTBLOCKS_API decim2 : virtual public gr::sync_decimator
    {
     public:
      typedef boost::shared_ptr<decim2> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of testblocks::decim2.
       *
       * To avoid accidental use of raw pointers, testblocks::decim2's
       * constructor is in a private implementation
       * class. testblocks::decim2::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace testblocks
} // namespace gr

#endif /* INCLUDED_TESTBLOCKS_DECIM2_H */

