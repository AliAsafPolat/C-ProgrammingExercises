#include<stdio.h>
int pattern_match(char *dizi1,char *dizi2){
	int i,n;
	
	for (i=0;i<strlen(dizi1);i++){
		for (n=0;(n<strlen(dizi2))&&((dizi2[n]==dizi1[n+i]));n++);
		
		if(n == strlen(dizi2))
			return 1;
	}
	
	return -1;
	
	
	
	
	
}



int main(){
	int n,m,i,j;
	char *dizi1,*dizi2;
	
	printf("Enter size of first array:"); scanf ("%d",&n); //size of first array =n
	printf("\nEnter size of second array:"); scanf ("%d",&m); // size of second array=m
	
	dizi1=(char*)malloc(n * sizeof(char));
	
	if(dizi1 == NULL)  {
		printf("Can not allocate memory for the string...\n");
		return -1;
	}	
	dizi2=(char*)malloc(m * sizeof(char));
	
	
	if(dizi1 == NULL)  {
		printf("Can not allocate memory for the string...\n");
		return -1;
	}	
	
	
	printf("\nEnter first str:"); scanf("%s",dizi1);
	printf("\nEnter second str:"); scanf("%s",dizi2);
	
	j=pattern_match(dizi1,dizi2);
	
	if (j==1)
	printf("\nIt contains.");
	else 
	printf("\nIt is not contained.");
	
	
	
	
	
	
	
	return 0;
}
