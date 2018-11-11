#include<stdio.h>
#include<string.h>
//Finds first comma in the array and prints after comma.
int main()
{
char str[]="www.asafreis.com";
char ch='.';
char *ret;

ret = strchr(str,ch);

printf("String after %c is :  %s  \n",ch,ret);



return 0;
}
