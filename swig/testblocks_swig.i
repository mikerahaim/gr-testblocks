/* -*- c++ -*- */

#define TESTBLOCKS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "testblocks_swig_doc.i"

%{
#include "testblocks/vec_shift.h"
%}


%include "testblocks/vec_shift.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, vec_shift);
