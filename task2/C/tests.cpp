#include <fstream>
#include <iostream>
#include "gtest/gtest.h"
#include "path.h"

TEST(Index, Correct) { 
    std::ifstream fin(path1);
    char* actual_str = new char[20];
    fin.getline(actual_str, 20);
    std::cout << actual_str <<"\n";
     
    ASSERT_STREQ("#include <math.h>", actual_str);
    delete[] actual_str;
}
 
TEST (Lib, Correct) { 
    std::ifstream fin(path2);
    char* actual_str = new char[20];
    fin.getline(actual_str, 20);
    ASSERT_STREQ("#include <iostream>", actual_str);
    fin.getline(actual_str, 20);
    ASSERT_STREQ("void Hello();", actual_str);
    delete[] actual_str;
}
