#include<stdio.h>
#include<string.h>

int main(){

	char str1[]="Asafa";
	char str2[]="Asaff";

	if (strcmp(str1,str2)>0)
		printf("Str1 is greater than Str2\n");
	else if (strcmp(str1,str2)<0)
		printf("Str2 is greater than Str1 \n");
	else printf("They are equal.\n");






return 0;
}
