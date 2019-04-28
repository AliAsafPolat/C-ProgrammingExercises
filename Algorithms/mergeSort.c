#include<stdio.h>
#include<stdlib.h>

void Merge(int l,int h,int mid,int dizi[]){						//Bu fonksiyonum birle�tirme i�in kullan�lacakt�r.
	int i,j,k;													//i ilk dizinin indisini j ikinci dizinin indisini k ise birle�tirmeyi yapaca��m		
	i=l;														//dizinin indisini tutmaktad�r.
	j=mid+1;													//�kinci dizinin indisi mid+1 den ba�lamaktad�r.
	int *tmp=(int *)malloc(sizeof(int)*(h+1));					//�nce dizideki elemanlar� yeni bir diziye kopyalamam gerekecektir.
	
	for(k=l;k<=h;k++){	
	tmp[k]=dizi[k];												//Kopyalama i�lemi neden gerekli ��nk� as�l diziye hangi de�erin gelece�ini
	}															//bu kopyalanm�� dizinin i�erisinden bakaca��m.
	
	for(k=l;k<=h;k++){											//S�rayla as�l diziyi doldurmaya ba�l�yorum.
		
	if(i>mid){													//E�er i de�erim yani ilk diziyi tutan indis de�erim mid de�erine ula�m��sa
			dizi[k]=tmp[j];										//demek ki birinci dizideki t�m elemanlar� alm���md�r.
			j++;												//O zaman ikinci dizinin kalan s�ralanm�� elemanlar�n� tek tek koyabilirim.
		}else{
		if(j>h){												//E�er j de�erim yani ikinci diziyi tutan indis de�erim high de�erine yani
		dizi[k]=tmp[i];											//dizinin sonuna ula�m��sa demek ki ikinci diziyi bitirmi�im demektir.
			i++;												//birinci dizinin kalan s�ralanm�� elemanlar�n� koyabilirim.
		}else{
				if(tmp[j]<tmp[i]){								//E�er iki de�ere de hen�z ula�mam��sam dizilerin s�radaki elemanlar�n� kar��
				dizi[k]=tmp[j];									//la�t�r�yorum ve k���k olan� as�l diziye ekleyip indisini bir artt�r�yorum.
				j++;
			}else{
				dizi[k]=tmp[i];
				i++;
			}
		}
	}
}
}
void mergeSort(int dizi[],int l,int h){							//Bu k�s�m i�lemi divide yapma k�sm�d�r.
	if(l<h){													//low de�erim high de�erine e�it veya k���k olana kadar diziyi b�l�yorum.
		int mid=(l+h)/2;										//Mid de�erini ald�m
		mergeSort(dizi,l,mid);									//Ba�tan mide kadar b�ld�m.
		mergeSort(dizi,mid+1,h);								//Midden sona kadar b�ld�m.
		Merge(l,h,mid,dizi);									//En son t�m b�l�nm�� par�alar� birle�tirdim.
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
