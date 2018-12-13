 
#include <stdio.h> 


int main() 
{ 
int i,j,k;
    double mat1[4][4] = { {1, 4, 5, -7}, {6, 7, 12, 4}, {2, 1, -4, 8}, {7, 8, 10, 9}}; 
  
    double mat2[4][5] = { {4, 5, -1, 2, 0},  {8, -2, 2, 4, 8}, {10, 4, 2, 5, -2}, {7, 6, 5, 1, 4}}; 
  
    int res[4][5]; // To store result 
 
    
    for (i = 0; i < 4; i++) 
    { 
        for (j = 0; j < 5; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < 4; k++) 
                res[i][j] += mat1[i][k]*mat2[k][j]; 
        } 
    } 
  
    printf("Result matrix is \n"); 
    for (i = 0; i < 4; i++) 
    { 
        for (j = 0; j < 5; j++) 
           printf("%5d ", res[i][j]); 
        printf("\n"); 
    } 
  
    return 0; 
} 
