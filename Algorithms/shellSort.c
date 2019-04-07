#include<stdio.h>


void shellSort(int dizi[],int boyut){
	int i,j,tmp;
	int h=1;
	while(h<boyut/2)
	h=h*2+1;												//Burada baþlangýç için bir geniþlik üretiyoruz tamamen opsiyonel
	
	while(h>=1){											//Geniþliðim 1 olduðunda insertion sorta geçmiþ olacaðým.
		for(i=h;i<boyut;i++){								//Bakýldýðýnda bubble sort gibi görülebilir fakat sadece yanýndakiyle karþýlaþtýrýp býrakmýyor.
			for(j=i;j>=0&&dizi[j]<dizi[j-h];j=j-h){			//Yanýndakinden küçüksen yer deðiþtiriyorsun sonra tekrar yanýndakine bakýyorsun ta ki solundakinden
			tmp=dizi[j];									//büyük olana kadar.
			dizi[j]=dizi[j-h];								//Eðer verilen geniþlik deðeri kadar uzaklýðýndaki elemandan küçüksen yer deðiþtirme iþlemi
			dizi[j-h]=tmp;									//gerçekleþir.
			}
		}
		h=h/2;												//Geniþliðimi her turdan sonra deðiþtiriyorum.
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
