//
// Created by Майя Флейшер on 07.03.2021.
//

#include <stdio.h>
#include "array.h"
#include "int_array.h"
#include "function_array.h"




void print_function(Array* arr){
    int (*temp)(int);
    for(int i=0; i<arr->size; i++){
        get(arr, i, &temp);
        printf("%d ", temp(10));
    }
}
void enter_func_array(Array* arr){
for(int i=0; i<arr->size; i++) {
    puts("choose function");
    puts("1-square");
    puts("2-multiply");
    puts("3-increase");
    puts("4-reduce");
    int choose;
    scanf("%d", &choose);
    scanf("%*c");
    void *temp;
    switch (choose) {
        case 1:
            temp = &square;
            break;
        case 2:
            temp = &multiply;
            break;

        case 3:
            temp = &increase;
            break;

        case 4:
            temp = &reduce;
            break;
    }
    set(arr, i, &temp);
    }
}
int main(){
    int menu;
    size_t size;
    Array* arr;

    puts("MENU");
    puts("What type of array do you need?");
    puts("1-integer array");
    puts("2-function array");
    scanf("%d", &menu);
    scanf("%*c");
    puts("What size of array do you want?");
    scanf("%zu", &size);
    scanf("%*c");
        if (menu==1){
            arr = create_int_arr(size);
            puts("enter the elements of the array");
            int temp;
            for(int i=0;i<size; i++) {
                scanf("%d", &temp);
                set(arr, i, &temp);
            }
            print_array(arr);
            int selection;
            do {
                puts("1-map");
                puts("2-where");
                puts("3-concatenate");
                puts("4-output array"); // вывести массив
                puts("5-exit");
                scanf("%d", &selection);
                scanf("%*c");
                switch (selection) {
                    case 1:
                        map(&for_map, arr);
                        break;
                    case 2:
                       where(&for_where, arr);
                        break;
                    case 3: {
                        puts("Enter the size of array for concatenation?");
                        int array_size;
                        scanf("%d", &array_size);
                        scanf("%*c");
                        puts("Enter elements of array");
                        Array* arrr = create_int_arr(array_size);
                        for (int i=0; i<array_size; i++){
                            scanf("%d", &temp);
                            scanf("%*c");
                            set(arrr, i, &temp);
                        }
                        concatenate(arr, arrr);
                        break;
                    }
                    case 4:
                        print_array(arr);
                        break;
                }
            } while (selection!=5);
        }
    if (menu==2){
        arr = create_function_arr(size);
        enter_func_array(arr);
        int selection;
        do{
            puts("choose action with array");
            puts("1-map");
            puts("2-where");
            puts("3-concatenate");
            puts("4-output array"); // вывести массив
            puts("5-exit");
            scanf("%d", &selection);
            scanf("%*c");
            switch (selection){
                case 1:
                    map(&f_map, arr);
                    break;
                case 2:
                    where(&f_where, arr);
                    break;
                case 3: {
                    puts("Enter the size of array for concatenation?");
                    int array_size;
                    scanf("%d", &array_size);
                    scanf("%*c");
                    puts("Enter elements of array");
                    Array* arrr = create_function_arr(array_size);
                    enter_func_array(arrr);
                    concatenate(arr, arrr);
                    break;
                }
                case 4:
                    //Number-число
                    puts("Enter a number");
                    int Number;
                    scanf("%d", &Number);
                    for(int i=0; i<arr->size; i++) {
                        int (*temp)(int);
                        get(arr, i, &temp);
                        int Result = temp(Number);
                        printf("%d\n", Result);

                    }
                    break;
            }

        } while (selection!=5);
    }
    delete(arr);


    return 0;
}