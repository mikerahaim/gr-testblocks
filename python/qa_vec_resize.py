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

class qa_vec_resize (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        in_len = 5
        out_len = 3
        src_data = (1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0)
        expected_result = (1.0,2.0,3.0,6.0,7.0,8.0)

        src = blocks.vector_source_f(src_data)
        s2v = blocks.stream_to_vector(gr.sizeof_float, in_len)
        blk = testblocks.vec_resize(in_len, out_len)
        v2s = blocks.vector_to_stream(gr.sizeof_float, out_len)
        dst = blocks.vector_sink_f()
        
        self.tb.connect(src, s2v)
        self.tb.connect(s2v, blk)
        self.tb.connect(blk, v2s)
        self.tb.connect(v2s, dst)
        self.tb.run()
        result_data = dst.data()
        print "T1 Source: "
        print str(src_data).strip('[]')
        print "T1 Results: "
        print str(result_data).strip('[]')
        print "***************************************************************"
        self.assertFloatTuplesAlmostEqual(expected_result, result_data, 6)

    def test_002_t (self):
        in_len = 5
        out_len = 8
        src_data = (1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0)
        expected_result = (1.0,2.0,3.0,4.0,5.0,0,0,0,6.0,7.0,8.0,9.0,10.0,0,0,0)

        src = blocks.vector_source_f(src_data)
        s2v = blocks.stream_to_vector(gr.sizeof_float, in_len)
        blk = testblocks.vec_resize(in_len, out_len)
        v2s = blocks.vector_to_stream(gr.sizeof_float, out_len)
        dst = blocks.vector_sink_f()
        
        self.tb.connect(src, s2v)
        self.tb.connect(s2v, blk)
        self.tb.connect(blk, v2s)
        self.tb.connect(v2s, dst)
        self.tb.run()
        result_data = dst.data()
        print "T1 Source: "
        print str(src_data).strip('[]')
        print "T1 Results: "
        print str(result_data).strip('[]')
        print "***************************************************************"
        self.assertFloatTuplesAlmostEqual(expected_result, result_data, 6)
        
if __name__ == '__main__':
    gr_unittest.run(qa_vec_resize, "qa_vec_resize.xml")
