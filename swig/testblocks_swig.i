/* -*- c++ -*- */

#define TESTBLOCKS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "testblocks_swig_doc.i"

%{
#include "testblocks/vec_shift.h"
#include "testblocks/vec_shift_var.h"
#include "testblocks/vec_resize.h"
#include "testblocks/mult_var.h"
%}


%include "testblocks/vec_shift.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, vec_shift);
%include "testblocks/vec_shift_var.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, vec_shift_var);
%include "testblocks/vec_resize.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, vec_resize);
%include "testblocks/mult_var.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, mult_var);
