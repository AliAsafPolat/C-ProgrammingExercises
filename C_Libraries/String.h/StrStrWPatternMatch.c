#include<stdio.h>
#include<string.h>

int main(){

char str1[]="Asaf's Repo is here.Welcome!";
char str2[]="Repo";
int i,j;
char *ret;

	ret = strstr(str1,str2);

	if (ret==NULL)
		printf("Not found\n");
	else{
		for (i=0;i<strlen(str1);i++){
				if (str1[i]==*ret)
				j=i;
				}
		 printf("The substring is here :| %d| and after this adress sentences: %s \n",j+1,ret);
	}
return 0;
}
