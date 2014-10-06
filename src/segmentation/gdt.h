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

#include "segmentation/structs.h"

#include "lib/util.h"

namespace Segmentation
{

void setup_gdt();

constexpr SegmentSelector CS_SELECTOR_KERNEL =
{
    .requestor_privilege_level = to_underlying_type(PrivilegeLevel::KERNEL),
    .table_indicator = to_underlying_type(TableIndicator::GDT),
    .selector_index = 2
};

constexpr SegmentSelector CS_SELECTOR_USER =
{
    .requestor_privilege_level = to_underlying_type(PrivilegeLevel::USER),
    .table_indicator = to_underlying_type(TableIndicator::GDT),
    .selector_index = 4
};

} // end namespace Segmentation
