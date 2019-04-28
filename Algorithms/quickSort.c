#include<stdio.h>
#include<stdlib.h>


int partition(int dizi[],int l,int h){							//Asl�nda b�t�n s�ralama i�lemleri burada ger�ekle�iyor.
	int pivot=dizi[l];											//low de�erini pivot olarak al�yoruz.
	int i=l;													//Dizinin ba��ndan itibaren pivottan b�y�k eleman var m� diye bak�yorum.
	int j=h;													//Dizinin sonundan itibaren pivottan k���k eleman var m� diye bak�yorum.
	int tmp;					
	while(i<j){													//i<j oldu�u s�rece yapaca��m swapler devam etsin.
		while(dizi[i]<=pivot)									//Ba�tan itibaren arama yap�yorum.
		i++;													//Pivottan b�y�k bulana kadar i=i+1
		while(dizi[j]>pivot)									//Sondan itibaren arama yap�yorum.
		j--;													//Pivottan k���k bulana kadar i=i-1
		
		if(i<j){												//E�er i de�erim j de�erinden k���k ise swap.
			tmp=dizi[j];
			dizi[j]=dizi[i];
			dizi[i]=tmp;
		}
	}
	tmp=dizi[j];												//E�er i de�eri j den b�y�k ise pivot de�eri ile j de�eri swap.
	dizi[j]=pivot;
	dizi[l]=tmp;
	return j;
	
}

void quickSort(int dizi[],int l,int h){
	if(l<h){
		int j=partition(dizi,l,h);								//Pivot de�erini belirliyorum.
		quickSort(dizi,l,j);									//Sonra pivotun sol taraf�n� kendi aras�nda
		quickSort(dizi,j+1,h);									//ve sa� taraf�n� kendi aras�nda s�ral�yor.
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
	
	quickSort(dizi,0,5);
	printf("\n");
	diziYazdir(dizi,6);
		
	
	return 0;
}
