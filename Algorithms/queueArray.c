#include<stdio.h>
#define BOYUT 10

void menu(){
	printf("Yapmak istediðiniz islemi seciniz :\n1-Kuyruga ekle\n2-Kuyruktan al\n");
}

void kuyrukGoster(int dizi[],int indis){
	int i;
//	printf("\n\n%d\n\n",indis);
	printf("Kuyruk durumu : ");
	for(i=0;i<=indis;i++){
		printf("%d  ",dizi[i]);
	}
	printf("\n----------------------\n----------------------\n");
}

void kuyrugaEkle(int dizi[],int *indis,int deger){
	if(*indis==BOYUT-1){
	printf("Maximum kapasiteye ulasildi.\n");
	return ;
	}
	*indis=*indis+1;
	dizi[*indis]=deger;
}

int kuyruktanAl(int dizi[],int* indis){
	if(*indis==-1){
		printf("Hata! Kuyruk bos\n");
		return;
	}
	*indis=*indis-1;
	return dizi[*indis+1];
}

int main(){
	int i,secim,ekle;
	int dizi[BOYUT],doluindis=-1;
	while(1){
	
	menu();
	scanf("%d",&secim);
	
	switch(secim){
		case 1:
			printf("Eklemek istediginiz elemani giriniz :\n");
			scanf("%d",&ekle);
			kuyrugaEkle(dizi,&doluindis,ekle);
			kuyrukGoster(dizi,doluindis);
			break;
		case 2:
			ekle=kuyruktanAl(dizi,&doluindis);
			kuyrukGoster(dizi,doluindis);
			break;
		default:
			printf("Hatali secim!\n");		
			break;
			
	}
}
	
	return 0;
}
