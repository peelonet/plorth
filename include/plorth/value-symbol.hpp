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
#ifndef PLORTH_VALUE_SYMBOL_HPP_GUARD
#define PLORTH_VALUE_SYMBOL_HPP_GUARD

#include <plorth/value.hpp>

namespace plorth
{
  /**
   * Symbol represents identifier in Plorth source code.
   */
  class symbol : public value
  {
  public:
    /**
     * Constructs new symbol.
     *
     * \param id       String which acts as identifier for the symbol.
     * \param position Optional position in source code where the symbol was
     *                 encountered.
     */
    explicit symbol(const unistring& id,
                    const struct position* position = nullptr);

    /**
     * Destructor.
     */
    ~symbol();

    /**
     * Returns string which acts as identifier for the symbol.
     */
    inline const unistring& id() const
    {
      return m_id;
    }

    /**
     * Returns position of the symbol in source code, or null pointer if no
     * such information is available.
     */
    inline const struct position* position() const
    {
      return m_position;
    }

    inline enum type type() const
    {
      return type_symbol;
    }

    bool equals(const ref<value>& that) const;
    bool exec(const ref<context>& ctx);
    bool eval(const ref<context>& ctx, ref<value>& slot);
    unistring to_string() const;
    unistring to_source() const;

  private:
    /** Identifier of the symbol. */
    const unistring m_id;
    /** Position of the symbol in source code. */
    struct position* m_position;
  };
}

#endif /* !PLORTH_VALUE_SYMBOL_HPP_GUARD */