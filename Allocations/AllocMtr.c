#include <stdio.h>
#include <stdlib.h>
int main(){
	int **dizi;
	int n,m,i,j;
	
	printf("Satir sayisini belirleyiniz.");		//Sat�r say�s� al�nd�.
	scanf("%d",&n);
	
	printf("Sutun sayisini belirleyiniz.");		//S�tun say�s� al�nd�.
	scanf("%d",&m);
	
	dizi=(int**)malloc(n * sizeof(int *));
	
	if (dizi==NULL){
		printf("Can not allocate memory.");		//Sat�rlar olu�turuldu.
		return -1;
	}
	
	for (i=0;i<n;i++){
		dizi[i]=(int*)malloc(m*sizeof(int));
	}											//S�tunlar olu�turuldu.
	
	
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
	
	
	
