#include<stdio.h>
#define MAX 5
typedef enum {false,true} boolean;
int front=-1;
int rear=-1;
int size=-1;


void menu(){
	printf("Yapmak istediginiz islemi seciniz : \n1-Ekle\n2-Cikar\n");

}

boolean isEmpty(){
	if (size==-1)
	return true;
	else return false;
	
}

boolean isFull(){
	if(size==MAX)
	return true;
	else return false;
}

void diziEkle(int dizi[],int val){
	if(!isFull()){
	if(size<0){
		dizi[0]=val;
		front=rear=0;
		size=1;
	}else if(rear+1==MAX){
		rear=0;
		dizi[0]=val;
		size++;
	}else{
		rear++;
		dizi[rear]=val;
		size++;
	}
	
}else
		printf("Dizi suan doludur.\n");

}

int diziSil(int dizi[]){
	int ret;
	if(isEmpty()){
		printf("Dizi suanda bostur.\n");
		return;
	}else{
		ret=dizi[front];
		front++;
		
		if(front==MAX)
		front=0;
		size--;
		return ret;
	}
	
	
	
}


void kuyrukYazdir(int dizi[]){
	int i;
	
	if(size!=-1){
	
	for(i=front;i<=rear;i++){
		printf("%d ",dizi[i]);
	}
	printf("\n\n");}
	else{printf("Dizi suanda bos agacim\n");
	}
}

int main(){
	
	int dizi[MAX];
int islem,ekle,al;
while(1){

menu();
scanf("%d",&islem);
switch(islem){
	case 1:
		printf("Kuyruga eklemek istediginiz elemani giriniz.");
		scanf("%d",&ekle);
		diziEkle(dizi,ekle);
		printf("Kuyrugun durumu : \n");
		kuyrukYazdir(dizi);
		break;
	case 2:
		al=diziSil(dizi);
		printf("Alinan eleman : %d",al);
		printf("\nKuyrugun durumu : \n");
		kuyrukYazdir(dizi);
		break;
	default:
		printf("Hatali secim");		
}
}

	
	
	
	return 0;
}
