#include<stdio.h>

//**SELECTÝON SORT**

void bubbleSort(int dizi[],int boyut){
	int i,j,tmp;
	
	for(i=0;i<boyut-1;i++){
		for(j=0;j<boyut-i-1;j++){
			if(dizi[j]>dizi[j+1]){
		tmp=dizi[j];
		dizi[j]=dizi[j+1];
		dizi[j+1]=tmp;		
			}
		}
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
	int dizi[5]={1,2,4,9,5};
	diziYazdir(dizi,5);
	bubbleSort(dizi,5);
	diziYazdir(dizi,5);
	
	
	
	return 0;
}
