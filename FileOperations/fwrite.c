#include<stdio.h>

int main(){

	FILE *fp;
	if((fp=fopen("Asaf.txt","r+"))==NULL)
		printf("Error to open Asaf.txt!");
	else{
	char buff[]="FWRITEisCooomingg!";	
	fwrite(buff,sizeof(char),20,fp);
	}

return 0;
}
