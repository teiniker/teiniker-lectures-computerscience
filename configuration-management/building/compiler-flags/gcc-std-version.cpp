/*
The __cplusplus macro indicates the C++ standard version 
the compiler is using by default or under specific flags.

Interpreting the Output:
	199711L -   C++98	
	199711L -   C++03	
	201103L -   C++11	
	201402L	-   C++14
	201703L -   C++17	
	202002L -   C++20	
	202302L -   C++23	

$ g++ -std=c++17 -o program program.c
*/

#include <stdio.h>

int main() 
{
    printf("C++ Standard version: %ld\n", __cplusplus);
    return 0;
}
