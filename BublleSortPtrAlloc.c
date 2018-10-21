#include<stdio.h>


void BubbleSort(int *ptr, int size){
int i,j,tmp;

for (i = 0; i < size-1; i++){
	for(j = 0 ;j < size-i-1; j++){
		if (ptr[j]  >  ptr[j+1]){
			tmp = ptr[j];
			ptr[j] = ptr[j+1];
			ptr[j+1] = tmp;
			
		}
		
	}
}
}





int main() {
	int n,i,j;
	int *dizi;
	
	printf("Dizi boyutunu giriniz:  ");
	scanf("%d",&n);
	
	dizi=(int*)malloc(n*sizeof(int));
	
	
	printf("Dizi elemanlarini giriniz:\n");
	for (i = 0 ;i < n; i++){
		printf("\n %d inci elemani giriniz:	",i+1);
		scanf("%d",&dizi[i]);
		
	}
	
	BubbleSort(dizi,n);
	
	
	for (i = 0; i < n; i++)
		printf(" %d \t",dizi[i]);
	
	
	return 0;
}
