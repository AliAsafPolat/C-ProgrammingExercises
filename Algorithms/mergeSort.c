#include<stdio.h>
#include<stdlib.h>

void Merge(int l,int h,int mid,int dizi[]){						//Bu fonksiyonum birleþtirme için kullanýlacaktýr.
	int i,j,k;													//i ilk dizinin indisini j ikinci dizinin indisini k ise birleþtirmeyi yapacaðým		
	i=l;														//dizinin indisini tutmaktadýr.
	j=mid+1;													//Ýkinci dizinin indisi mid+1 den baþlamaktadýr.
	int *tmp=(int *)malloc(sizeof(int)*(h+1));					//Önce dizideki elemanlarý yeni bir diziye kopyalamam gerekecektir.
	
	for(k=l;k<=h;k++){	
	tmp[k]=dizi[k];												//Kopyalama iþlemi neden gerekli çünkü asýl diziye hangi deðerin geleceðini
	}															//bu kopyalanmýþ dizinin içerisinden bakacaðým.
	
	for(k=l;k<=h;k++){											//Sýrayla asýl diziyi doldurmaya baþlýyorum.
		
	if(i>mid){													//Eðer i deðerim yani ilk diziyi tutan indis deðerim mid deðerine ulaþmýþsa
			dizi[k]=tmp[j];										//demek ki birinci dizideki tüm elemanlarý almýþýmdýr.
			j++;												//O zaman ikinci dizinin kalan sýralanmýþ elemanlarýný tek tek koyabilirim.
		}else{
		if(j>h){												//Eðer j deðerim yani ikinci diziyi tutan indis deðerim high deðerine yani
		dizi[k]=tmp[i];											//dizinin sonuna ulaþmýþsa demek ki ikinci diziyi bitirmiþim demektir.
			i++;												//birinci dizinin kalan sýralanmýþ elemanlarýný koyabilirim.
		}else{
				if(tmp[j]<tmp[i]){								//Eðer iki deðere de henüz ulaþmamýþsam dizilerin sýradaki elemanlarýný karþý
				dizi[k]=tmp[j];									//laþtýrýyorum ve küçük olaný asýl diziye ekleyip indisini bir arttýrýyorum.
				j++;
			}else{
				dizi[k]=tmp[i];
				i++;
			}
		}
	}
}
}
void mergeSort(int dizi[],int l,int h){							//Bu kýsým iþlemi divide yapma kýsmýdýr.
	if(l<h){													//low deðerim high deðerine eþit veya küçük olana kadar diziyi bölüyorum.
		int mid=(l+h)/2;										//Mid deðerini aldým
		mergeSort(dizi,l,mid);									//Baþtan mide kadar böldüm.
		mergeSort(dizi,mid+1,h);								//Midden sona kadar böldüm.
		Merge(l,h,mid,dizi);									//En son tüm bölünmüþ parçalarý birleþtirdim.
	}
}

void diziYazdir(int dizi[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",dizi[i]);
	}
}

int main(){
	int dizi[]={1,10,3,2,6,9};
	
	diziYazdir(dizi,6);
	
	mergeSort(dizi,0,5);
	printf("\n");
	diziYazdir(dizi,6);
	
	return 0;
}
