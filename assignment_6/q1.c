#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int *r; 

int top_down_dp(int n)
{
    //write your code here
    if (n == 0) {
        r[0] = 0; 
        return 0; 
    }

    if (n == 1) {
        r[1] = 1; 
        return 1; 
    }

    if (n == 2) {
        r[2] = 2; 
        return 2; 
    }

    if (r[n-1] == -1) {
        r[n-1] = top_down_dp(n-1);
    }

    if (r[n-2] == -1) {
        r[n-2] = top_down_dp(n-2);
    }

    if (r[n-3] == -1) {
        r[n-3] = top_down_dp(n-3);
    }

    return r[n-1] + 2 * r[n-2] - 3 * r[n-3]; 

}


 
int main ()
{
    int n;
    int function;
    int i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    
    r = (int *)malloc(sizeof(int) * (n+1));
    for (int i = 0; i <= n; i++) r[i] = -1; 

    printf("The value of F(%d) is: %d \n", n, top_down_dp(n));
        
}