#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char buffer_for_number[4];

    printf("Please put number less that 100\n");

    fgets(buffer_for_number, 4, stdin);

    int number = atoi(buffer_for_number);
    printf("The number:%d\n", number);

    int *array = (int *)malloc(sizeof(int) * number);

    for(int i = 0; i < number; i++){
        char tmp[100];
        fgets(tmp, 100, stdin);
        int tmp_number = atoi(tmp);
        array[i] = tmp_number;
        if(i > 0){
            printf("The one before last:%d\n", array[i - 1]);
        }
        else{
            continue;
        }
    }
    
    free(array);

    return 0;

}
