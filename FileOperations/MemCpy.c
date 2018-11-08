#include<stdio.h>
#include<string.h>
//This function will copy src to ...


int main (){

const char src[50]="AsafReis";

char dest[50];

strcpy(dest,"ReisAsaf");

printf("Before the copy : %s \n",dest);
memcpy(dest,src,strlen(src)+1);
printf("After the copy : %s\n",dest);

return 0;

}
