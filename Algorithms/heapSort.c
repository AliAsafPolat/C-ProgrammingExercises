#include<stdio.h>

void maxHeapify(int dizi[],int indis,int boyut){
	int tmp,left,right,largest;
	left=2*indis+1;							//Dizi indislerinin sıfırdan başladığı düşünülerek sol ayak 2*i+1 sag 2*i+2 de dedik.
	right=2*indis+2;
									//Öncelikle dizinin bize sıralı verildiğini düşünüyoruz yani alttaki elemanlar parentlardan büyük olamaz
	if(left<boyut&&dizi[left]>dizi[indis])				//Heapify dediğimiz olay diziye bir eleman geldiği zaman onu dizinin sonuna ekliyoruz fakat parentlarıyla
	largest=left;							//Arasında kim daha büyük bunun kontrolünü yapmamız gerekiyor.
	else								//Bunu da sırayla baka baka yer değiştirerek çözüyoruz.
	largest=indis;
	
	if(right<boyut&&dizi[right]>dizi[largest])			//Bu fonksiyonda dizide max olan parent olacak şekilde ayarlandığı varsayılıyor.
	largest=right;
	
	if (largest!=indis){						//Largest olan indise eşit değilse değiştirme işlemlerini yapabiliriz.
		tmp=dizi[indis];					
		dizi[indis]=dizi[largest];
		dizi[largest]=tmp;
		maxHeapify(dizi,largest,boyut);				//Yer değiştirilme yapıldıktan sonra bu eleman diğerlerinden de küçük mü bunun kontrolü sağlanmalı.
	}
}

void buildMaxHeap(int dizi[],int boyut){				//Bu fonksiyonun mantığı verilen diziyi veya heap ağacını, dizinin son gözünden baslayarak sıralaması.
	int i;								//Eleman geldikçe child nodelarla kendini karsilastiriyor ve büyük olanı parent yapıyor.
									//boyut/2 den başlamasının nedeni ise yaprakların kendini karşılaştıracağı nodeların olmamasıdır.
	for(i=boyut/2;i>=0;i--){					//Boyut/2 den başlayıp roota kadar üstleri karşılaştırıyor büyük olanı yukarı atıyor.
		maxHeapify(dizi,i,boyut);				//maxHeapify fonksiyonunun içine girildiğinde görülecektir ki değişim olduğu zaman küçük olan eleman kendi
	}								//aşağısındakilerle de sonradan karşılaştırılıyor.
	
}

void heapSort(int dizi[],int boyut){					//Bu fonksiyonun mantığı işte sıralama yapmaktır.
	int i,tmp,boyuthold;
	buildMaxHeap(dizi,boyut);					//Görüldüğü gibi önce maxHeap haline getirildi.Ondan sonra sort kısmına geçildi.
	for(i=boyut-1;i>1;i--){						//Yapılmak istenen her adımda max eleman en büyük göze konuyor ve dizinin boyutu bir azaltılıyor.
		tmp=dizi[0];						//En büyük indisten başlanıyor ta ki ilk elemana kadar gidiyor.
		dizi[0]=dizi[i];					//Buradaki for döngüsünde dikkat edilmesi gereken bir nokta var burada bitişi i>0 yapsaydık son 
		dizi[i]=tmp;						//Kontrolde büyük olan başa geçecekti.
		maxHeapify(dizi,0,i-1);					//En sonda max ile min i yer değiştirdiğimiz için aslında minimum başta kaldı.
	}
	
}


void diziYazdir(int dizi[],int boyut){					//Burada sadece dizi yazdırıyoruz.
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
