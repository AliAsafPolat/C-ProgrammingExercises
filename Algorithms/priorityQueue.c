#include<stdio.h>

//**Priority Queue**

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
int siradanAl(int dizi[],int boyut){
	int max;
	buildMaxHeap(dizi,boyut);					//Önce diziyi max heap haline getiriyorum.
	if(boyut>=1){							//Eğer dizinin boyutu 1 den küçükse alacak bir şey yoktur demektir.
		max=dizi[0];						//Dizi max heap haline getirdikten sonra max eleman 0. gözdedir demektir.
		dizi[0]=dizi[boyut-1];					//Max ı çektikten sonra son elemanı yani en küçük elemanı başa alıyorum
		maxHeapify(dizi,0,boyut);				//ve tekrardan onu maxHeapify ile hakettiği yere yolluyorum.
		buildMaxHeap(dizi,boyut);
		return max;						//Sıradan aldığımı döndürüyorum.
	}
	 return -1;							//Hata varsa -1
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
if(dizi[indis]<yeniDeger){					//Eğer gelen değer içindeki değerden küçükse işlem yapılmayacak.
dizi[indis]=yeniDeger;						//Değilse atama işlemi gerçekleştiriliyor.
printf("Yeni deger eklendi : \n");
diziYazdir(dizi,boyut);					
buildMaxHeap(dizi,boyut);					//Atama gerçekleştikten sonra ağacımı tekrardan düzenliyorum.	
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
