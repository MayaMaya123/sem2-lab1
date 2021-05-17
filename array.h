//
// Created by Майя Флейшер on 18.02.2021.
//

#ifndef UNTITLED1_ARRAY_H
#define UNTITLED1_ARRAY_H

#include <stdlib.h>
#include <stdio.h>
// структура массива
typedef struct array{
    void* Memory; // память
    size_t element_size;//размер одного элемента
    size_t size;// количество элементов

   /* void* (*map)(void*, void*);
    void* (*where)(void*,void*);
    void* (*conc)(void*,void*);
*/
} Array;

Array* create (size_t element_size, size_t size);
void delete (Array* a);
void get (Array* a, size_t index, void* destination);  // get получает значение из массива
void set (Array* a,size_t Index, void* source);  // set установливает значение элементов
void grow (Array* a,size_t Amount);  // увеличивает количество элементов массива
void decrease (Array* a, size_t Amount);

void map(void* (*func)(void*, void*), Array *arr); //map прогоняет каждый элемент массива через функцию
void where(int (*func)(void*), Array *arr); // where фильтрует массив
void concatenate(Array* arr1, Array* arr2);

#endif //UNTITLED1_ARRAY_H
