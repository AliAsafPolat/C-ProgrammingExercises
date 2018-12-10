#include<stdio.h>

int main(){

	FILE *fp;

	if((fp=fopen("Asaf.txt","w+"))==NULL)
		printf("Asaf.txt is not available.");
	else{
	
	fprintf(fp,"%s","It is my First Sentence Here.");	
	
	}



return 0;
}
