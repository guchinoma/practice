#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Each element is different from each other. Will write the case of having same numbers.
int *quick_sort(int *, int, int);

int main(){
    int array[15] = {33, 8, 2, 25, 9, 18, 6, 23, 77, 1, 45, 888, 46, 54545, 0};
    int len = sizeof(array)/sizeof(array[0]);
    printf("%d\n", len);
    //return 0;
    int *array_answer = quick_sort(array, 0, len - 1);

    for(int i = 0; i < len; i++){
        printf("array_answer[%d]:%d\n", i, array_answer[i]);
    }

    return 0;
}

int *quick_sort(int *pointer, int start, int last){

    int pivot_number = (start + last)/2;
    int pivot = pointer[pivot_number];
    printf("pivot:%d\n", pivot);

    int bigger_number_in_smaller_raw;
    int smaller_number_in_bigger_raw;

    if(start == last){
        printf("One elemets\n");
        return pointer;
    }
    else{


        for(int j = start; j <= pivot_number; j++){
            if(pointer[j] >= pivot){
                printf("pointer[j]:%d\n", pointer[j]);
                bigger_number_in_smaller_raw = j;
                break;
            }
            else{
                continue;
            }
        }

        for(int k = last; k >= pivot_number; k--){
            if(pointer[k] <= pivot){
                printf("pointer[k]:%d\n", pointer[k]);
                smaller_number_in_bigger_raw = k;
                break;
            }
            else{
                continue;
            }
        }

        printf("bigger_number_in_smaller_raw:%d\n", bigger_number_in_smaller_raw);
        printf("smaller_number_in_bigger_raw:%d\n", smaller_number_in_bigger_raw);

        //return 0;

        if(bigger_number_in_smaller_raw == smaller_number_in_bigger_raw){
            printf("Separate\n");
            if(start == pivot_number){
                // This is for two elements that are correct order. 
                // This case has same "start" and "pivot_number"
                // e.g (6, 7) or (5, 8) or sth
                // In that cases without this clause, 
                // start and pivot_number - 1(start - 1) directly goes to 
                // the arguments of quick_sort() and will lead to segmentation fault.
                pointer = quick_sort(pointer, start, start);
                pointer = quick_sort(pointer, last, last);
            }
            else{
                printf("[Separate] start:%d last:%d\n", start, pivot_number - 1);
                pointer = quick_sort(pointer, start, pivot_number - 1);
                printf("[Separate] start:%d last:%d\n", pivot_number + 1, last);
                pointer = quick_sort(pointer, pivot_number + 1, last);
            }
        }
        else{
            printf("swapping\n");
            //printf("swapped numbers: pointer[smaller_number_in_bigger_raw]:%d pointer[bigger_number_in_smaller_raw]:%d\n", pointer[smaller_number_in_bigger_raw], pointer[bigger_number_in_smaller_raw]);
            int tmp = pointer[smaller_number_in_bigger_raw];
            pointer[smaller_number_in_bigger_raw] = pointer[bigger_number_in_smaller_raw];
            pointer[bigger_number_in_smaller_raw] = tmp;
            printf("(after swapping)swapped numbers: pointer[smaller_number_in_bigger_raw]:%d\n", pointer[smaller_number_in_bigger_raw]);
            printf("(after swapping)swapped numbers: pointer[bigger_number_in_smaller_raw]:%d\n", pointer[bigger_number_in_smaller_raw]);
            printf("start:%d last:%d\n", start, last);
            for(int l = 0; l < 15; l++){
                printf("pointer[%d]:%d\n", l, pointer[l]);
            }
            pointer = quick_sort(pointer, start, last);
        }
    }

    return pointer;

}

