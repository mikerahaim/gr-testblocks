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
#include "testblocks/streams_to_streams_ff.h"
#include "testblocks/interp2.h"
#include "testblocks/decim2.h"
#include "testblocks/interp_var.h"
#include "testblocks/decim_var.h"
#include "testblocks/vec_select.h"
%}


%include "testblocks/vec_shift.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, vec_shift);
%include "testblocks/vec_shift_var.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, vec_shift_var);
%include "testblocks/vec_resize.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, vec_resize);
%include "testblocks/mult_var.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, mult_var);

%include "testblocks/streams_to_streams_ff.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, streams_to_streams_ff);
%include "testblocks/interp2.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, interp2);
%include "testblocks/decim2.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, decim2);
%include "testblocks/interp_var.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, interp_var);
%include "testblocks/decim_var.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, decim_var);
%include "testblocks/vec_select.h"
GR_SWIG_BLOCK_MAGIC2(testblocks, vec_select);
