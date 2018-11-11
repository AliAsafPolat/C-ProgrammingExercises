#include<stdio.h>
#include<string.h>

int main(){

	char str1[]="Asaf says hello to you!";
	char str2[]="hello";
	char *ret;

	ret=strstr(str1,str2);

	if (ret==NULL)
		printf("Pattern couldn't found.\n");
	else
		printf("After this pattern sentence is : %s",ret);




return 0;
}
