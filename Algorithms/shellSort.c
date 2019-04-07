#include<stdio.h>


void shellSort(int dizi[],int boyut){
	int i,j,tmp;
	int h=1;
	while(h<boyut/2)
	h=h*2+1;								//Burada başlangıç için bir genişlik üretiyoruz tamamen opsiyonel
	
	while(h>=1){								//Genişliğim 1 olduğunda insertion sorta geçmiş olacağım.
		for(i=h;i<boyut;i++){						//Bakıldığında bubble sort gibi görülebilir fakat sadece yanındakiyle karşılaştırıp bırakmıyor.
			for(j=i;j>=0&&dizi[j]<dizi[j-h];j=j-h){			//Yanındakinden küçüksen yer değiştiriyorsun sonra tekrar yanındakine bakıyorsun ta ki solundakinden
			tmp=dizi[j];						//büyük olana kadar.
			dizi[j]=dizi[j-h];					//Eğer verilen genişlik değeri kadar uzaklığındaki elemandan küçüksen yer değiştirme işlemi
			dizi[j-h]=tmp;						//gerçekleşir.
			}
		}
		h=h/2;								//Genişliğimi her turdan sonra değiştiriyorum.
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
