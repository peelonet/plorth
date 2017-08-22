/*
 * Copyright (c) 2017, Rauli Laine
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef PLORTH_VALUE_NUMBER_HPP_GUARD
#define PLORTH_VALUE_NUMBER_HPP_GUARD

#include <plorth/value.hpp>

namespace plorth
{
  class number : public value
  {
  public:
    /**
     * Enumeration for different supported number types.
     */
    enum number_type
    {
      number_type_int,
      number_type_real
    };

    /**
     * Returns type of the number.
     */
    virtual enum number_type number_type() const = 0;

    /**
     * Tests whether this number is of specific type.
     */
    inline bool is(enum number_type t) const
    {
      return number_type() == t;
    }

    /**
     * Returns value of the number as integer.
     */
    virtual std::int64_t as_int() const = 0;

    /**
     * Returns value of the number as floating point decimal.
     */
    virtual double as_real() const = 0;

    inline enum type type() const
    {
      return type_number;
    }

    bool equals(const ref<class value>& that) const;
    unistring to_string() const;
    unistring to_source() const;
  };
}

#endif /* !PLORTH_VALUE_NUMBER_HPP_GUARD */