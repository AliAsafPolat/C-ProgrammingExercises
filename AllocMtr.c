#include <stdio.h>
#include <stdlib.h>
int main(){
	int **dizi;
	int n,m,i,j;
	
	printf("Satir sayisini belirleyiniz.");		//Satýr sayýsý alýndý.
	scanf("%d",&n);
	
	printf("Sutun sayisini belirleyiniz.");		//Sütun sayýsý alýndý.
	scanf("%d",&m);
	
	dizi=(int**)malloc(n * sizeof(int *));
	
	if (dizi==NULL){
		printf("Can not allocate memory.");		//Satýrlar oluþturuldu.
		return -1;
	}
	
	for (i=0;i<n;i++){
		dizi[i]=(int*)malloc(m*sizeof(int));
	}											//Sütunlar oluþturuldu.
	
	
		for (i=0;i<n;i++){
			printf("Degerleri belirleyiniz: \n");
			
			for(j=0;j<m;j++){
				scanf("%d",&dizi[i][j]);
				
			} 
			
			
		}
	
	
	
		for (i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%3d",dizi[i][j]);
				
			} 
	printf("\n");
	}
	return 0;
	
}
	
	
	
