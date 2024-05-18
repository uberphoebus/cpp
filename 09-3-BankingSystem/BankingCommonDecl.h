#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include <cstring>
#include <iostream>

using namespace std;
const int NAME_LEN = 20;

//////////////////////////////////////////////
// Enums
//////////////////////////////////////////////
//////////////////////////////////////////////

// Menu
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// Credit grade
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// Account type
enum { NORMAL = 1, CREDIT = 2 };

#endif