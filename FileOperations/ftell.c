#include<stdio.h>

int main(){

	FILE *fp;
	if((fp=fopen("Asaf.txt","r+"))==NULL)
		printf("Error to open Asaf.txt\n");
	else{
	char buff[25];
	int addr;
	fseek(fp,sizeof(char)*4,SEEK_SET);
	addr=ftell(fp);
	fread(buff,sizeof(char)*4,3,fp);
	printf("This sentence[%s] starts from :* %dth * order to beginning of text \n",buff,addr);
	}


return 0;
}
