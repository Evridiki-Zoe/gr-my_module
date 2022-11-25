/* -*- c++ -*- */
/*
 * Copyright 2022 No.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "myclipper_impl.h"

namespace gr {
  namespace my_module {

    using input_type = float;
    using output_type = float;
    myclipper::sptr
    myclipper::make(float clipper)
    {
      return gnuradio::make_block_sptr<myclipper_impl>(
        clipper);
    }


    /*
     * The private constructor
     */
    myclipper_impl::myclipper_impl(float clipper)
      : gr::sync_block("myclipper",
              /* The block has exactly one float input */
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              /* The block has exactly one float output */
              gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
              /* Initialize private members */
                    d_clip(clipper)
    {
        if(d_clip < 0.0f){
                throw std::invalid_argument("clipper should be positive!");
        }

    }

    /*
     * Our virtual destructor.
     */
    myclipper_impl::~myclipper_impl()
    {
    }

    int
    myclipper_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const input_type*)(input_items[0]);
      float *out = (output_type*)(output_items[0]);

      // Do <+signal processing+>
      for(int i = 0; i < noutput_items; i++){
        if(in[i] > d_clip)
          out[i] = d_clip;
        else if(in[i] < -d_clip)
          out[i] = -d_clip;
        else
          out[i] = in[i];
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace my_module */
} /* namespace gr */
