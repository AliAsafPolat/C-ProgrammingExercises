#include<stdio.h>

int main(int argc, int*argv[]){
	
	while(--argc>0)
	printf("%d",*++argv);
	return 0;	
	
	
}
