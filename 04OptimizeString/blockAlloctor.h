//
// Created by allen on 22-4-22.
//

#ifndef OPTIMIZEDC__LINUX_BLOCKALLOCTOR_H
#define OPTIMIZEDC__LINUX_BLOCKALLOCTOR_H
#include <iostream>
class block_o_memory {
public:
    static const unsigned size = 8;
    static const size_t   blocksize = 512;
    static void* allocate(size_t size){
        if (size <= blocksize) {
            for (unsigned i = 0; i < sizeof(free_)/sizeof(free_[0]); ++i) {
                if (free_[i]) {
                    free_[i] = false;
                    return mem_[i];
                }
            }
        }
        throw std::bad_alloc();
        return nullptr;
    };
    static void  deallocate(void* p){
        typedef char blocktype[512];
        if (p == 0)
            return;
        if (p < (void*)mem_ || p > (void*)(mem_ + size))
            throw std::bad_alloc();
        unsigned i = static_cast<blocktype*>(p) - mem_;
        free_[i] = true;
        mem_[i][0] = 0;
    };
    static unsigned count(){
        unsigned ct = 0;
        for (unsigned i = 0; i < size; ++i)
            if (!free_[i])
                ct += 1;
        return ct;
    };
private:
    static char mem_[size][blocksize];
    static bool free_[size];
};

template <typename T> class allocter_defs{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef size_t size_type;

};

template<typename T,size_t N >
class blockAlloctor:public allocter_defs<T>{
public:
    using typename allocter_defs<T>::value_type;
    using typename allocter_defs<T>::pointer;
    using typename allocter_defs<T>::size_type;
    template <typename U> struct rebind {
        typedef blockAlloctor<U, N> other;
    };
    pointer allocate(
            size_type count,
            typename std::allocator<void>::const_pointer = 0) {
        return reinterpret_cast<pointer>(block_o_memory::allocate(count * sizeof(T)));
    }
    void deallocate(pointer p, size_type){
        block_o_memory::deallocate(p);
    }
    bool operator==(blockAlloctor const&) const {
        return true;
    }
    bool operator!=(blockAlloctor const& a) const {
        return !operator==(a);
    }

};


#endif //OPTIMIZEDC__LINUX_BLOCKALLOCTOR_H
