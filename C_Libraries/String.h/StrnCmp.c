#include<stdio.h>
#include<string.h>

int main(){
	char str1[]="Asaf's Code";
	char str2[]="Asaf's Repo";
int i;

	i=strncmp(str1,str2,8); //You can try with n=4, output will be 'they are equal'
	if (i<0)
	printf("Str2 is greater.\n");
	else if (i>0)
		printf("Str1 is greater.\n");
	else printf("They are equal");

	return 0;



}
