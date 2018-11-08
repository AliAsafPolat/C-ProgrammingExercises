#include<stdio.h>

#define Check(a,b) if ((a)!=(b)) fail (a,b,__FILE__,__LINE__)

void fail(int a,int b,char *p,int line){
printf("Check failed in file %s at line %d received %d , expected %d \n",p,line,a,b);

}

int main(){
int i,j;

i=6;
j=5;

Check(i,j);


return 0;
}
