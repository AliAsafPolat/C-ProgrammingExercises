#include<stdio.h>
int main(){

	FILE *fp;

	if((fp=fopen("Asaf.txt","r+"))==NULL)
		printf("Error to open Asaf.txt\n");
	else{
		char buff[25];
	fseek(fp,sizeof(char)*4,SEEK_SET);
	fread(buff,sizeof(char)*4,3,fp);
	
	printf("%s",buff);
	}


return 0;
}
