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

#include "uefi/types.h"

constexpr EFI_GUID EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID = {
    0x387477c2, 0x69c7, 0x11d2, 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

struct SIMPLE_TEXT_OUTPUT_MODE {
    INT32 MaxMode;
    // current settings
    INT32 Mode;
    INT32 Attribute;
    INT32 CursorColumn;
    INT32 CursorRow;
    BOOLEAN CursorVisible;
};

#pragma clang diagnostic pop

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

using EFI_TEXT_RESET = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
               BOOLEAN ExtendedVerification);

using EFI_TEXT_STRING = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);

constexpr CHAR16 BOXDRAW_HORIZONTAL = 0x250;
constexpr CHAR16 BOXDRAW_VERTICAL = 0x2502;
constexpr CHAR16 BOXDRAW_DOWN_RIGHT = 0x250c;
constexpr CHAR16 BOXDRAW_DOWN_LEFT = 0x2510;
constexpr CHAR16 BOXDRAW_UP_RIGHT = 0x2514;
constexpr CHAR16 BOXDRAW_UP_LEFT = 0x2518;
constexpr CHAR16 BOXDRAW_VERTICAL_RIGHT = 0x251c;
constexpr CHAR16 BOXDRAW_VERTICAL_LEFT = 0x2524;
constexpr CHAR16 BOXDRAW_DOWN_HORIZONTAL = 0x252c;
constexpr CHAR16 BOXDRAW_UP_HORIZONTAL = 0x2534;
constexpr CHAR16 BOXDRAW_VERTICAL_HORIZONTAL = 0x253c;

constexpr CHAR16 BOXDRAW_DOUBLE_HORIZONTAL = 0x2550;
constexpr CHAR16 BOXDRAW_DOUBLE_VERTICAL = 0x2551;
constexpr CHAR16 BOXDRAW_DOWN_RIGHT_DOUBLE = 0x2552;
constexpr CHAR16 BOXDRAW_DOWN_DOUBLE_RIGHT = 0x2553;
constexpr CHAR16 BOXDRAW_DOUBLE_DOWN_RIGHT = 0x2554;
constexpr CHAR16 BOXDRAW_DOWN_LEFT_DOUBLE = 0x2555;
constexpr CHAR16 BOXDRAW_DOWN_DOUBLE_LEFT = 0x2556;
constexpr CHAR16 BOXDRAW_DOUBLE_DOWN_LEFT = 0x2557;

constexpr CHAR16 BOXDRAW_UP_RIGHT_DOUBLE = 0x2558;
constexpr CHAR16 BOXDRAW_UP_DOUBLE_RIGHT = 0x2559;
constexpr CHAR16 BOXDRAW_DOUBLE_UP_RIGHT = 0x255a;

constexpr CHAR16 BOXDRAW_UP_LEFT_DOUBLE = 0x255b;
constexpr CHAR16 BOXDRAW_UP_DOUBLE_LEFT = 0x255c;
constexpr CHAR16 BOXDRAW_DOUBLE_UP_LEFT = 0x255d;

constexpr CHAR16 BOXDRAW_VERTICAL_RIGHT_DOUBLE = 0x255e;
constexpr CHAR16 BOXDRAW_VERTICAL_DOUBLE_RIGHT = 0x255f;
constexpr CHAR16 BOXDRAW_DOUBLE_VERTICAL_RIGHT = 0x2560;

constexpr CHAR16 BOXDRAW_VERTICAL_LEFT_DOUBLE = 0x2561;
constexpr CHAR16 BOXDRAW_VERTICAL_DOUBLE_LEFT = 0x2562;
constexpr CHAR16 BOXDRAW_DOUBLE_VERTICAL_LEFT = 0x2563;

constexpr CHAR16 BOXDRAW_DOWN_HORIZONTAL_DOUBLE = 0x2564;
constexpr CHAR16 BOXDRAW_DOWN_DOUBLE_HORIZONTAL = 0x2565;
constexpr CHAR16 BOXDRAW_DOUBLE_DOWN_HORIZONTAL = 0x2566;

constexpr CHAR16 BOXDRAW_UP_HORIZONTAL_DOUBLE = 0x2567;
constexpr CHAR16 BOXDRAW_UP_DOUBLE_HORIZONTAL = 0x2568;
constexpr CHAR16 BOXDRAW_DOUBLE_UP_HORIZONTAL = 0x2569;

constexpr CHAR16 BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE = 0x256a;
constexpr CHAR16 BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL = 0x256b;
constexpr CHAR16 BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL = 0x256c;

constexpr CHAR16 BLOCKELEMENT_FULL_BLOCK = 0x2588;
constexpr CHAR16 BLOCKELEMENT_LIGHT_SHADE = 0x2591;

constexpr CHAR16 GEOMETRICSHAPE_UP_TRIANGLE = 0x25b2;
constexpr CHAR16 GEOMETRICSHAPE_RIGHT_TRIANGLE = 0x25ba;
constexpr CHAR16 GEOMETRICSHAPE_DOWN_TRIANGLE = 0x25bc;
constexpr CHAR16 GEOMETRICSHAPE_LEFT_TRIANGLE = 0x25c4;

constexpr CHAR16 ARROW_UP = 0x2191;
constexpr CHAR16 ARROW_DOWN = 0x2193;

using EFI_TEXT_TEST_STRING = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);

using EFI_TEXT_QUERY_MODE = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UINTN ModeNumber,
               UINTN *Column, UINTN *Rows);

using EFI_TEXT_SET_MODE = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UINTN ModeNumber);

using EFI_TEXT_SET_ATTRIBUTE = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UINTN Attribute);

constexpr UINTN EFI_BLACK = 0x00;
constexpr UINTN EFI_BLUE = 0x01;
constexpr UINTN EFI_GREEN = 0x02;
constexpr UINTN EFI_CYAN = 0x03;
constexpr UINTN EFI_RED = 0x04;
constexpr UINTN EFI_MAGENTA = 0x05;
constexpr UINTN EFI_BROWN = 0x06;
constexpr UINTN EFI_LIGHTGRAY = 0x07;
constexpr UINTN EFI_BRIGHT = 0x08;
constexpr UINTN EFI_DARKGRAY = 0x08;
constexpr UINTN EFI_LIGHTBLUE = 0x09;
constexpr UINTN EFI_LIGHTGREEN = 0x0A;
constexpr UINTN EFI_LIGHTCYAN = 0x0B;
constexpr UINTN EFI_LIGHTRED = 0x0C;
constexpr UINTN EFI_LIGHTMAGENTA = 0x0D;
constexpr UINTN EFI_YELLOW = 0x0E;
constexpr UINTN EFI_WHITE = 0x0F;
constexpr UINTN EFI_BACKGROUND_BLACK = 0x00;
constexpr UINTN EFI_BACKGROUND_BLUE = 0x10;
constexpr UINTN EFI_BACKGROUND_GREEN = 0x20;
constexpr UINTN EFI_BACKGROUND_CYAN = 0x30;
constexpr UINTN EFI_BACKGROUND_RED = 0x40;
constexpr UINTN EFI_BACKGROUND_MAGENTA = 0x50;
constexpr UINTN EFI_BACKGROUND_BROWN = 0x60;
constexpr UINTN EFI_BACKGROUND_LIGHTGRAY = 0x70;
constexpr UINTN EFI_TEXT_ATTR(UINTN foreground, UINTN background)
{
    return foreground | (background << 4);
}

using EFI_TEXT_CLEAR_SCREEN = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);

using EFI_TEXT_SET_CURSOR_POSITION = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, UINTN Column, UINTN Row);

using EFI_TEXT_ENABLE_CURSOR = EFIAPI
EFI_STATUS (*)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, BOOLEAN Visible);

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_TEXT_RESET Reset;
    EFI_TEXT_STRING OutputString;
    EFI_TEXT_TEST_STRING TestString;
    EFI_TEXT_QUERY_MODE QueryMode;
    EFI_TEXT_SET_MODE SetMode;
    EFI_TEXT_SET_ATTRIBUTE SetAttribute;
    EFI_TEXT_CLEAR_SCREEN ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE *Mode;
};
