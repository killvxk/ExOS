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
#include "uefi/protocols/console_support/simple_text_input.h"
#include "uefi/protocols/console_support/simple_text_output.h"
#include "uefi/boot_services/all.h"
#include "uefi/runtime_services/all.h"

constexpr UINT64 EFI_SYSTEM_TABLE_SIGNATURE = 0x5453595320494249;

constexpr UINT32 EFI_2_40_SYSTEM_TABLE_REVISION = ((2 << 16) | (40));
constexpr UINT32 EFI_2_31_SYSTEM_TABLE_REVISION = ((2 << 16) | (31));
constexpr UINT32 EFI_2_30_SYSTEM_TABLE_REVISION = ((2 << 16) | (30));
constexpr UINT32 EFI_2_20_SYSTEM_TABLE_REVISION = ((2 << 16) | (20));
constexpr UINT32 EFI_2_10_SYSTEM_TABLE_REVISION = ((2 << 16) | (10));
constexpr UINT32 EFI_2_00_SYSTEM_TABLE_REVISION = ((2 << 16) | (00));
constexpr UINT32 EFI_1_10_SYSTEM_TABLE_REVISION = ((1 << 16) | (10));
constexpr UINT32 EFI_1_02_SYSTEM_TABLE_REVISION = ((1 << 16) | (02));
constexpr UINT32 EFI_SYSTEM_TABLE_REVISION = EFI_2_40_SYSTEM_TABLE_REVISION;
constexpr UINT32 EFI_SPECIFICATION_VERSION = EFI_SYSTEM_TABLE_REVISION;

struct EFI_TABLE_HEADER {
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
};

constexpr UINT64 EFI_BOOT_SERVICES_SIGNATURE = 0x56524553544f4f42;

constexpr UINT32 EFI_BOOT_SERVICES_REVISION = EFI_SPECIFICATION_VERSION;

struct EFI_BOOT_SERVICES {
    EFI_TABLE_HEADER Hdr;

    EFI_RAISE_TPL RaiseTPL;
    EFI_RESTORE_TPL RestoreTPL;

    EFI_ALLOCATE_PAGES AllocatePages;
    EFI_FREE_PAGES FreePages;
    EFI_GET_MEMORY_MAP GetMemoryMap;
    EFI_ALLOCATE_POOL AllocatePool;
    EFI_FREE_POOL FreePool;

    EFI_CREATE_EVENT CreateEvent;
    EFI_SET_TIMER SetTimer;
    EFI_WAIT_FOR_EVENT WaitForEvent;
    EFI_SIGNAL_EVENT SignalEvent;
    EFI_CLOSE_EVENT CloseEvent;
    EFI_CHECK_EVENT CheckEvent;

    EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL HandleProtocol;
    VOID *Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
    EFI_LOCATE_HANDLE LocateHandle;
    EFI_LOCATE_DEVICE_PATH LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;

    EFI_IMAGE_LOAD LoadImage;
    EFI_IMAGE_START StartImage;
    EFI_EXIT Exit;
    EFI_IMAGE_UNLOAD UnloadImage;
    EFI_EXIT_BOOT_SERVICES ExitBootServices;

    EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
    EFI_STALL Stall;
    EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;

    EFI_CONNECT_CONTROLLER ConnectController;
    EFI_DISCONNECT_CONTROLLER DisconnectController;

    EFI_OPEN_PROTOCOL OpenProtocol;
    EFI_CLOSE_PROTOCOL CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;

    EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES
    UninstallMultipleProtocolInterfaces;

    EFI_CALCULATE_CRC32 CalculateCrc32;

    EFI_COPY_MEM CopyMem;
    EFI_SET_MEM SetMem;
    EFI_CREATE_EVENT_EX CreateEventEx;
};

constexpr UINT64 EFI_RUNTIME_SERVICES_SIGNATURE = 0x56524553544e5552;

constexpr UINT32 EFI_RUNTIME_SERVICES_REVISION = EFI_SPECIFICATION_VERSION;

struct EFI_RUNTIME_SERVICES {
    EFI_TABLE_HEADER Hdr;

    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;

    EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
    EFI_CONVERT_POINTER ConvertPointer;

    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;

    EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;

    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;

    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
};

struct EFI_CONFIGURATION_TABLE {
    EFI_GUID VendorGuid;
    VOID *VendorTable;
};

constexpr EFI_GUID EFI_ACPI_20_TABLE_GUID = {
    0x8868e871, 0xe4f1, 0x11d3, 0xbc, 0x22, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81
};
constexpr EFI_GUID ACPI_TABLE_GUID = {
    0xeb9d2d30, 0x2d88, 0x11d3, 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d
};
constexpr EFI_GUID SAL_SYSTEM_TABLE_GUID = {
    0xeb9d2d32, 0x2d88, 0x11d3, 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d
};
constexpr EFI_GUID SMBIOS_TABLE_GUID = {
    0xeb9d2d31, 0x2d88, 0x11d3, 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d
};
constexpr EFI_GUID MPS_TABLE_GUID = {
    0xeb9d2d2f, 0x2d88, 0x11d3, 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d
};

// ACPI 2.0 or newer tables should use EFI_ACPI_TABLE_GUID

constexpr EFI_GUID EFI_ACPI_TABLE_GUID = {
    0x8868e871, 0xe4f1, 0x11d3, 0xbc, 0x22, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81
};
constexpr EFI_GUID ACPI_10_TABLE_GUID = {
    0xeb9d2d30, 0x2d88, 0x11d3, 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

struct EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER Hdr;
    CHAR16 *FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UINTN NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTable;
};

#pragma clang diagnostic pop
