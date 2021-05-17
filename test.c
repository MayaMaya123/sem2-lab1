#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"
#include "function_array.h"
#include "int_array.h"

void test1() {
    size_t element_size = sizeof(int);
    size_t size = 20;
    Array *arr = create(element_size, size);// создаем массив
    assert(arr != NULL);
    assert(size == arr->size);
    puts("успешно создано");

    int b_z=10;
    int mr;

    set(arr, 10, &b_z);
    set(NULL, 28, NULL);
    set(arr, -6, &b_z);
    set(arr, 26, &b_z);

    get(arr, 10, &mr);
    assert(b_z == mr);
    get(arr, -6, &b_z);
    get(arr, 26, &b_z);

    puts("get and set is okay");

    grow(arr, 10);
    assert(arr->size == 30);
    set(arr, 22, &b_z);

    grow(NULL, 2);

    decrease(arr, 20);
    assert(arr->size == 10);

    decrease(NULL, 9);
    decrease(arr, -9);

    puts("decrease and grow is okay");
    // инициализируем массив

    for(int i=0; i<arr->size; i++){
        set(arr, i, &i);
    }
    puts("NULL, NULL");
    concatenate(NULL, NULL);
    puts("NULL, arr");
    concatenate(NULL, arr);
    puts("arr, NULL");
    concatenate(arr, NULL);
    puts("concatenate is ok");


    map(for_map, arr);
    print_array (arr);
    where(for_where, arr);
    print_array (arr);
    delete(arr);
}


void test2(){
    Array *cry = create_int_arr (23);
    assert( cry->size==23);

    for (int i = 0; i<23; i++){ //проинециализировали каждый элемент массива
        int w=i*3;
        set(cry, i, &w);
    }
// получаем значение каждой ячейки и проверяем на легальность
    for (int i=0; i<23; i++){
        int l;
        get(cry, i, &l);
        assert (l==i*3);
    }



}


int main(){
    test1();
    //test2();
    return 0;
}
