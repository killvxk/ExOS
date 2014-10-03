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

constexpr EFI_GUID EFI_SERIAL_IO_PROTOCOL_GUID = { 0xBB25CF6F, 0xF1D4, 0x11D2,
                                                   0x9A,       0x0C,   0x00,
                                                   0x90,       0x27,   0x3F,
                                                   0xC1,       0xFD };

constexpr UINT32 EFI_SERIAL_IO_PROTOCOL_REVISION = 0x00010000;

enum EFI_PARITY_TYPE
{
    DefaultParity,
    NoParity,
    EvenParity,
    OddParity,
    MarkParity,
    SpaceParity
};

enum EFI_STOP_BITS_TYPE
{
    DefaultStopBits,
    OneStopBit,      // 1 stop bit
    OneFiveStopBits, // 1.5 stop bits
    TwoStopBits      // 2 stop bits
};

struct SERIAL_IO_MODE
{
    UINT32 ControlMask;
    // current Attributes
    UINT32 Timeout;
    UINT64 BaudRate;
    UINT32 ReceiveFifoDepth;
    UINT32 DataBits;
    UINT32 Parity;
    UINT32 StopBits;
};

struct EFI_SERIAL_IO_PROTOCOL;

using EFI_SERIAL_RESET = EFIAPI EFI_STATUS (*)(EFI_SERIAL_IO_PROTOCOL *This);

using EFI_SERIAL_SET_ATTRIBUTES = EFIAPI
EFI_STATUS (*)(EFI_SERIAL_IO_PROTOCOL *This, UINT64 BaudRate,
               UINT32 ReceiveFifoDepth, UINT32 Timeout, EFI_PARITY_TYPE Parity,
               UINT8 DataBits, EFI_STOP_BITS_TYPE StopBits);

using EFI_SERIAL_SET_CONTROL_BITS = EFIAPI
EFI_STATUS (*)(EFI_SERIAL_IO_PROTOCOL *This, UINT32 Control);

constexpr UINT32 EFI_SERIAL_CLEAR_TO_SEND = 0x0010;
constexpr UINT32 EFI_SERIAL_DATA_SET_READY = 0x0020;
constexpr UINT32 EFI_SERIAL_RING_INDICATE = 0x0040;
constexpr UINT32 EFI_SERIAL_CARRIER_DETECT = 0x0080;
constexpr UINT32 EFI_SERIAL_REQUEST_TO_SEND = 0x0002;
constexpr UINT32 EFI_SERIAL_DATA_TERMINAL_READY = 0x0001;
constexpr UINT32 EFI_SERIAL_INPUT_BUFFER_EMPTY = 0x0100;
constexpr UINT32 EFI_SERIAL_OUTPUT_BUFFER_EMPTY = 0x0200;
constexpr UINT32 EFI_SERIAL_HARDWARE_LOOPBACK_ENABLE = 0x1000;
constexpr UINT32 EFI_SERIAL_SOFTWARE_LOOPBACK_ENABLE = 0x2000;
constexpr UINT32 EFI_SERIAL_HARDWARE_FLOW_CONTROL_ENABLE = 0x4000;

using EFI_SERIAL_GET_CONTROL_BITS = EFIAPI
EFI_STATUS (*)(EFI_SERIAL_IO_PROTOCOL *This, UINT32 *Control);

using EFI_SERIAL_WRITE = EFIAPI
EFI_STATUS (*)(EFI_SERIAL_IO_PROTOCOL *This, UINTN *BufferSize, VOID *Buffer);

using EFI_SERIAL_READ = EFIAPI
EFI_STATUS (*)(EFI_SERIAL_IO_PROTOCOL *This, UINTN *BufferSize, VOID *Buffer);

struct EFI_SERIAL_IO_PROTOCOL
{
    UINT32 Revision;
    EFI_SERIAL_RESET Reset;
    EFI_SERIAL_SET_ATTRIBUTES SetAttributes;
    EFI_SERIAL_SET_CONTROL_BITS SetControl;
    EFI_SERIAL_GET_CONTROL_BITS GetControl;
    EFI_SERIAL_WRITE Write;
    EFI_SERIAL_READ Read;
    SERIAL_IO_MODE *Mode;
};
