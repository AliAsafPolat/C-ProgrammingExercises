#include<stdio.h>
int main(){
	FILE *fp;
char buff[15];
	if((fp=fopen("Asaf.txt","r+"))==NULL)
	printf("Error to open Asaf.txt\n");
	else{
	fgets(buff,15,fp); // 15 is an integer that show us how many char gonna read.
	printf("%s",buff);
	
	}


return 0;
}
