#include<stdio.h>
#include<string.h>

//In this tutorial:
//	if the return_value<0 then str1 is less than str2====str2>str1
// 	if the return_value>0 then str2 is less than str1====str1>str2
//	otherwise str1==str2


int main()
{
char str1[15];
char str2[15];
int *ret;
				//When we look at the ASCII table str1 is greater than str2
memcpy(str1,"abcdef",6);	//6 is length of "abcdef"
memcpy(str2,"ABCDEF",6);

ret= memcpy(str1,str2,5);	//5 byte will be compared.

if (ret>0){
printf("Str1 is greater than Str2\n");
} else if(ret<0){
printf("Str2 is greater than Str2\n");
}else{
printf("Str1 is equal to Str2\n");
}



return 0;
}
