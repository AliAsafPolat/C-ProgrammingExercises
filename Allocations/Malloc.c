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
	
	
	
	for (i=0;i<n;i++){
		printf("%2d",dizi[i]);
			
	}
	
	
	return 0;
}
