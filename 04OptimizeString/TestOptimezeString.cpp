
#include "stringFunctions.h"
#include "../03StopWatch/StopWatch.h"

std::string s("\07Now is the time\07 for all good men\r\n to come to the aid of their country. \07");
std::string test("Now is the time for all good men to come to the aid of their country. ");
void test_Rm_Ctrl_01(){
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl(s + s + s);
    }
};
void test_Rm_Ctrl_02(){
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_mutating  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_mutating(s + s + s);
    }
};
void test_Rm_Ctrl_03(){
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Reserve  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_reserve(s + s + s);
    }
};
void test_Rm_Ctrl_04(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Ref_Args  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_ref_args(tmp);
    }
};
void test_Rm_Ctrl_05(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Ref_Args_It  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_ref_args_it(tmp);
    }
};

void test_Rm_Ctrl_06(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Ref_Args_CacheSize  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_ref_args_cacheSize(tmp);
    }
};

void test_Rm_Ctrl_07(){
    auto tmp = s + s + s;
    std::string res;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Ref_Result_it  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_ref_result_it(res,tmp);
    }
};

void test_Rm_Ctrl_08(){
    auto tmp = s + s + s;
    std::string res;
    char dest[tmp.size()];
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Cstrings  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_cstrings(dest,res.c_str(),tmp.size());
    }
};


void test_Rm_Ctrl_09(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Block  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_block(tmp);
    }
};
void test_Rm_Ctrl_10(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Mutate  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_block_mutate(tmp);
    }
};
void test_Rm_Ctrl_11(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Append  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_block_append(tmp);
    }
};

void test_Rm_Ctrl_12(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Block_Args  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_block_args(tmp);
    }
};
void test_Rm_Ctrl_13(){
    auto tmp = s + s + s;
    std::string res;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Block_Ret_It  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_block_ret_it(res,tmp);
    }
};

void test_Rm_Ctrl_14(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Erase  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_erase(tmp);
    }
};

void test_Rm_Ctrl_15(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Erase_It  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_erase_it(tmp);
    }
};

void test_Rm_Ctrl_16(){
    auto tmp = s + s + s;
    basic_StopWatch<baseTimerClock> SW("test Remove_ctrl_Fixed_Block  ");
    for(int i = 0; i < 10;i++){
        remove_ctrl_fixed_block(tmp);
    }
};
int main(){


    test_Rm_Ctrl_01();
    test_Rm_Ctrl_02();
    test_Rm_Ctrl_03();
    test_Rm_Ctrl_04();
    test_Rm_Ctrl_05();
    test_Rm_Ctrl_06();
    test_Rm_Ctrl_07();
    test_Rm_Ctrl_08();
    test_Rm_Ctrl_09();
    test_Rm_Ctrl_10();
    test_Rm_Ctrl_11();
    test_Rm_Ctrl_12();
    test_Rm_Ctrl_13();
    test_Rm_Ctrl_14();
    test_Rm_Ctrl_15();
    test_Rm_Ctrl_16();

}