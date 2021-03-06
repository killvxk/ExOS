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

enum EFI_INTERFACE_TYPE {
    EFI_NATIVE_INTERFACE
};

using EFI_INSTALL_PROTOCOL_INTERFACE = EFIAPI
EFI_STATUS (*)(EFI_HANDLE *Handle, EFI_GUID *Protocol,
               EFI_INTERFACE_TYPE InterfaceType, VOID *Interface);

using EFI_UNINSTALL_PROTOCOL_INTERFACE = EFIAPI
EFI_STATUS (*)(EFI_HANDLE Handle, EFI_GUID *Protocol, VOID *Interface);

using EFI_REINSTALL_PROTOCOL_INTERFACE = EFIAPI
EFI_STATUS (*)(EFI_HANDLE Handle, EFI_GUID *Protocol, VOID *OldInterface,
               VOID *NewInterface);

using EFI_REGISTER_PROTOCOL_NOTIFY = EFIAPI
EFI_STATUS (*)(EFI_GUID *Protocol, EFI_EVENT Event, VOID **Registration);

enum EFI_LOCATE_SEARCH_TYPE {
    AllHandles,
    ByRegisterNotify,
    ByProtocol
};

using EFI_LOCATE_HANDLE = EFIAPI
EFI_STATUS (*)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID *Protocol,
               VOID *SearchKey, UINTN *BufferSize, EFI_HANDLE *Buffer);

using EFI_HANDLE_PROTOCOL = EFIAPI
EFI_STATUS (*)(EFI_HANDLE Handle, EFI_GUID *Protocol, VOID **Interface);

struct EFI_DEVICE_PATH_PROTOCOL;

using EFI_LOCATE_DEVICE_PATH = EFIAPI
EFI_STATUS (*)(EFI_GUID *Protocol, EFI_DEVICE_PATH_PROTOCOL **DevicePath,
               EFI_HANDLE *Device);

using EFI_OPEN_PROTOCOL = EFIAPI
EFI_STATUS (*)(EFI_HANDLE Handle, EFI_GUID *Protocol, VOID **Interface,
               EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle,
               UINT32 Attributes);

constexpr UINT32 EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL = 0x00000001;
constexpr UINT32 EFI_OPEN_PROTOCOL_GET_PROTOCOL = 0x00000002;
constexpr UINT32 EFI_OPEN_PROTOCOL_TEST_PROTOCOL = 0x00000004;
constexpr UINT32 EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER = 0x00000008;
constexpr UINT32 EFI_OPEN_PROTOCOL_BY_DRIVER = 0x00000010;
constexpr UINT32 EFI_OPEN_PROTOCOL_EXCLUSIVE = 0x00000020;

using EFI_CLOSE_PROTOCOL = EFIAPI
EFI_STATUS (*)(EFI_HANDLE Handle, EFI_GUID *Protocol, EFI_HANDLE AgentHandle,
               EFI_HANDLE ControllerHandle);

struct EFI_OPEN_PROTOCOL_INFORMATION_ENTRY {
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attribute;
    UINT32 OpenCount;
};

using EFI_OPEN_PROTOCOL_INFORMATION = EFIAPI
EFI_STATUS (*)(EFI_HANDLE Handle, EFI_GUID *Protocol,
               EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer,
               UINTN *EntryCount);

using EFI_CONNECT_CONTROLLER = EFIAPI
EFI_STATUS (*)(EFI_HANDLE ControllerHandle, EFI_HANDLE *DriverImageHandle,
               EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath,
               BOOLEAN Recursive);

using EFI_DISCONNECT_CONTROLLER = EFIAPI
EFI_STATUS (*)(EFI_HANDLE ControllerHandle, EFI_HANDLE DriverImageHandle,
               EFI_HANDLE ChildHandle);

using EFI_PROTOCOLS_PER_HANDLE = EFIAPI
EFI_STATUS (*)(EFI_HANDLE Handle, EFI_GUID ***ProtocolBuffer,
               UINTN *ProtocolBufferCount);

using EFI_LOCATE_HANDLE_BUFFER = EFIAPI
EFI_STATUS (*)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID *Protocol,
               VOID *SearchKey, UINTN *NoHandles, EFI_HANDLE **Buffer);

using EFI_LOCATE_PROTOCOL = EFIAPI
EFI_STATUS (*)(EFI_GUID *Protocol, VOID *Registration, VOID **Interface);

using EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES = EFIAPI
EFI_STATUS (*)(EFI_HANDLE *Handle, ...);

using EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES = EFIAPI
EFI_STATUS (*)(EFI_HANDLE Handle, ...);
