
#include "int_array.h"

Array* create_int_arr(size_t size){
    return create(sizeof(int), size); // функция возвращает указатель на массив
}

void for_map (int *t, int *res){
    *res = *t+10;
}

int for_where (int *p){
    return  *p<=20;
}

void print_array(Array* arr){
    int temp;
    for(int i=0; i<arr->size;i++) {
        get(arr,i,&temp);
        printf("%d ", temp);
    }
    printf("\n");
}
