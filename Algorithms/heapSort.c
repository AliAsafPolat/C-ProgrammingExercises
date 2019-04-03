#include<stdio.h>

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

void heapSort(int dizi[],int boyut){			//Bu fonksiyonun mantýðý iþte sýralama yapmaktýr.
	int i,tmp,boyuthold;
	buildMaxHeap(dizi,boyut);					//Görüldüðü gibi önce maxHeap haline getirildi.Ondan sonra sort kýsmýna geçildi.
	for(i=boyut-1;i>1;i--){						//Yapýlmak istenen her adýmda max eleman en büyük göze konuyor ve dizinin boyutu bir azaltýlýyor.
		tmp=dizi[0];							//En büyük indisten baþlanýyor ta ki ilk elemana kadar gidiyor.
		dizi[0]=dizi[i];						//Buradaki for döngüsünde dikkat edilmesi gereken bir nokta var burada bitiþi i>0 yapsaydýk son 
		dizi[i]=tmp;							//Kontrolde büyük olan baþa geçecekti.
		maxHeapify(dizi,0,i-1);					//En sonda max ile min i yer deðiþtirdiðimiz için aslýnda minimum baþta kaldý.
	}
	
}


void diziYazdir(int dizi[],int boyut){			//Burada sadece dizi yazdýrýyoruz.
	int i;
	printf("Dizi : \n");
	for(i=0;i<boyut;i++){
		printf("%d ",dizi[i]);
	}
	printf("\n");
	
}

int main(){
	int dizi[6]={2,8,5,3,4,1};
	printf("Siralamadan once : \n");
	diziYazdir(dizi,6);
	heapSort(dizi,6);
	printf("Siralamadan sonra : \n");
	diziYazdir(dizi,6);
	
	
	
	
	return 0;
}
