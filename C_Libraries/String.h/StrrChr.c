#include<stdio.h>
#include<string.h>

int main(){

	char str1[]="www.asaf.has.this.repo";
	char ch='.';
	char *ret;
	int len;	
ret= strrchr(str1,ch);
len= strrspn(str1,ch);
	printf("Last found char '%c' is at %d .\n After this char sentence is:%s\n",ch,len,ret);





return 0;
}
