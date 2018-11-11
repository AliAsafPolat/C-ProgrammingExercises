#include<stdio.h>
#include<string.h>

int main(){

char dest[]="old string.";
const char source[]="new string is this.";

printf("Before the memmove operation : %s \n",dest);
memmove(dest,source,20);
printf("After the memmove operation : %s  \n",dest);
return 0;
}
