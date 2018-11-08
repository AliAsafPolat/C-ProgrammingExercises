#include<stdio.h>

#if INTSIZE < 16 
	#error INTSIZE too small
#endif

int main(){

printf("Hey dudee\n");
	return 0;
}
