/*
 * Copyright (c) 2014, Thorben Hasenpusch <t.hasenpusch@icloud.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#include <cstddef>
#include <cstdint>

#include "lib/immut_array_ref.h"
#include "lib/mut_array_ref.h"
#include "lib/array.h"
#include "lib/value_or_error.h"
#include "lib/ctstring.h"

// printf() and snprintf()-like functions featuring format string checking
// at compile time. They either return the number of characters written or
// an error.

enum class Case : std::uint8_t {
    LOWER,
    UPPER
};

struct ConvFlags {
    Case letter_case;
    std::uint8_t base;
};

ValueOrError<std::size_t> to_string(MutStringRef &buf, ConvFlags flags, StringRef arg);
ValueOrError<std::size_t> to_string(MutStringRef &buf, ConvFlags flags, const void *arg);
ValueOrError<std::size_t> to_string(MutStringRef &buf, ConvFlags flags, int arg);
ValueOrError<std::size_t> to_string(MutStringRef &buf, ConvFlags flags, unsigned int arg);
ValueOrError<std::size_t> to_string(MutStringRef &buf, ConvFlags flags, long arg);
ValueOrError<std::size_t> to_string(MutStringRef &buf, ConvFlags flags, unsigned long arg);
ValueOrError<std::size_t> to_string(MutStringRef &buf, ConvFlags flags, long long arg);
ValueOrError<std::size_t> to_string(MutStringRef &buf, ConvFlags flags, unsigned long long arg);

ValueOrError<std::size_t> format(MutStringRef &buf, StringRef fmt);

template <class Arg, class ...Args>
constexpr ValueOrError<std::size_t> format(MutStringRef &buf, StringRef fmt, Arg arg, Args ...args)
{
    std::size_t cnt = 0;

    for (std::size_t i = 0; i < fmt.length(); ++i) {
        if (fmt[i] != '(') {
            ++cnt;

            if (buf.is_space_left())
                buf.push_back(fmt[i]);

            continue;
        }

        if (fmt[i + 1] == '(') {
            ++cnt;
            ++i;

            if (buf.is_space_left())
                buf.push_back('(');

            continue;
        }

        ++i;

        ConvFlags flags {
            .base = 10,
            .letter_case = Case::LOWER
        };

        for (; fmt[i] != ')'; ++i) {
            switch (fmt[i]) {
            case 'x':
                flags.base = 16;
                flags.letter_case = Case::LOWER;
                break;
            case 'X':
                flags.base = 16;
                flags.letter_case = Case::UPPER;
                break;
            case 'o':
                flags.base = 8;
                flags.letter_case = Case::LOWER;
                break;
            case 'O':
                flags.base = 8;
                flags.letter_case = Case::UPPER;
                break;
            }
        }

        ++i;

        ValueOrError<std::size_t> result = to_string(buf, flags, arg);
        if (result.is_error())
            return result.error();

        cnt += result.value();

        result = format(buf, fmt.slice_from(i), args...);
        if (result.is_error())
            return result.error();
        
        cnt += result.value();
        
        return cnt;
    }
    
    return cnt;
}

constexpr bool is_valid(StringRef fmt)
{
    for (std::size_t i = 0; i < fmt.length(); ++i)
        if (fmt[i] == '(' && (i+1 == fmt.length() || fmt[i++ + 1] != '('))
            return false;

    return true;
}

constexpr bool flags_valid(StringRef fmt, const StringRef &)
{
    if (fmt.length() > 0)
        return false;

    return true;
}

constexpr bool flags_valid(StringRef fmt, const void *const &)
{
    for (const char c : fmt)
        if (c != 'x' && c != 'X')
            return false;
    return true;
}

constexpr bool flags_valid(StringRef fmt, const int &)
{
    for (const char c : fmt)
        if (c != 'x' && c != 'X' && c != 'o' && c != 'O')
            return false;
    return true;
}

constexpr bool flags_valid(StringRef fmt, const unsigned int &)
{
    for (const char c : fmt)
        if (c != 'x' && c != 'X' && c != 'o' && c != 'O')
            return false;
    return true;
}

constexpr bool flags_valid(StringRef fmt, const long &)
{
    for (const char c : fmt)
        if (c != 'x' && c != 'X' && c != 'o' && c != 'O')
            return false;
    return true;
}

constexpr bool flags_valid(StringRef fmt, const unsigned long &)
{
    for (const char c : fmt)
        if (c != 'x' && c != 'X' && c != 'o' && c != 'O')
            return false;
    return true;
}

constexpr bool flags_valid(StringRef fmt, const long long &)
{
    for (const char c : fmt)
        if (c != 'x' && c != 'X' && c != 'o' && c != 'O')
            return false;
    return true;
}

constexpr bool flags_valid(StringRef fmt, const unsigned long long &)
{
    for (const char c : fmt)
        if (c != 'x' && c != 'X' && c != 'o' && c != 'O')
            return false;
    return true;
}

template <class Arg, class ...Args>
constexpr bool is_valid(StringRef fmt, const Arg &arg, const Args &...args)
{
    for (std::size_t i = 0; i < fmt.length(); ++i) {
        if (fmt[i] != '(')
            continue;

        if (i+1 != fmt.length() && fmt[i+1] == '(') {
            ++i;
            continue;
        }

        ++i;

        std::size_t begin_flags = i;

        bool found = false;
        for (; i < fmt.length(); ++i) {
            if (fmt[i] == ')') {
                found = true;
                break;
            }
        }
        if (!found)
            return false;

        std::size_t end_flags = i;

        if (!flags_valid(fmt.slice_from_until(begin_flags, end_flags), arg))
            return false;

        ++i;

        return is_valid(fmt.slice_from(i), args...);
    }

    return true;
}

template <char ...Fmt, class ...Args>
constexpr ValueOrError<std::size_t> snprintf(MutStringRef &buf, CTString<Fmt...>, Args ...args)
{
    constexpr String<sizeof...(Fmt)> fmt = { { Fmt... } };

    static_assert(is_valid(fmt.ref(), args...), "Invalid format string!");

    return format(buf, fmt.ref(), args...);
}

static Error (*print_func)(StringRef s);

template <char ...Fmt, class ...Args>
constexpr ValueOrError<std::size_t> printf(CTString<Fmt...> fmt, Args ...args)
{
    String<2048> buf;
    MutStringRef mut_ref = buf.mut_ref();

    ValueOrError<std::size_t> result = snprintf(mut_ref, fmt, args...);
    if (result.is_error())
        return result.error();

    Error err = print_func(mut_ref.to_immut_ref());
    if (err != Error::SUCCESS)
        return err;

    return result.value();
}