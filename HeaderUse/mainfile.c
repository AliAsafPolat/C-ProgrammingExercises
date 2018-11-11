#include<stdio.h>
#include"headertopla.h"
#include"headercarp.h"
int main(void){
int i=5,j=6;
extern int s;

	topla(i,j);
	printf("\n");
       carp(i,j);
printf("\n");       
	printf("%d",s);
       return 0;

}
