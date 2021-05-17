//
// Created by Майя Флейшер on 09.04.2021.
//
#include "array.h"
#include <stdlib.h>
#ifndef UNTITLED1_FUNCTION_ARRAY_H
#define UNTITLED1_FUNCTION_ARRAY_H
Array* create_function_arr(size_t size);


void f_map (void* fun, void* t);


int f_where (int (**func)(int n));


int square (int s);


int multiply (int a);


int increase (int b);


int reduce (int c);

#endif //UNTITLED1_FUNCTION_ARRAY_H
