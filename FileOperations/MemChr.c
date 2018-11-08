#include<stdio.h>
#include<string.h>

int main(){
	const char str[]="AliasafWas.Here";
	const char ch='s';
	char *ret;

	ret=memchr(str,ch,strlen(str));		//Search a char that defined 's' by me.After than point its memory adress..



	printf("String after |%c| is : |%s|\n",ch,ret);


return (0);


}
