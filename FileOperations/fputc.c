#include<stdio.h>

int main(){

	FILE *fp;
char ch;
	if((fp=fopen("Asaf.txt","a+"))==NULL)
	printf("Error to open Asaf.txt\n");
	else{
	printf("Enter a char that you want to put in text.\n");
	scanf("%c",&ch);
	
	fputc(ch,fp);
	}	


return 0;
}
