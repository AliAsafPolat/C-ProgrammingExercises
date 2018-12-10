#include<stdio.h>

int main(){

	FILE *fp;
char buff[15];
	if((fp=fopen("Asaf.txt","r+"))==NULL){
	printf("Error to opening: Asaf.txt\n");
	}
	else{
	fscanf(fp,"%s",buff);		//it scans just first word in the text.

	}
	printf("%s\n",buff);

return 0;
}
