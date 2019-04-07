#include<stdio.h>

//**Priority Queue**

void maxHeapify(int dizi[],int indis,int boyut){
	int tmp,left,right,largest;
	left=2*indis+1;							//Dizi indislerinin sýfýrdan baþladýðý düþünülerek sol ayak 2*i+1 sag 2*i+2 de dedik.
	right=2*indis+2;
											//Öncelikle dizinin bize sýralý verildiðini düþünüyoruz yani alttaki elemanlar parentlardan büyük olamaz
	if(left<boyut&&dizi[left]>dizi[indis])	//Heapify dediðimiz olay diziye bir eleman geldiði zaman onu dizinin sonuna ekliyoruz fakat parentlarýyla
	largest=left;							//Arasýnda kim daha büyük bunun kontrolünü yapmamýz gerekiyor.
	else									//Bunu da sýrayla baka baka yer deðiþtirerek çözüyoruz.
	largest=indis;
	
	if(right<boyut&&dizi[right]>dizi[largest])	//Bu fonksiyonda dizide max olan parent olacak þekilde ayarlandýðý varsayýlýyor.
	largest=right;
	
	if (largest!=indis){					//Largest olan indise eþit deðilse deðiþtirme iþlemlerini yapabiliriz.
		tmp=dizi[indis];					
		dizi[indis]=dizi[largest];
		dizi[largest]=tmp;
		maxHeapify(dizi,largest,boyut);		//Yer deðiþtirilme yapýldýktan sonra bu eleman diðerlerinden de küçük mü bunun kontrolü saðlanmalý.
	}
}
	

void buildMaxHeap(int dizi[],int boyut){	//Bu fonksiyonun mantýðý verilen diziyi veya heap aðacýný, dizinin son gözünden baslayarak sýralamasý.
	int i;									//Eleman geldikçe child nodelarla kendini karsilastiriyor ve büyük olaný parent yapýyor.
											//boyut/2 den baþlamasýnýn nedeni ise yapraklarýn kendini karþýlaþtýracaðý nodelarýn olmamasýdýr.
	for(i=boyut/2;i>=0;i--){				//Boyut/2 den baþlayýp roota kadar üstleri karþýlaþtýrýyor büyük olaný yukarý atýyor.
		maxHeapify(dizi,i,boyut);			//maxHeapify fonksiyonunun içine girildiðinde görülecektir ki deðiþim olduðu zaman küçük olan eleman kendi
	}										//aþaðýsýndakilerle de sonradan karþýlaþtýrýlýyor.
	
}
int siradanAl(int dizi[],int boyut){
	int max;
	buildMaxHeap(dizi,boyut);				//Önce diziyi max heap haline getiriyorum.
	if(boyut>=1){							//Eðer dizinin boyutu 1 den küçükse alacak bir þey yoktur demektir.
		max=dizi[0];						//Dizi max heap haline getirdikten sonra max eleman 0. gözdedir demektir.
		dizi[0]=dizi[boyut-1];				//Max ý çektikten sonra son elemaný yani en küçük elemaný baþa alýyorum
		maxHeapify(dizi,0,boyut);			//ve tekrardan onu maxHeapify ile hakettiði yere yolluyorum.
		buildMaxHeap(dizi,boyut);
		return max;							//Sýradan aldýðýmý döndürüyorum.
	}
	 return -1;								//Hata varsa -1
}
	


void diziYazdir(int dizi[],int boyut){
	int i;
	printf("Dizi : \n");
	for(i=0;i<boyut;i++){
		printf("%d  ",dizi[i]);
	}
	printf("\n");
	
}
void increaseKey(int dizi[],int indis,int yeniDeger,int boyut){

int i;
if(dizi[indis]<yeniDeger){					//Eðer gelen deðer içindeki deðerden küçükse iþlem yapýlmayacak.
dizi[indis]=yeniDeger;						//Deðilse atama iþlemi gerçekleþtiriliyor.
printf("Yeni deger eklendi : \n");
diziYazdir(dizi,boyut);					
buildMaxHeap(dizi,boyut);					//Atama gerçekleþtikten sonra aðacýmý tekrardan düzenliyorum.	
printf("Build Max Heap uygunlandi : \n");
diziYazdir(dizi,boyut);
	
}	
	
}


int main(){
	int max;
	int dizi[6]={2,8,5,3,4,1};
	int boyut=6;
	printf("Siralamadan once : \n");
	diziYazdir(dizi,boyut);
	max=siradanAl(dizi,boyut);
	boyut--;
	printf("Siradan alindi :%d \n",max);
	diziYazdir(dizi,boyut);
	
	increaseKey(dizi,4,10,boyut);
	max=siradanAl(dizi,boyut);
	boyut--;
	printf("Siradan alindi :%d \n",max);
	diziYazdir(dizi,boyut);
	
	
	
	return 0;
}
