/* -*- c++ -*- */
/*
 * Copyright 2022 No.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_MY_MODULE_MYCLIPPER_IMPL_H
#define INCLUDED_MY_MODULE_MYCLIPPER_IMPL_H

#include <gnuradio/my_module/myclipper.h>

namespace gr {
  namespace my_module {

    class myclipper_impl : public myclipper
    {
     private:
        float d_clip; //its a good coding practice to name this in a way that you can
                      //differentiate private from public variables
                      // gnuradio's name convention for private variables is d_myvar, cpp uses m_myvar

     public:
      myclipper_impl(float clipper);
      ~myclipper_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace my_module
} // namespace gr

#endif /* INCLUDED_MY_MODULE_MYCLIPPER_IMPL_H */
