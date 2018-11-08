#include<stdio.h>
#define BOYUT(a)((a)+(a))//each element should include parenthesis otherwise it can be cause some errors.!


int main(){
int i=2;
int j=4;
printf("Before the macro using.:\ni value is:%d\nj value is:%d",i,j);


i=BOYUT(i);
j=BOYUT(j);


printf("\nAfter the macro using.:\ni value is:%d\nj value is:%d\n",i,j);

return 0;}
