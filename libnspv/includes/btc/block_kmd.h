/*

 The MIT License (MIT)

 Copyright (c) 2016 Thomas Kerin
 Copyright (c) 2016 libbtc developers

 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
 OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef __LIBBTC_BLOCKKMD_H__
#define __LIBBTC_BLOCKKMD_H__

#include "btc.h"
#include "buffer.h"
#include "cstr.h"
#include "hash.h"

LIBBTC_BEGIN_DECL

typedef struct kmd_block_header_ {
    int32_t version;
    uint256 prev_block;
    uint256 merkle_root;
    uint256 final_sapling_root;
    uint32_t timestamp;
    uint32_t bits;
    uint256 nonce;
    cstring *solution;
} kmd_block_header;

LIBBTC_API kmd_block_header* kmd_block_header_new();
LIBBTC_API void kmd_block_header_free(kmd_block_header* header);
LIBBTC_API int kmd_block_header_deserialize(kmd_block_header* header, struct const_buffer* buf);
LIBBTC_API void kmd_block_header_serialize(cstring* s, const kmd_block_header* header);
LIBBTC_API void kmd_block_header_copy(kmd_block_header* dest, const kmd_block_header* src);
LIBBTC_API btc_bool kmd_block_header_hash(kmd_block_header* header, uint256 hash);

LIBBTC_END_DECL

#endif // __LIBBTC_BLOCK_H__
