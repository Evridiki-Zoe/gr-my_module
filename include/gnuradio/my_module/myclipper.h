/* -*- c++ -*- */
/*
 * Copyright 2022 No.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_MY_MODULE_MYCLIPPER_H
#define INCLUDED_MY_MODULE_MYCLIPPER_H

#include <gnuradio/my_module/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace my_module {

    /*!
     * \brief <+description of block+>
     * \ingroup my_module
     *
     */
    class MY_MODULE_API myclipper : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<myclipper> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of my_module::myclipper.
       *
       * To avoid accidental use of raw pointers, my_module::myclipper's
       * constructor is in a private implementation
       * class. my_module::myclipper::make is the public interface for
       * creating new instances.
       */
      static sptr make(float clipper = 1.0f);
    };

  } // namespace my_module
} // namespace gr

#endif /* INCLUDED_MY_MODULE_MYCLIPPER_H */
