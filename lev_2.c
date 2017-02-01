#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function: Every word, except for, with, the, or like that must be a capital letter,
// connected with "_" each other.
// Variable: Every word is a lower case, connected with "_" respectively.



// Calculating Levenshtein Distance
// first_arg, second_arg are the letters compared with each other
// the output is the distance

int Calc_Levenshtein_Distance(char *first_arg, char *second_arg){
    int first_arg_length = strlen(first_arg);
    int second_arg_length = strlen(second_arg);

    printf("first_arg_length:%d\n", first_arg_length);
    printf("second_arg_length:%d\n", second_arg_length);

    char *first_letters_1 = (char *)malloc(sizeof(char) * first_arg_length);
    char *second_letters_2 = (char *)malloc(sizeof(char) * second_arg_length);

    //copy
    strcpy(first_letters_1, first_arg);
    strcpy(second_letters_2, second_arg);

    printf("succeeded in generating array\n");

    int **array_lev = (int **)malloc(sizeof(int*) * (first_arg_length + 1));
    for(int i = 0; i < first_arg_length + 1; i++){
        array_lev[i] = (int *)malloc(sizeof(int) * (second_arg_length + 1));
    }
    printf("succedded in generating calc_array\n");

    array_lev[0][0] = 0;

    for(int j = 1; j < first_arg_length + 1; j++){
        array_lev[j][0] = j;
        printf("%d times at first_arg\n", j);
    }
    for(int k = 1; k < second_arg_length + 1; k++){
        array_lev[0][k] = k;
        printf("%d times at second arg\n", k);
    }

    //main algorithm
    int l = 1;
    while (l < first_arg_length + 1) {
        //int first_arg_length_plus_1 = first_arg_length + 1;
        //printf("first_arg_length_plus_1:%d\n", first_arg_length_plus_1);
        for (int m = 1; m < second_arg_length + 1; m++) {
            int number_upper_right_diagonal = array_lev[l-1][m-1];
            int number_left = array_lev[l][m-1] + 1;
            int number_upper = array_lev[l-1][m] + 1;

            // The flag for coparing letters
            if (first_letters_1[l] == second_letters_2[m]) {
                number_upper_right_diagonal += 0;
            }
            else {
                number_upper_right_diagonal += 1;
            }
            //So troublesome if-statements so please fix it hahahaha
            //if all the same. dont have to add 1 to number_upper_right_diagonal for added above
            if ((number_upper_right_diagonal == number_left ) && (number_left == number_upper)){
                array_lev[l][m] = number_upper_right_diagonal;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("all the same\n");
            }
            // if one is smaller than others that are the same 
            if ((number_upper_right_diagonal == number_left) && (number_left > number_upper)){
                array_lev[l][m] = number_upper;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("one is smaller\n");
            }
            else if ((number_upper_right_diagonal == number_upper) && (number_upper > number_left)){
                array_lev[l][m] = number_left;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("one is smaller\n");
            }
            else if ((number_left == number_upper) && (number_upper > number_upper_right_diagonal)){
                array_lev[l][m] = number_upper_right_diagonal;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("one is smaller\n");
            }
            else if((number_upper_right_diagonal > number_left) && (number_left > number_upper)){
                array_lev[l][m] = number_upper;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("one is smaller\n");
            }

            //if all is not same so boring
            else if((number_upper_right_diagonal > number_left) && (number_left > number_upper)){
                array_lev[l][m] = number_upper;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("all is not the same\n");
            }
            else if((number_upper_right_diagonal > number_upper) && (number_upper > number_left)){
                array_lev[l][m] = number_left;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("all is not the same\n");
            }
            else if((number_left > number_upper) && (number_upper > number_upper_right_diagonal)){
                array_lev[l][m] = number_upper_right_diagonal;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("all is not the same\n");
            }
            else if((number_left > number_upper_right_diagonal) && (number_upper_right_diagonal > number_upper)){
                array_lev[l][m] = number_upper;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("all is not the same\n");
            }
            else if((number_upper > number_upper_right_diagonal) && (number_upper_right_diagonal > number_left)){
                array_lev[l][m] = number_left;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("all is not the same\n");
            }
            //else ((number_upper > number_left) && (number_left > number_upper_right_diagonal)){
            else {
                array_lev[l][m] = number_upper_right_diagonal;
                printf("array_lev[%d][%d] = %d\n", l, m, array_lev[l][m]);
                printf("all is not the same\n");
            }
        }
        l++;
    }

    int answer_calc = array_lev[first_arg_length][second_arg_length];
    return answer_calc;

    free(first_letters_1);
    free(second_letters_2);
    for(int n = 0; n < first_arg_length + 1; n++){
      free(array_lev[n]);
    }
    free(array_lev);
}

int main(){

    printf("Go\n");
    char *letter_1 = "bonbastic";
    char *letter_2 = "bonbonbon";

    printf("pass 1\n");

    int answer = Calc_Levenshtein_Distance(letter_1, letter_2);

    printf("The distance is %d\n", answer);

    return 0;
}