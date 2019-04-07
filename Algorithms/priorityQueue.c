#include<stdio.h>

//**Priority Queue**

void maxHeapify(int dizi[],int indis,int boyut){
	int tmp,left,right,largest;
	left=2*indis+1;							//Dizi indislerinin s�f�rdan ba�lad��� d���n�lerek sol ayak 2*i+1 sag 2*i+2 de dedik.
	right=2*indis+2;
											//�ncelikle dizinin bize s�ral� verildi�ini d���n�yoruz yani alttaki elemanlar parentlardan b�y�k olamaz
	if(left<boyut&&dizi[left]>dizi[indis])	//Heapify dedi�imiz olay diziye bir eleman geldi�i zaman onu dizinin sonuna ekliyoruz fakat parentlar�yla
	largest=left;							//Aras�nda kim daha b�y�k bunun kontrol�n� yapmam�z gerekiyor.
	else									//Bunu da s�rayla baka baka yer de�i�tirerek ��z�yoruz.
	largest=indis;
	
	if(right<boyut&&dizi[right]>dizi[largest])	//Bu fonksiyonda dizide max olan parent olacak �ekilde ayarland��� varsay�l�yor.
	largest=right;
	
	if (largest!=indis){					//Largest olan indise e�it de�ilse de�i�tirme i�lemlerini yapabiliriz.
		tmp=dizi[indis];					
		dizi[indis]=dizi[largest];
		dizi[largest]=tmp;
		maxHeapify(dizi,largest,boyut);		//Yer de�i�tirilme yap�ld�ktan sonra bu eleman di�erlerinden de k���k m� bunun kontrol� sa�lanmal�.
	}
}
	

void buildMaxHeap(int dizi[],int boyut){	//Bu fonksiyonun mant��� verilen diziyi veya heap a�ac�n�, dizinin son g�z�nden baslayarak s�ralamas�.
	int i;									//Eleman geldik�e child nodelarla kendini karsilastiriyor ve b�y�k olan� parent yap�yor.
											//boyut/2 den ba�lamas�n�n nedeni ise yapraklar�n kendini kar��la�t�raca�� nodelar�n olmamas�d�r.
	for(i=boyut/2;i>=0;i--){				//Boyut/2 den ba�lay�p roota kadar �stleri kar��la�t�r�yor b�y�k olan� yukar� at�yor.
		maxHeapify(dizi,i,boyut);			//maxHeapify fonksiyonunun i�ine girildi�inde g�r�lecektir ki de�i�im oldu�u zaman k���k olan eleman kendi
	}										//a�a��s�ndakilerle de sonradan kar��la�t�r�l�yor.
	
}
int siradanAl(int dizi[],int boyut){
	int max;
	buildMaxHeap(dizi,boyut);				//�nce diziyi max heap haline getiriyorum.
	if(boyut>=1){							//E�er dizinin boyutu 1 den k���kse alacak bir �ey yoktur demektir.
		max=dizi[0];						//Dizi max heap haline getirdikten sonra max eleman 0. g�zdedir demektir.
		dizi[0]=dizi[boyut-1];				//Max � �ektikten sonra son eleman� yani en k���k eleman� ba�a al�yorum
		maxHeapify(dizi,0,boyut);			//ve tekrardan onu maxHeapify ile haketti�i yere yolluyorum.
		buildMaxHeap(dizi,boyut);
		return max;							//S�radan ald���m� d�nd�r�yorum.
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
if(dizi[indis]<yeniDeger){					//E�er gelen de�er i�indeki de�erden k���kse i�lem yap�lmayacak.
dizi[indis]=yeniDeger;						//De�ilse atama i�lemi ger�ekle�tiriliyor.
printf("Yeni deger eklendi : \n");
diziYazdir(dizi,boyut);					
buildMaxHeap(dizi,boyut);					//Atama ger�ekle�tikten sonra a�ac�m� tekrardan d�zenliyorum.	
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
