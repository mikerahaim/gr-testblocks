#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2016 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import testblocks_swig as testblocks

class qa_mult_var (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        my_mult = 2
        src_data = (1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0)
        expected_result = (10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0)

        src = blocks.vector_source_f(src_data)
#        blk = blocks.multiply_const_vff((my_mult, ))
        blk = testblocks.mult_var(my_mult)
        dst = blocks.vector_sink_f()
        
#        blk.set_k((10,))
        blk.set_mult(10)
#        print "Multiply Value: %f." % blk.k()
        print "Multiply Value: %f." % blk.mult()
        
        self.tb.connect(src, blk)
        self.tb.connect(blk, dst)
        self.tb.run()
        result_data = dst.data()
        
        print "Source: "
        print str(src_data).strip('[]')
        print "Results: "
        print str(result_data).strip('[]')
        self.assertFloatTuplesAlmostEqual(expected_result, result_data, 6)


if __name__ == '__main__':
    gr_unittest.run(qa_mult_var, "qa_mult_var.xml")
