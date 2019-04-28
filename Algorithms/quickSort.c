#include<stdio.h>
#include<stdlib.h>


int partition(int dizi[],int l,int h){							//Aslında bütün sıralama işlemleri burada gerçekleşiyor.
	int pivot=dizi[l];								//low değerini pivot olarak alıyoruz.
	int i=l;									//Dizinin başından itibaren pivottan büyük eleman var mı diye bakıyorum.
	int j=h;									//Dizinin sonundan itibaren pivottan küçük eleman var mı diye bakıyorum.
	int tmp;					
	while(i<j){									//i<j olduğu sürece yapacağım swapler devam etsin.
		while(dizi[i]<=pivot)							//Baştan itibaren arama yapıyorum.
		i++;									//Pivottan büyük bulana kadar i=i+1
		while(dizi[j]>pivot)							//Sondan itibaren arama yapıyorum.
		j--;									//Pivottan küçük bulana kadar i=i-1
		
		if(i<j){								//Eğer i değerim j değerinden küçük ise swap.
			tmp=dizi[j];
			dizi[j]=dizi[i];
			dizi[i]=tmp;
		}
	}
	tmp=dizi[j];									//Eğer i değeri j den büyük ise pivot değeri ile j değeri swap.
	dizi[j]=pivot;
	dizi[l]=tmp;
	return j;
	
}

void quickSort(int dizi[],int l,int h){
	if(l<h){
		int j=partition(dizi,l,h);						//Pivot değerini belirliyorum.
		quickSort(dizi,l,j);							//Sonra pivotun sol tarafını kendi arasında
		quickSort(dizi,j+1,h);							//ve sağ tarafını kendi arasında sıralıyor.
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
