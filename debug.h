#ifndef DEBUG_H__C
#define DEBUG_H__C
#include <stdio.h>
#ifdef DEBUG
#define DEBUG_TEST 1
#else
#define DEBUG_TEST 0
#endif

#define debug_print(str,...) do {if (DEBUG_TEST) printf("[In %20s:\t Line: %4d]\tfunc:%-15s call " #str "\n", __FILE__, __LINE__, __func__,##__VA_ARGS__);} while( 0 )

#endif