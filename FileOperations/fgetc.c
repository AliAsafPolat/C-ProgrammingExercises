#include<stdio.h>


int main(){

char ch;
	FILE *fp;
	if((fp=fopen("Asaf.txt","r+"))==NULL){
	printf("Error to open Asaf.txt\n");

	}else{
	while(!feof(fp)){
	ch=fgetc(fp);
	printf("%c",ch);
	}
	
	}



return 0;
}
