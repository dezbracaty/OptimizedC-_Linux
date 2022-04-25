//
// Created by allen on 22-4-19.
//
#include <iostream>
#include "fixedBlockString.h"
#ifndef OPTIMIZEDC__LINUX_STRINGFUNCTIONS_H
#define OPTIMIZEDC__LINUX_STRINGFUNCTIONS_H
//最初始的版本
std::string remove_ctrl(std::string s) {
    std::string result;
    for (int i=0; i<s.length(); ++i) {
        if(s[i] >= 0x20)
            result = result + s[i];
    }
    return result;
}
//去除临时字符串
std::string remove_ctrl_mutating(std::string s) {
    std::string result;
    for (int i=0; i<s.length(); ++i) {
        if(s[i] >= 0x20)
            result += s[i];
    }
    return result;
}
//通过预留存储空间减少内存分配
std::string remove_ctrl_reserve(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (int i=0; i<s.length(); ++i){
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}
//通过字符串引用减少实参的复制
std::string remove_ctrl_ref_args(std::string const& s) {
    std::string result;
    result.reserve(s.length());
    for (int i=0; i<s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}
//通过迭代器的方式遍历字符串
std::string remove_ctrl_ref_args_it(std::string const& s) {
    std::string result;
    result.reserve(s.length());
    for (auto it=s.begin(),end=s.end(); it != end; ++it) {
        if (*it >= 0x20)
            result += *it;}
    return result;
}
//通过字符串引用减少实参的复制
std::string remove_ctrl_ref_args_cacheSize(std::string const& s) {
    std::string result;
    auto _size = s.length();
    result.reserve(_size);
    for (int i=0; i < _size; ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}
void remove_ctrl_ref_result_it (
        std::string& result,
        std::string const& s) {
    result.clear();
    result.reserve(s.length());
    for (auto it=s.begin(),end=s.end(); it != end; ++it) {
        if (*it >= 0x20)
            result += *it;
    }
}
//避免返回值的方式减少字符复制
void remove_ctrl_cstrings(char* destp, char const* srcp, size_t size) {
    for (size_t i=0; i<size; ++i) {
        if (srcp[i] >= 0x20)
            *destp++ = srcp[i];
    }
    *destp = 0;
}


//以下是算法优化部分

//使用字串的方式
std::string remove_ctrl_block(std::string s) {
    std::string result;
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1) {
        for (i = b; i < e; ++i) {
            if (s[i] < 0x20)
                break;
        }
        result = result + s.substr(b, i - b);
    }
    return result;
}
// 移除临时字符串
std::string remove_ctrl_block_mutate(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (size_t b=0,i=b,e=s.length(); b < e; b = i+1) {
        for (i=b; i<e; ++i) {
            if (s[i] < 0x20) break;
        }
        result += s.substr(b,i-b);
    }
    return result;
}

//通过调用append方法
std::string remove_ctrl_block_append(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (size_t b=0,i=b; b < s.length(); b = i+1) {
        for (i=b; i<s.length(); ++i) {
            if (s[i] < 0x20)
                break;
        }
        result.append(s, b, i-b);
    }
    return result;
}

//通过调用append字串的方式
std::string remove_ctrl_block_args(std::string& s) {
    std::string result;
    result.reserve(s.length());
    for (size_t b=0,i=b; b < s.length(); b = i+1) {
        for (i=b; i<s.length(); ++i) {
            if (s[i] < 0x20)
                break;
        }
        result.append(s, b, i-b);
    }
    return result;
}

//移除返回值
void remove_ctrl_block_ret_it(std::string& result, std::string const& s) {
    result.clear();
    result.reserve(s.length());
    for (auto b=s.begin(),i=b,e=s.end(); b != e; b = i+1) {
        for (i=b; i != e; ++i) {
            if (*i < 0x20)
                break;
        }
        result.append(b, i);
    }
}


//  删除指定字符
std::string remove_ctrl_erase(std::string s) {
    for (size_t i = 0; i < s.length(); )
        if (s[i] < 0x20)
            s.erase(i,1);
        else ++i;
    return s;
}
//通过迭代器删除字符
std::string remove_ctrl_erase_it(std::string s) {
    for (auto i = s.begin(); i != s.end(); )
        if (*i < 0x20)
            s.erase(i);
        else ++i;
    return s;
}


//以下是更换分配器之后的测试代码

// 原始版本的函数，只是更换了内存分配器
fixed_block_string remove_ctrl_fixed_block(std::string s) {
    fixed_block_string result;
    for (size_t i=0; i<s.length(); ++i) {
        if (s[i] >= 0x20)
            result = result + s[i];
    }
    return result;
}



#endif //OPTIMIZEDC__LINUX_STRINGFUNCTIONS_H
