#include<stdio.h>

int main(){
	
	int i,j,n,m;
	int *mtr;
	
	printf("Enter number of row ");
	scanf("%d",&n);
	
	printf("Enter number of column ");
	scanf("%d",&m);
	
	mtr=(int*)malloc(n*m*sizeof(int));
	
	if(mtr == NULL)  {
		printf("Can not allocate memory for the array...\n");
		return -1;
	}
	
	for (i=0;i<n;i++){
		printf("Enter values:\n");
		for (j=0;j<m;j++){
			scanf("%d",(mtr+i*m+j));
			
		}
	}
	for (i=0;i<n;i++){
		for (j=0;j<m;j++)
			printf("%d \t",*(mtr+i*m+j));
					
		printf("\n");
	}
	
	
	
	
	
	return 0;
}
