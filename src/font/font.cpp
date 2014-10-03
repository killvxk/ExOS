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

#include "font/font.h"

Font::Glyph Font::get_glyph(char c)
{
    static constexpr Glyph strange_glyph = {
        { { 0b11111110, 0b10000010, 0b10000010, 0b10000010, 0b10000010,
            0b10000010, 0b10000010, 0b10000010, 0b10000010, 0b10000010,
            0b10000010, 0b10000010, 0b10000010, 0b11111110, 0b00000000,
            0b00000000 } }
    };

    static constexpr Glyph font[] =
        {[0 ... 31] = strange_glyph, [' '] = {},
         ['!'] = { { { 0b00000000, 0b00000000, 0b00011000, 0b00111100,
                       0b00111100, 0b00111100, 0b00011000, 0b00011000,
                       0b00011000, 0b00011000, 0b00000000, 0b00011000,
                       0b00011000, 0b00000000, 0b00000000 } } },
         ['"'] = { { { 0b00000000, 0b01100110, 0b01100110, 0b01100110,
                       0b00100100, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000 } } },
         ['#'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b01101100,
                       0b01101100, 0b11111110, 0b01101100, 0b01101100,
                       0b01101100, 0b11111110, 0b01101100, 0b01101100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['$'] = { { { 0b00011000, 0b00011000, 0b01111100, 0b11000110,
                       0b11000010, 0b11000000, 0b01111100, 0b00000110,
                       0b00000110, 0b10000110, 0b11000110, 0b01111100,
                       0b00011000, 0b00011000, 0b00000000, 0b00000000 } } },
         ['%'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b11000010, 0b11000110, 0b00001100, 0b00011000,
                       0b00110000, 0b01100000, 0b11000110, 0b10000110,
                       0b00000000, 0b00000000, 0b00000000 } } },
         ['&'] = { { { 0b00000000, 0b00000000, 0b00111000, 0b01101100,
                       0b01101100, 0b00111000, 0b01110110, 0b11011100,
                       0b11001100, 0b11001100, 0b11001100, 0b01110110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['\''] = { { { 0b00000000, 0b00110000, 0b00110000, 0b00110000,
                        0b00100000, 0b00000000, 0b00000000, 0b00000000,
                        0b00000000, 0b00000000, 0b00000000, 0b00000000,
                        0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['('] = { { { 0b00000000, 0b00000000, 0b00001100, 0b00011000,
                       0b00110000, 0b00110000, 0b00110000, 0b00110000,
                       0b00110000, 0b00110000, 0b00011000, 0b00001100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         [')'] = { { { 0b00000000, 0b00000000, 0b00110000, 0b00011000,
                       0b00001100, 0b00001100, 0b00001100, 0b00001100,
                       0b00001100, 0b00001100, 0b00011000, 0b00110000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['*'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01100110, 0b00111100, 0b11111111,
                       0b00111100, 0b01100110, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['+'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00011000, 0b00011000, 0b01111110,
                       0b00011000, 0b00011000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         [','] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00011000, 0b00011000, 0b00011000,
                       0b00110000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['-'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b11111110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['.'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00011000, 0b00011000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['/'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000010, 0b00000110, 0b00001100, 0b00011000,
                       0b00110000, 0b01100000, 0b11000000, 0b10000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['0'] = { { { 0b00000000, 0b00000000, 0b00111000, 0b01101100,
                       0b11000110, 0b11000110, 0b11010110, 0b11010110,
                       0b11000110, 0b11000110, 0b01101100, 0b00111000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['1'] = { { { 0b00000000, 0b00000000, 0b00011000, 0b00111000,
                       0b01111000, 0b00011000, 0b00011000, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b01111110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['2'] = { { { 0b00000000, 0b00000000, 0b01111100, 0b11000110,
                       0b00000110, 0b00001100, 0b00011000, 0b00110000,
                       0b01100000, 0b11000000, 0b11000110, 0b11111110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['3'] = { { { 0b00000000, 0b00000000, 0b01111100, 0b11000110,
                       0b00000110, 0b00000110, 0b00111100, 0b00000110,
                       0b00000110, 0b00000110, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['4'] = { { { 0b00000000, 0b00000000, 0b00001100, 0b00011100,
                       0b00111100, 0b01101100, 0b11001100, 0b11111110,
                       0b00001100, 0b00001100, 0b00001100, 0b00011110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['5'] = { { { 0b00000000, 0b00000000, 0b11111110, 0b11000000,
                       0b11000000, 0b11000000, 0b11111100, 0b00000110,
                       0b00000110, 0b00000110, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['6'] = { { { 0b00000000, 0b00000000, 0b00111000, 0b01100000,
                       0b11000000, 0b11000000, 0b11111100, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['7'] = { { { 0b00000000, 0b00000000, 0b11111110, 0b11000110,
                       0b00000110, 0b00000110, 0b00001100, 0b00011000,
                       0b00110000, 0b00110000, 0b00110000, 0b00110000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['8'] = { { { 0b00000000, 0b00000000, 0b01111100, 0b11000110,
                       0b11000110, 0b11000110, 0b01111100, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['9'] = { { { 0b00000000, 0b00000000, 0b01111100, 0b11000110,
                       0b11000110, 0b11000110, 0b01111110, 0b00000110,
                       0b00000110, 0b00000110, 0b00001100, 0b01111000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         [':'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00011000, 0b00011000, 0b00000000, 0b00000000,
                       0b00000000, 0b00011000, 0b00011000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         [';'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00011000, 0b00011000, 0b00000000, 0b00000000,
                       0b00000000, 0b00011000, 0b00011000, 0b00110000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['<'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000110,
                       0b00001100, 0b00011000, 0b00110000, 0b01100000,
                       0b00110000, 0b00011000, 0b00001100, 0b00000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['='] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01111110, 0b00000000, 0b00000000,
                       0b01111110, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['>'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b01100000,
                       0b00110000, 0b00011000, 0b00001100, 0b00000110,
                       0b00001100, 0b00011000, 0b00110000, 0b01100000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['?'] = { { { 0b00000000, 0b00000000, 0b01111100, 0b11000110,
                       0b11000110, 0b00001100, 0b00011000, 0b00011000,
                       0b00011000, 0b00000000, 0b00011000, 0b00011000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['@'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b01111100,
                       0b11000110, 0b11000110, 0b11011110, 0b11011110,
                       0b11011110, 0b11011100, 0b11000000, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['A'] = { { { 0b00000000, 0b00000000, 0b00010000, 0b00111000,
                       0b01101100, 0b11000110, 0b11000110, 0b11111110,
                       0b11000110, 0b11000110, 0b11000110, 0b11000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['B'] = { { { 0b00000000, 0b00000000, 0b11111100, 0b01100110,
                       0b01100110, 0b01100110, 0b01111100, 0b01100110,
                       0b01100110, 0b01100110, 0b01100110, 0b11111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['C'] = { { { 0b00000000, 0b00000000, 0b00111100, 0b01100110,
                       0b11000010, 0b11000000, 0b11000000, 0b11000000,
                       0b11000000, 0b11000010, 0b01100110, 0b00111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['D'] = { { { 0b00000000, 0b00000000, 0b11111000, 0b01101100,
                       0b01100110, 0b01100110, 0b01100110, 0b01100110,
                       0b01100110, 0b01100110, 0b01101100, 0b11111000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['E'] = { { { 0b00000000, 0b00000000, 0b11111110, 0b01100110,
                       0b01100010, 0b01101000, 0b01111000, 0b01101000,
                       0b01100000, 0b01100010, 0b01100110, 0b11111110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['F'] = { { { 0b00000000, 0b00000000, 0b11111110, 0b01100110,
                       0b01100010, 0b01101000, 0b01111000, 0b01101000,
                       0b01100000, 0b01100000, 0b01100000, 0b11110000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['G'] = { { { 0b00000000, 0b00000000, 0b00111100, 0b01100110,
                       0b11000010, 0b11000000, 0b11000000, 0b11011110,
                       0b11000110, 0b11000110, 0b01100110, 0b00111010,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['H'] = { { { 0b00000000, 0b00000000, 0b11000110, 0b11000110,
                       0b11000110, 0b11000110, 0b11111110, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b11000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['I'] = { { { 0b00000000, 0b00000000, 0b00111100, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['J'] = { { { 0b00000000, 0b00000000, 0b00011110, 0b00001100,
                       0b00001100, 0b00001100, 0b00001100, 0b00001100,
                       0b11001100, 0b11001100, 0b11001100, 0b01111000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['K'] = { { { 0b00000000, 0b00000000, 0b11100110, 0b01100110,
                       0b01100110, 0b01101100, 0b01111000, 0b01111000,
                       0b01101100, 0b01100110, 0b01100110, 0b11100110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['L'] = { { { 0b00000000, 0b00000000, 0b11110000, 0b01100000,
                       0b01100000, 0b01100000, 0b01100000, 0b01100000,
                       0b01100000, 0b01100010, 0b01100110, 0b11111110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['M'] = { { { 0b00000000, 0b00000000, 0b11000110, 0b11101110,
                       0b11111110, 0b11111110, 0b11010110, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b11000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['N'] = { { { 0b00000000, 0b00000000, 0b11000110, 0b11100110,
                       0b11110110, 0b11111110, 0b11011110, 0b11001110,
                       0b11000110, 0b11000110, 0b11000110, 0b11000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['O'] = { { { 0b00000000, 0b00000000, 0b01111100, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['P'] = { { { 0b00000000, 0b00000000, 0b11111100, 0b01100110,
                       0b01100110, 0b01100110, 0b01111100, 0b01100000,
                       0b01100000, 0b01100000, 0b01100000, 0b11110000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['Q'] = { { { 0b00000000, 0b00000000, 0b01111100, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b11000110,
                       0b11000110, 0b11010110, 0b11011110, 0b01111100,
                       0b00001100, 0b00001110, 0b00000000, 0b00000000 } } },
         ['R'] = { { { 0b00000000, 0b00000000, 0b11111100, 0b01100110,
                       0b01100110, 0b01100110, 0b01111100, 0b01101100,
                       0b01100110, 0b01100110, 0b01100110, 0b11100110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['S'] = { { { 0b00000000, 0b00000000, 0b01111100, 0b11000110,
                       0b11000110, 0b01100000, 0b00111000, 0b00001100,
                       0b00000110, 0b11000110, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['T'] = { { { 0b00000000, 0b00000000, 0b01111110, 0b01111110,
                       0b01011010, 0b00011000, 0b00011000, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['U'] = { { { 0b00000000, 0b00000000, 0b11000110, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['V'] = { { { 0b00000000, 0b00000000, 0b11000110, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b11000110,
                       0b11000110, 0b01101100, 0b00111000, 0b00010000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['W'] = { { { 0b00000000, 0b00000000, 0b11000110, 0b11000110,
                       0b11000110, 0b11000110, 0b11010110, 0b11010110,
                       0b11010110, 0b11111110, 0b11101110, 0b01101100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['X'] = { { { 0b00000000, 0b00000000, 0b11000110, 0b11000110,
                       0b01101100, 0b01111100, 0b00111000, 0b00111000,
                       0b01111100, 0b01101100, 0b11000110, 0b11000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['Y'] = { { { 0b00000000, 0b00000000, 0b01100110, 0b01100110,
                       0b01100110, 0b01100110, 0b00111100, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['Z'] = { { { 0b00000000, 0b00000000, 0b11111110, 0b11000110,
                       0b10000110, 0b00001100, 0b00011000, 0b00110000,
                       0b01100000, 0b11000010, 0b11000110, 0b11111110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['['] = { { { 0b00000000, 0b00000000, 0b00111100, 0b00110000,
                       0b00110000, 0b00110000, 0b00110000, 0b00110000,
                       0b00110000, 0b00110000, 0b00110000, 0b00111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['\\'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b10000000,
                        0b11000000, 0b11100000, 0b01111000, 0b00111000,
                        0b00011100, 0b00001110, 0b00000110, 0b00000010,
                        0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         [']'] = { { { 0b00000000, 0b00000000, 0b00111100, 0b00001100,
                       0b00001100, 0b00001100, 0b00001100, 0b00001100,
                       0b00001100, 0b00001100, 0b00001100, 0b00111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['^'] = { { { 0b00010000, 0b00111000, 0b01101100, 0b11000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['_'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11111111, 0b00000000, 0b00000000 } } },
         ['`'] = { { { 0b00110000, 0b00110000, 0b00011000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['a'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01111000, 0b00001100, 0b01111100,
                       0b11001100, 0b11001100, 0b11001100, 0b01110110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['b'] = { { { 0b00000000, 0b00000000, 0b11100000, 0b01100000,
                       0b01100000, 0b01111000, 0b01101100, 0b01100110,
                       0b01100110, 0b01100110, 0b01100110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['c'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01111100, 0b11000110, 0b11000000,
                       0b11000000, 0b11000000, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['d'] = { { { 0b00000000, 0b00000000, 0b00011100, 0b00001100,
                       0b00001100, 0b00111100, 0b01101100, 0b11001100,
                       0b11001100, 0b11001100, 0b11001100, 0b01110110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['e'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01111100, 0b11000110, 0b11111110,
                       0b11000000, 0b11000000, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['f'] = { { { 0b00000000, 0b00000000, 0b00111000, 0b01101100,
                       0b01100100, 0b01100000, 0b11110000, 0b01100000,
                       0b01100000, 0b01100000, 0b01100000, 0b11110000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['g'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01110110, 0b11001100, 0b11001100,
                       0b11001100, 0b11001100, 0b11001100, 0b01111100,
                       0b00001100, 0b11001100, 0b01111000, 0b00000000 } } },
         ['h'] = { { { 0b00000000, 0b00000000, 0b11100000, 0b01100000,
                       0b01100000, 0b01101100, 0b01110110, 0b01100110,
                       0b01100110, 0b01100110, 0b01100110, 0b11100110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['i'] = { { { 0b00000000, 0b00000000, 0b00011000, 0b00011000,
                       0b00000000, 0b00111000, 0b00011000, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['j'] = { { { 0b00000000, 0b00000000, 0b00000110, 0b00000110,
                       0b00000000, 0b00001110, 0b00000110, 0b00000110,
                       0b00000110, 0b00000110, 0b00000110, 0b00000110,
                       0b01100110, 0b01100110, 0b00111100, 0b00000000 } } },
         ['k'] = { { { 0b00000000, 0b00000000, 0b11100000, 0b01100000,
                       0b01100000, 0b01100110, 0b01101100, 0b01111000,
                       0b01111000, 0b01101100, 0b01100110, 0b11100110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['l'] = { { { 0b00000000, 0b00000000, 0b00111000, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['m'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11101100, 0b11111110, 0b11010110,
                       0b11010110, 0b11010110, 0b11010110, 0b11000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['n'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11011100, 0b01100110, 0b01100110,
                       0b01100110, 0b01100110, 0b01100110, 0b01100110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['o'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01111100, 0b11000110, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['p'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11011100, 0b01100110, 0b01100110,
                       0b01100110, 0b01100110, 0b01100110, 0b01111100,
                       0b01100000, 0b01100000, 0b11110000, 0b00000000 } } },
         ['q'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01110110, 0b11001100, 0b11001100,
                       0b11001100, 0b11001100, 0b11001100, 0b01111100,
                       0b00001100, 0b00001100, 0b00011110, 0b00000000 } } },
         ['r'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11011100, 0b01110110, 0b01100110,
                       0b01100000, 0b01100000, 0b01100000, 0b11110000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['s'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01111100, 0b11000110, 0b01100000,
                       0b00111000, 0b00001100, 0b11000110, 0b01111100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['t'] = { { { 0b00000000, 0b00000000, 0b00010000, 0b00110000,
                       0b00110000, 0b11111100, 0b00110000, 0b00110000,
                       0b00110000, 0b00110000, 0b00110110, 0b00011100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['u'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11001100, 0b11001100, 0b11001100,
                       0b11001100, 0b11001100, 0b11001100, 0b01110110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['v'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b01100110, 0b01100110, 0b01100110,
                       0b01100110, 0b01100110, 0b00111100, 0b00011000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['w'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11000110, 0b11000110, 0b11010110,
                       0b11010110, 0b11010110, 0b11111110, 0b01101100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['x'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11000110, 0b01101100, 0b00111000,
                       0b00111000, 0b00111000, 0b01101100, 0b11000110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['y'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11000110, 0b11000110, 0b11000110,
                       0b11000110, 0b11000110, 0b11000110, 0b01111110,
                       0b00000110, 0b00001100, 0b11111000, 0b00000000 } } },
         ['z'] = { { { 0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b11111110, 0b11001100, 0b00011000,
                       0b00110000, 0b01100000, 0b11000110, 0b11111110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['{'] = { { { 0b00000000, 0b00000000, 0b00001110, 0b00011000,
                       0b00011000, 0b00011000, 0b01110000, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00001110,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['|'] = { { { 0b00000000, 0b00000000, 0b00011000, 0b00011000,
                       0b00011000, 0b00011000, 0b00000000, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b00011000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['}'] = { { { 0b00000000, 0b00000000, 0b01110000, 0b00011000,
                       0b00011000, 0b00011000, 0b00001110, 0b00011000,
                       0b00011000, 0b00011000, 0b00011000, 0b01110000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         ['~'] = { { { 0b00000000, 0b00000000, 0b01110110, 0b11011100,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000,
                       0b00000000, 0b00000000, 0b00000000, 0b00000000 } } },
         [127] = strange_glyph };

    return font[static_cast<unsigned char>(c)];
}
