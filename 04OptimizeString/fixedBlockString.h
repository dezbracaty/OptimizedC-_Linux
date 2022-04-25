#include "blockAlloctor.h"

typedef std::basic_string<char,
        std::char_traits<char>,
        blockAlloctor<char,10>>
        fixed_block_string;

