#include<stdio.h>


void shellSort(int dizi[],int boyut){
	int i,j,tmp;
	int h=1;
	while(h<boyut/2)
	h=h*2+1;												//Burada ba�lang�� i�in bir geni�lik �retiyoruz tamamen opsiyonel
	
	while(h>=1){											//Geni�li�im 1 oldu�unda insertion sorta ge�mi� olaca��m.
		for(i=h;i<boyut;i++){								//Bak�ld���nda bubble sort gibi g�r�lebilir fakat sadece yan�ndakiyle kar��la�t�r�p b�rakm�yor.
			for(j=i;j>=0&&dizi[j]<dizi[j-h];j=j-h){			//Yan�ndakinden k���ksen yer de�i�tiriyorsun sonra tekrar yan�ndakine bak�yorsun ta ki solundakinden
			tmp=dizi[j];									//b�y�k olana kadar.
			dizi[j]=dizi[j-h];								//E�er verilen geni�lik de�eri kadar uzakl���ndaki elemandan k���ksen yer de�i�tirme i�lemi
			dizi[j-h]=tmp;									//ger�ekle�ir.
			}
		}
		h=h/2;												//Geni�li�imi her turdan sonra de�i�tiriyorum.
	}
	
}

void diziYazdir(int dizi[],int boyut){
	int i;
	printf("Dizi : \n");
	for(i=0;i<boyut;i++){
		printf("%d  ",dizi[i]);
	}
	printf("\n");
	
}

int main(){
	int dizi[9]={1,2,4,9,5,15,8,4,6};
	diziYazdir(dizi,9);
	shellSort(dizi,9);
	diziYazdir(dizi,9);
	
	
	
	return 0;
}
