#include<stdio.h>

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

void heapSort(int dizi[],int boyut){			//Bu fonksiyonun mant��� i�te s�ralama yapmakt�r.
	int i,tmp,boyuthold;
	buildMaxHeap(dizi,boyut);					//G�r�ld��� gibi �nce maxHeap haline getirildi.Ondan sonra sort k�sm�na ge�ildi.
	for(i=boyut-1;i>1;i--){						//Yap�lmak istenen her ad�mda max eleman en b�y�k g�ze konuyor ve dizinin boyutu bir azalt�l�yor.
		tmp=dizi[0];							//En b�y�k indisten ba�lan�yor ta ki ilk elemana kadar gidiyor.
		dizi[0]=dizi[i];						//Buradaki for d�ng�s�nde dikkat edilmesi gereken bir nokta var burada biti�i i>0 yapsayd�k son 
		dizi[i]=tmp;							//Kontrolde b�y�k olan ba�a ge�ecekti.
		maxHeapify(dizi,0,i-1);					//En sonda max ile min i yer de�i�tirdi�imiz i�in asl�nda minimum ba�ta kald�.
	}
	
}


void diziYazdir(int dizi[],int boyut){			//Burada sadece dizi yazd�r�yoruz.
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
