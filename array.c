//
// Created by Майя Флейшер on 18.02.2021.
//

#include "array.h"
#include <stdlib.h>
#include <string.h>
//typedef struct array{
  //  void* P;
   // size_t n;
    //void* map;
//} Array;
//Array*  init_num(size_t size) //init_num- function for initialization numbers array
//{
  //  Array* z=malloc(sizeof(Array));
    //z->P=malloc(sizeof(float)*size);
    //z->n=size;
   // return z;
//}
Array* create (size_t element_size, size_t size){ // создаем массив
 Array* rez=malloc(sizeof(Array));
 rez->size=size;
 rez->element_size=element_size;
 rez->Memory= malloc(size * element_size);

    return rez;
}

// удаляем массив
void delete (Array* a) {
    if (a != NULL) {
        if (a->Memory != NULL) {
            free(a->Memory);

        }
        free(a);
    }
}
//destination-адрес на переменную в которую нужно передать значение массива
void get (Array* a, size_t index, void* destination) { // get получает значение из массива
    if (a != NULL && 0 <= index && index < a->size && destination != NULL) {
        void *o;
        o = a->Memory + (index * a->element_size);
        memcpy(destination, o, a->element_size);
    }
}
//source-"источник"
void set (Array* a, size_t Index, void* source) { // set установливает значение элементов
    if (a != NULL && 0 <= Index && Index < a->size && source != NULL) {
        void *o;
        o = a->Memory + (Index * a->element_size);//находим место в которое нужно записать новый элемент
        memcpy(o, source, a->element_size);
    }
}
// увеличивает количество элементов массива
void grow (Array* a, size_t Amount) {
    if (a != NULL && 0 < Amount) {
        size_t new_size = a->element_size * (a->size + Amount);
        void* new_memory = realloc(a->Memory, new_size);// realloc - изменяет размер буфера
          a->Memory=new_memory;
          a->size += Amount;
    }
}
// уменьшает количество элементов массива
void decrease (Array* a, size_t Amount) {
    if (a != NULL && 0 < Amount) {
        size_t new_size = a->element_size * (a->size - Amount);
        void *new_memory = realloc(a->Memory, new_size);
        a->Memory = new_memory;
        a->size -= Amount;
    }
}
// в map передаем функцию которая принимает в себя два указателя: один указатель для элемента массива
// второй для результата функции
//map прогоняет каждый элемент массива через функцию
void map(void* (*func)(void*, void*), Array *arr){
    void* temp = malloc(arr->element_size);// выделяем память
    void* res = malloc(arr->element_size);
    for(int i=0; i<arr->size; i++ ){
        get(arr, i, temp);
        func(temp, res);
        set(arr, i, res);
    }
    free(temp); // освобождаем память
    free(res);

}

// where фильтрует массив
void where(int (*func)(void*), Array *arr){
    Array *array = create(arr->element_size, arr->size);// создаем переменную array и инициализируем ее
    size_t counter = 0;
    void* temp = malloc(arr->element_size);
    for(int i=0; i<arr->size; i++){ // "перебираем" все элементы массива
        get (arr, i, temp);// записываем в temp значение элемента массива под индексом i
        int res = func(temp); //вызываем функцию с аргументом temp
        if(res){ // проверяем что вернула функция func
            set(array, counter, temp); // в индекс i массива array записываем значение temp
            counter++;
        }
    }
    decrease(array, arr->size-counter);// отрезаем лишние элементы массива
    //delete(arr);
    //memcpy(arr->Memory, array->Memory, arr->size * arr->element_size);
     memcpy(arr, array, sizeof(Array)); // копируем память: arr - куда array-откуда
}
//realloc-перевыделяет памяять
void concatenate(Array* arr1, Array* arr2){  //склеиваем два массива
    if(arr1 && arr2) {
        arr1->Memory = realloc(arr1->Memory, (arr1->size + arr2->size) * arr1->element_size);
        void *position = arr1->Memory + arr1->size * arr1->element_size;//ищем куда добавить элементы arr2
        memcpy(position, arr2->Memory, arr2->size * arr1->element_size);//добавляем элементы arr2
        arr1->size += arr2->size;
        delete(arr2);
    }
}