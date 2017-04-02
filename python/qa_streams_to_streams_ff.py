#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2017 <+YOU OR YOUR COMPANY+>.
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

class qa_streams_to_streams_ff (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        #This tests 1 stream, to make sure it outputs the same input from before
        src_data=(1.0,2.0,3.0,4.0,5.0)
        expected_results=(1.0,2.0,3.0,4.0,5.0)
        src = blocks.vector_source_f(src_data)
        blk = testblocks.streams_to_streams_ff()
        dst = blocks.vector_sink_f()
        
        self.tb.connect(src, blk)
        self.tb.connect(blk, dst)
        self.tb.run()
        result_data = dst.data()
        # check data
        print result_data
        self.assertFloatTuplesAlmostEqual(expected_results, result_data, 6)
        
    def test_002_t (self):
        #This tests multiple streams, to make sure it outputs the same input from before
        src_data0=(1.0,2.0,3.0)
        src_data1=(4.0,5.0,6.0)
        src_data2=(7.0,8.0,9.0)
        expected_result0=(1.0,2.0,3.0)
        src0 = blocks.vector_source_f(src_data0)
        src1 = blocks.vector_source_f(src_data1)
        src2 = blocks.vector_source_f(src_data2)
        blk = testblocks.streams_to_streams_ff()
        dst0 = blocks.vector_sink_f()
        dst1 = blocks.vector_sink_f()
        dst2 = blocks.vector_sink_f()

        self.tb.connect(src0, (blk,0) )
        self.tb.connect(src1, (blk,1) )
        self.tb.connect(src2, (blk,2) )                
        self.tb.connect((blk,0), dst0)
        self.tb.connect((blk,1), dst1)
        self.tb.connect((blk,2), dst2)
        
        self.tb.run()
        result_data0 = dst0.data()
        result_data1 = dst1.data()
        result_data2 = dst2.data()
        # check data
        print result_data0
        self.assertFloatTuplesAlmostEqual(expected_result0, result_data0, 6)
 
    

if __name__ == '__main__':
    gr_unittest.run(qa_streams_to_streams_ff, "qa_streams_to_streams_ff.xml")
