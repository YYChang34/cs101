#include <stdio.h>

int factorial_calculator(int num) {
	int result_of_factorial = 1, i;  
    if (num == 0) {
    	return(result_of_factorial);
    }  
    else {  
    	for(i = 1; i <= num; i++) {
    		result_of_factorial *= i;
    	}  
    }
    return(result_of_factorial);
}

int main(void) {
	int n, r, nCr;

    printf("Enter the value of n and r?\n");  
    scanf("%d %d",&n,&r);

    nCr = factorial_calculator(n) / (factorial_calculator(r) * factorial_calculator(n - r));

    printf("nCr = %d", nCr);

    return 0;
}