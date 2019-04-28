#include<stdio.h>
#include<stdlib.h>

void Merge(int l,int h,int mid,int dizi[]){						//Bu fonksiyonum birleştirme için kullanılacaktır.
	int i,j,k;									//i ilk dizinin indisini j ikinci dizinin indisini k ise birleştirmeyi yapacağım		
	i=l;										//dizinin indisini tutmaktadır.
	j=mid+1;									//İkinci dizinin indisi mid+1 den başlamaktadır.
	int *tmp=(int *)malloc(sizeof(int)*(h+1));					//Önce dizideki elemanları yeni bir diziye kopyalamam gerekecektir.
	
	for(k=l;k<=h;k++){	
	tmp[k]=dizi[k];									//Kopyalama işlemi neden gerekli çünkü asıl diziye hangi değerin geleceğini
	}										//bu kopyalanmış dizinin içerisinden bakacağım.
	
	for(k=l;k<=h;k++){								//Sırayla asıl diziyi doldurmaya başlıyorum.
		
	if(i>mid){									//Eğer i değerim yani ilk diziyi tutan indis değerim mid değerine ulaşmışsa
			dizi[k]=tmp[j];							//demek ki birinci dizideki tüm elemanları almışımdır.
			j++;								//O zaman ikinci dizinin kalan sıralanmış elemanlarını tek tek koyabilirim.
		}else{
		if(j>h){								//Eğer j değerim yani ikinci diziyi tutan indis değerim high değerine yani
		dizi[k]=tmp[i];								//dizinin sonuna ulaşmışsa demek ki ikinci diziyi bitirmişim demektir.
			i++;								//birinci dizinin kalan sıralanmış elemanlarını koyabilirim.
		}else{
				if(tmp[j]<tmp[i]){					//Eğer iki değere de henüz ulaşmamışsam dizilerin sıradaki elemanlarını karşı
				dizi[k]=tmp[j];						//laştırıyorum ve küçük olanı asıl diziye ekleyip indisini bir arttırıyorum.
				j++;
			}else{
				dizi[k]=tmp[i];
				i++;
			}
		}
	}
}
}
void mergeSort(int dizi[],int l,int h){							//Bu kısım işlemi divide yapma kısmıdır.
	if(l<h){									//low değerim high değerine eşit veya küçük olana kadar diziyi bölüyorum.
		int mid=(l+h)/2;							//Mid değerini aldım
		mergeSort(dizi,l,mid);							//Baştan mide kadar böldüm.
		mergeSort(dizi,mid+1,h);						//Midden sona kadar böldüm.
		Merge(l,h,mid,dizi);							//En son tüm bölünmüş parçaları birleştirdim.
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
