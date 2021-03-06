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

constexpr EFI_GUID EFI_COMPONENT_NAME2_PROTOCOL_GUID = {
    0x6a7a5cff, 0xe8d9, 0x4f70, 0xba, 0xda, 0x75, 0xab, 0x30, 0x25, 0xce, 0x14
};

struct EFI_COMPONENT_NAME2_PROTOCOL;

using EFI_COMPONENT_NAME_GET_DRIVER_NAME = EFIAPI
EFI_STATUS (*)(EFI_COMPONENT_NAME2_PROTOCOL *This, CHAR8 *Language,
               CHAR16 **DriverName);

using EFI_COMPONENT_NAME_GET_CONTROLLER_NAME = EFIAPI
EFI_STATUS (*)(EFI_COMPONENT_NAME2_PROTOCOL *This, EFI_HANDLE ControllerHandle,
               EFI_HANDLE ChildHandle, CHAR8 *Language,
               CHAR16 **ControllerName);

struct EFI_COMPONENT_NAME2_PROTOCOL {
    EFI_COMPONENT_NAME_GET_DRIVER_NAME GetDriverName;
    EFI_COMPONENT_NAME_GET_CONTROLLER_NAME GetControllerName;
    CHAR8 *SupportedLanguages;
};
