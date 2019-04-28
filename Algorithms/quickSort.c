#include<stdio.h>
#include<stdlib.h>


int partition(int dizi[],int l,int h){							//Aslýnda bütün sýralama iþlemleri burada gerçekleþiyor.
	int pivot=dizi[l];											//low deðerini pivot olarak alýyoruz.
	int i=l;													//Dizinin baþýndan itibaren pivottan büyük eleman var mý diye bakýyorum.
	int j=h;													//Dizinin sonundan itibaren pivottan küçük eleman var mý diye bakýyorum.
	int tmp;					
	while(i<j){													//i<j olduðu sürece yapacaðým swapler devam etsin.
		while(dizi[i]<=pivot)									//Baþtan itibaren arama yapýyorum.
		i++;													//Pivottan büyük bulana kadar i=i+1
		while(dizi[j]>pivot)									//Sondan itibaren arama yapýyorum.
		j--;													//Pivottan küçük bulana kadar i=i-1
		
		if(i<j){												//Eðer i deðerim j deðerinden küçük ise swap.
			tmp=dizi[j];
			dizi[j]=dizi[i];
			dizi[i]=tmp;
		}
	}
	tmp=dizi[j];												//Eðer i deðeri j den büyük ise pivot deðeri ile j deðeri swap.
	dizi[j]=pivot;
	dizi[l]=tmp;
	return j;
	
}

void quickSort(int dizi[],int l,int h){
	if(l<h){
		int j=partition(dizi,l,h);								//Pivot deðerini belirliyorum.
		quickSort(dizi,l,j);									//Sonra pivotun sol tarafýný kendi arasýnda
		quickSort(dizi,j+1,h);									//ve sað tarafýný kendi arasýnda sýralýyor.
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
