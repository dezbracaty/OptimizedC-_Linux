//
// Created by allen on 22-4-22.
//

#include "blockAlloctor.h"

char block_o_memory::mem_[block_o_memory::size][block_o_memory::blocksize] = {};
bool block_o_memory::free_[block_o_memory::size] = {true, true, true, true, true, true, true, true};
