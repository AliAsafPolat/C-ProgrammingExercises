#include<stdio.h>

int square (int a){
a=a*a;

return a;
}

int main(){
int (*pf)();
int sum=5;

pf=square;
sum=(*pf)(sum);

printf("%d",sum);



return 0;
}
