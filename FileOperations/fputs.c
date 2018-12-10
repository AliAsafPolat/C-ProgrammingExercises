#include<stdio.h>

int main(){

	FILE *fp;
	if((fp=fopen("Asaf.txt","w"))==NULL)
		printf("Error to open Asaf.txt\n");
	//else{
	char buff[30]="ThisSentenceIsAppended";	
	fputs("Sentence is coooming!",fp);
	fclose(fp);
	

return 0;
}
