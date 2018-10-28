#include<stdio.h>


int factorial(int i){
	int j,conc;
	
	if (i>1)
	i=i*factorial(i-1);
	else 					 
	return i;
	
	
	
}


int main(){
	
	int i=31;
		
		printf("%d  factorial is %d ", i , factorial(i));
	
	return 0;
}


