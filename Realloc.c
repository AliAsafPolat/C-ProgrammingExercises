#include <stdio.h>
int main(){
	
	int *dizi,n,i,j;
	
	printf("Dizi uzunlugunu belirleyiniz:\t");
	scanf("%d",&n);
	
	dizi=(int*)malloc(n*sizeof(int));
	
	if (dizi==NULL){
		printf("Can not allocate memory.\n");
		return -1;
	}
	
	printf("Dizinin elemanlarini belirleyiniz.\n");
	
	for (i=0;i<n;i++){
		scanf("%d",&dizi[i]);
			
	}
	
	dizi=(int*)realloc(dizi,(n+1)*sizeof(int));
	
	for (i=0;i<n+1;i++){
		printf("%d",dizi[i]);
			
	}
	
	
	
	return 0;
}
