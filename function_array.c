
#include "function_array.h"


Array* create_function_arr(size_t size){
    return create(sizeof(&create_function_arr),size);
}

void f_map (void* fun, void* t){
    t = fun;
    int (**tfun)(int) = fun;
    int (*tfun2)(int) = *tfun;
    int temp = tfun2(4);
    printf("%d ", temp);
    puts(" ");
}

int f_where (int (**func)(int n)){
    int (*fun)(int) = *func;
    int result = fun(4);
    return result > 10;
}


int square (int s){
    return s*s;
}


int multiply (int a){
    return a*10;
}


int increase (int b){
    return b+2;
}


int reduce (int c){
    return c-19;
}