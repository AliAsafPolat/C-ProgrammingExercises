#include<stdio.h>
int main(){

	FILE *fp;
	if((fp=fopen("Asaf.txt","r+"))==NULL){
		printf("Error to open Asaf.txt\n");
	}else{
	char buff[15];
	fread(buff,sizeof(char)*3,5,fp);
	
	
	printf("%s",buff);
	}
return 0;
}
