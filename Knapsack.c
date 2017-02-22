#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_W 5

//dont forget free() using malloc

//Solve max value with constraint of MAX_W, in this case, 5
int Solve_with_DP(int *value, int *weight, int length){
    
    //make a table, dp[]
    //dp[w][n] = v

    int **dp = (int **)malloc(sizeof(int *) * (MAX_W + 1));
    for(int i = 0; i <= MAX_W; i++){
        dp[i] = (int *)malloc(sizeof(int) * (length + 1));
    }

    for(int j = 0; j <= MAX_W; j++){
        for(int k = 0; k <= length; k++){
            dp[j][k] = -1;
        }
    }

    dp[0][0] = 0;

    //main algorithm
    for(int l = 0; l <= length ; l++){
        for(int m = 0; m <= MAX_W; m++){
        
            int value_in_loop = value[l];
            int weight_in_loop = weight[l];

            if(dp[m][l] == -1){
                continue;
            }
            else{
                if(dp[m][l + 1] == -1){
                    dp[m][l + 1] = dp[m][l];
                }
                else{
                    continue;
                }

                if(m + weight_in_loop > MAX_W){
                    continue;
                }
                else{
                    if(dp[m][l] + value_in_loop > dp[m + weight_in_loop][l]){
                        dp[m + weight_in_loop][l + 1] = dp[m][l] + value_in_loop;
                    }
                    else{
                        dp[m + weight_in_loop][l + 1] = dp[m + weight_in_loop][l];
                    }
                }
            }
        }
    }
    
    for(int n_1 = 0; n_1 <= MAX_W; n_1++){
        for(int n_2 = 0; n_2 <= length; n_2++){
            printf("dp[%d][%d] = %d\n", n_1, n_2, dp[n_1][n_2]);
        }
    }


    for(int n = length; n >= 0; n--){
        int maximum = dp[0][n];
        for(int o = 1; o <= MAX_W; o++){
            if(maximum < dp[o][n]){
                maximum = dp[o][n];
            }
            else{
                continue;
            }
        }
        if(maximum != -1){
            return maximum;
            break;
        }
        else{
            continue;
        }
    }

    for(int p = 0; p <= MAX_W; p++){
        free(dp[p]);
    }
    free(dp);

}

int main(){

    //
    //    
    //   v| 4 5 2 8 
    //   -----------
    //   w| 2 2 1 3 
    //
    //  
    // with constraint of maximum w as 5

    int v[4] = {4, 5, 2, 8};

    int w[4] = {2, 2, 1, 3};

    int length_of_v = sizeof(v)/sizeof(int);

    int answer = Solve_with_DP(v, w, length_of_v);

    printf("The answer is %d\n", answer);
}