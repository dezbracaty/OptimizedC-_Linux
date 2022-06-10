//
// Created by allen on 22-5-13.
//

#ifndef OPTIMIZEDC__LINUX_BLOCKCOPYOPERATOR_H
#define OPTIMIZEDC__LINUX_BLOCKCOPYOPERATOR_H
#ifdef __cplusplus > 199711L
class BigClass {
public:
    BigClass(BigClass  const & oth) = delete;
    BigClass & operator=( BigClass const &oth) = delete;
    BigClass() = default;
};
class MoveConstruct{
public:
    MoveConstruct() = default;
    MoveConstruct( MoveConstruct &&rhs ) noexcept {
        std::cout<<"MoveConstruct &&rhs "<<std::endl;
    }
    MoveConstruct( MoveConstruct const & rhs ){
        std::cout<<"MoveConstruct const & rhs "<<std::endl;
    }
    MoveConstruct & operator = (MoveConstruct const & rhs){
        std::cout<<"MoveConstruct operator  =  "<<std::endl;
    }
    ~MoveConstruct(){
        std::cout<<" ~MoveConstruct "<<std::endl;
    }
public:
    int a = 10;
};
#else
class BigClass {
private:
    BigClass(BigClass  const & oth);
    BigClass & operator=( BigClass const &oth);
public:
    BigClass() = default;
};

#endif
#endif //OPTIMIZEDC__LINUX_BLOCKCOPYOPERATOR_H
