#include<stdio.h>

int main(){
	
	int n,i,j;
	int *dizi;
	
	printf("Dizinin boyutunu giriniz: ");
	scanf("%d",&n);
	
	dizi=(int *)malloc(n*sizeof(int));
	for (i=0;i<n;i++){
		printf("%d inci elemani giriniz :\n",i+1);
		scanf("%d",&dizi[i]);
	}
	
	printf("Dizinin normal hali :\n");
	for(i=0;i<n;i++)
	printf("%d 	",dizi[i]);
	
	
	for (j=1;j<n;j++){
		int key=dizi[j];
		i=j-1;
		while(i>=0&&dizi[i]>key){
			dizi[i+1]=dizi[i];
			i=i-1;
			dizi[i+1]=key;
		}
	}
	printf("\nDizinin siralanmis hali :\n");
	for(i=0;i<n;i++){
		printf("%d	",dizi[i]);
	}
	return 0;
}
