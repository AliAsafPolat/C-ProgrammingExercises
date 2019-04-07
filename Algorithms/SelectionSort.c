#include<stdio.h>

//**SELECTÝON SORT**

void selectionSort(int dizi[],int boyut){
	int i,j,minidx,tmp;
	for(i=0;i<boyut-1;i++){
		minidx=i;							//En bastan baslayarak min elemanlari bulup getiriyor.
		for(j=i+1;j<=boyut-1;j++){
		if(dizi[j]<dizi[minidx])
		minidx=j;	
		}
		tmp=dizi[i];
		dizi[i]=dizi[minidx];
		dizi[minidx]=tmp;
		
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
	int dizi[5]={1,2,4,3,5};
	diziYazdir(dizi,5);
	selectionSort(dizi,5);
	diziYazdir(dizi,5);
	
	
	
	return 0;
}
