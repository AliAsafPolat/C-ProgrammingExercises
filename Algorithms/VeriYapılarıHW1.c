#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BOYUT 25
typedef enum { false, true } bool;

static int sayilar[BOYUT];						//Sayiları tutacağım yığın.
static char isaretler[BOYUT];						//İşaretleri tutacağım yığın.
static int isaretler_indis=-1,sayilar_indis=-1;				//İndisleri -1 den başlatıyorum.
	

bool isSayiEmpty(){
	if(sayilar_indis==-1){
		return true;
	}
	else return false;
}
//******************************************************************

bool isSayiFull(){
	if(sayilar_indis==BOYUT-1){			//Eger yigin max kapasiteye ulaşmışsa bir uyarı mesajı yollanacak.
		return true;
	}
	return false;
}
//******************************************************************

bool isIsaretEmpty(){
	if(isaretler_indis==-1){
		return true;
	}
	else return false;
}
//******************************************************************

bool isIsaretFull(){
	if(isaretler_indis==BOYUT-1){			//Eger yigin max kapasiteye ulaşmışsa bir uyarı mesajı yollanacak.
		return true;
	}
	return false;
}
//******************************************************************

void pushSayi(int a){
	if(!isSayiFull()){	
	sayilar_indis++;
	sayilar[sayilar_indis]=a;
}else{
	printf("Sayi yigini doludur!");
	return;
}

}
//******************************************************************

int popSayi(){							//Eger yigin suanda boş ise bir uyarı mesajı yollanacak.
	int sayi;
	if(isSayiEmpty()){
		printf("Yigin suan bostur!");
		return -1;
	}
	
	sayi=sayilar[sayilar_indis];
	--sayilar_indis;
	return sayi;
}
//******************************************************************

void pushIsaret(char ch){
	if(isIsaretFull()){				//Eger yigin max kapasiteye ulaşmışsa bir uyarı mesajı yollanacak.
		printf("Yigin max kapasiteye ulasti yükleme yapilamiyor!");
		return;
	}
	isaretler_indis++;
	isaretler[isaretler_indis]=ch;
	
	
}
//******************************************************************
char popIsaret(){
	char isaret;
	if(isIsaretEmpty()){				//Eger yigin suanda boş ise bir uyarı mesajı yollanacak.
		printf("Yigin suan bostur!");
		return ;
	}
	isaret=isaretler[isaretler_indis];
	isaretler_indis--;
	return isaret;
	
}
//******************************************************************
char peekIsaret(){
	if(!isIsaretEmpty())
	return isaretler[isaretler_indis];
	else{
	return;
		}
}

//******************************************************************
void sayiStackYazdir(){
	int k;
	printf("\n Sayilar Stack Durumu : ");
			for(k=0;k<=sayilar_indis;k++)
				printf(" %d ",sayilar[k]);
}
//******************************************************************
void isaretStackYazdir(){
	int k;
				printf("\n Isaretler Stack Durumu : ");
			for(k=0;k<=isaretler_indis;k++)
				printf(" %c ",isaretler[k]);
	printf("\n_________________________________________\n");
}
//******************************************************************
int main(){
	
	char islem[BOYUT],buff[5];			//buff stringten int değer dönüşümünde kullanılacaktır.
	int islem_length;				//Girilen işlemin string olarak uzunluğunu hesaplamak için kullanılacaktır.
	int i,sayi;					//i : döngü değişkeni, sayi Stringten int değerine dönüşümde int değerini tutan değişken olarak kullanılacak.
	char isaret;					//Yığından çekilen işareti tutmak için kullanılacak değişken
	int sayi1,sayi2;				//Yığın çekilecek 2 sayıyı tutmak için kullanılacak değişkenler.
	int sonuc;					//Çekilen 2 sayının işlemleri sonucu oluşacak sayıyı tutmak için kullanılacak değişken.
	
	printf("Islemi giriniz : ");
	scanf("%s",islem);
	islem_length=strlen(islem);			//İşlemin uzunluğu alındı.
	
	for(i=0;i<islem_length;i++){
	
		if(islem[i]>=48&&islem[i]<=57){
			int j=0;
			buff[j]=islem[i];
			j++;
			while(islem[i+1]>=48&&islem[i+1]<=57){  //İşlemde verilen sayının bir basamaklıdan daha fazla basamaklı olup olmadığının kontrolü.
			buff[j]=islem[i+1];
			i++;
			j++;
		}
		sayi=atoi(buff);			// Aldığım string değerini integer değere çeviriyorum
		pushSayi(sayi);				//Çevirilen integer değerini sayi stackine atıyorum.
		memset(buff, 0, 5);			//Buffer olarak kullandığım değeri içinde değer kalmasın diye sıfırlıyorum.
		sayiStackYazdir();			//Yazdırma işlemleri.
		isaretStackYazdir();	
		
				
	}else if(islem[i]=='('){
		pushIsaret(islem[i]);			//'(' gelirse direkt yığına atılıyor.
		sayiStackYazdir();			//Yazdirma işlemleri.
		isaretStackYazdir();	
		
	}else if(islem[i]=='*'){
		if(peekIsaret()=='*'||peekIsaret()=='/'){//Çarpma işleminde yığın içindeki eşit öncelikli terimlere bakılıyor.
			isaret=popIsaret();		//Eşit öncelikli ise işaret yığından çekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//İşaret '*' ise yığından terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//İşlem sonucu tekrardan yığına atılıyor.
			pushSayi(sonuc);
			pushIsaret('*');		//Eşit öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			
			}else {				//Gelen işaret '*' değilse '/' dir.
			sayi2=popSayi();		//Yığına son giren bölen, ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);		//İşlem sonucu tekrardan Sayı Yığınına atıldı.
			pushIsaret('*');		//Eşit öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			
			sayiStackYazdir();		//Yazdırma işlemleri.
			isaretStackYazdir();
			
			}
		}else if(peekIsaret()=='('){
			pushIsaret('*');		//Yığındaki işaret '(' ise işaret direkt yığına yerleştirilir.
		sayiStackYazdir();			//Yazdırma işlemleri.
		isaretStackYazdir();
		
		}else{
			pushIsaret('*');		//Çarpma işlemi işaret yığınına atıldı.	
		sayiStackYazdir();			//Yazdırma işlemleri.
		isaretStackYazdir();
		}

	}else if(islem[i]=='/'){//*************GELEN İŞLEM '/' İSE *******************
		if(peekIsaret()=='*'||peekIsaret()=='/'){//Bölme işleminde yığın içindeki eşit öncelikli terimlere bakılıyor.
			isaret=popIsaret();		//Eşit öncelikli ise işaret yığından çekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//İşaret '*' ise yığından terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//İşlem sonucu tekrardan yığına atılıyor.
			pushSayi(sonuc);
			pushIsaret('/');		//Eşit öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();		//Yazdırma işlemleri.
			isaretStackYazdir();	
			}else {				//Gelen işaret '*' değilse '/' dir.
			sayi2=popSayi();		//Yığına son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);		//İşlem sonucu tekrardan Sayı Yığınına atıldı.
			pushIsaret('/');		//Eşit öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();		//Yazdırma işlemleri
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='('){
			pushIsaret('/');		//Yığındaki işaret '(' ise doğrudan yığına atıyorum.	
			sayiStackYazdir();		//Yazdırma işlemleri.
		    isaretStackYazdir();
		}else{
		
		pushIsaret('/');			//Bölme işlemi işaret yığınına atıldı.
		sayiStackYazdir();			//Yazdırma işlemleri. 
		isaretStackYazdir();
	}
	} else if(islem[i]=='+'){	//************************GELEN İŞLEM '+' İSE********************************
		if(peekIsaret()=='*'||peekIsaret()=='/'){//Toplama işleminde yığın içindeki eşit ve öncelikli terimlere bakılıyor.
			isaret=popIsaret();		//Öncelikli ise işaret yığından çekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//İşaret '*' ise yığından terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//İşlem sonucu tekrardan yığına atılıyor.
			pushSayi(sonuc);
			pushIsaret('+');		//Öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();		//Yazdırma işlemleri.
			isaretStackYazdir();	
			}else {					//Gelen işaret '*' değilse '/' dir.
			sayi2=popSayi();			//Yığına son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//İşlem sonucu tekrardan Sayı Yığınına atıldı.
			pushIsaret('+');			//Öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();			//Yazdırma işlemleri
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='+'){			//Yığının tepesindeki işaret '+' ise çekiyorum
			popIsaret();				//Yığındaki işaret çekildi.
			sayi1=popSayi();			//Toplama işareti olduğundan yığındaki 2 terim çekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//Çekilen sayıların işlem sonucu tekrardan yığına atıldı.
			pushIsaret('+');			//Eşit öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();
		}else if(peekIsaret()=='-'){
			popIsaret();				//Yığından işaret çekildi.
			sayi2=popSayi();			//Yığına ilk giren sayı öncelikli olduğundan ters şekilde sayılar çekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Oluşan işlem sonucu tekrardan yığına atıldı.
			pushIsaret('+');			//Eşit öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();
		}
		else if(peekIsaret()=='('){
			pushIsaret('+');			//Yığındaki işaret '(' ise doğrudan yığına atıyorum.	
			sayiStackYazdir();			//Yazdırma işlemleri
			isaretStackYazdir();
		}else{
		pushIsaret('+');				//Toplama işlemi işaret yığınına atıldı.
		sayiStackYazdir();				//Yazdırma işlemleri
		isaretStackYazdir();
		}
	}else if(islem[i]=='-'){	//************************GELEN İŞLEM '-' İSE********************************
		if(peekIsaret()=='*'||peekIsaret()=='/'){//Toplama işleminde yığın içindeki eşit ve öncelikli terimlere bakılıyor.
			isaret=popIsaret();		//Öncelikli ise işaret yığından çekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//İşaret '*' ise yığından terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//İşlem sonucu tekrardan yığına atılıyor.
			pushSayi(sonuc);
			pushIsaret('-');		//Öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();		//Yazdırma işlemleri.
			isaretStackYazdir();
			}else {					//Gelen işaret '*' değilse '/' dir.
			sayi2=popSayi();			//Yığına son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//İşlem sonucu tekrardan Sayı Yığınına atıldı.
			pushIsaret('-');			//Öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='+'){			//Yığının tepesindeki işaret '+' ise çekiyorum
			popIsaret();				//Yığındaki işaret çekildi.
			sayi1=popSayi();			//Toplama işareti olduğundan yığındaki 2 terim çekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//Çekilen sayıların işlem sonucu tekrardan yığına atıldı.
			pushIsaret('-');			//Eşit öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();
		}else if(peekIsaret()=='-'){
			popIsaret();				//Yığından işaret çekildi.
			sayi2=popSayi();			//Yığına ilk giren sayı öncelikli olduğundan ters şekilde sayılar çekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Oluşan işlem sonucu tekrardan yığına atıldı.
			pushIsaret('-');			//Eşit öncelikli işlem yapıldıktan sonra gelen işaretim yığına atılıyor.
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();
		}
		else if(peekIsaret()=='('){
			pushIsaret('-');			//Yığındaki işaret '(' ise doğrudan yığına atıyorum.	
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();
		}else
		pushIsaret('-');				//Çıkarma işlemi işaret yığınına atıldı.
		sayiStackYazdir();				//Yazdırma işlemleri.
		isaretStackYazdir();
	}
	//**********************IŞARET ')' ISE******************************
	else if(islem[i]==')'){
		isaret=popIsaret();			//İlk işaret çekiliyor.
		while(isaret!='('){			//Gelen işaret '(' olmadığı sürece döngü devam ediyor.
			
			if(isaret=='*'){			
			sayi1=popSayi();		//İşaret '*' ise yığından terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//İşlem sonucu tekrardan yığına atılıyor.
			pushSayi(sonuc);
			sayiStackYazdir();		//Yazdırma işlemleri.
			isaretStackYazdir();	
			}else if(isaret=='/') {		//Gelen işaret '*' değilse '/' dir.
			sayi2=popSayi();		//Yığına son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);		//İşlem sonucu tekrardan Sayı Yığınına atıldı.
			sayiStackYazdir();		//Yazdırma işlemleri.
			isaretStackYazdir();	
			}
		else if(isaret=='+'){			//Yığının tepesindeki işaret '+' ise çekiyorum
			sayi1=popSayi();		//Toplama işareti olduğundan yığındaki 2 terim çekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);		//Çekilen sayıların işlem sonucu tekrardan yığına atıldı.
			sayiStackYazdir();		//Yazdırma işlemleri.
			isaretStackYazdir();	
		}else if(isaret=='-'){
			sayi2=popSayi();		//Yığına ilk giren sayı öncelikli olduğundan ters şekilde sayılar çekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);		//Oluşan işlem sonucu tekrardan yığına atıldı.
			sayiStackYazdir();		//Yazdırma işlemleri.
			isaretStackYazdir();	
		}
	isaret=popIsaret();				//Döngünün devamı için işaret çekmeye devam ediyorum.
	}
			sayiStackYazdir();
			isaretStackYazdir();		//En son '(' yığından çekildikten sonraki yazdırma işlemi.
			
			
	}
}
	//**********************************ISLEMLER BITTI********************************
		while(!isIsaretEmpty()){			//İşlemler bittikten sonra yığın boşalana kadar işaret çekiyorum.
			isaret=popIsaret();
			
			if(isaret=='*'){			
			sayi1=popSayi();			//İşaret '*' ise yığından terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;			//İşlem sonucu tekrardan yığına atılıyor.
			pushSayi(sonuc);		
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();	
			}else if(isaret=='/') {			//Gelen işaret '*' değilse '/' dir.
			sayi2=popSayi();			//Yığına son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//İşlem sonucu tekrardan Sayı Yığınına atıldı.
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();	
			}
		else if(isaret=='+'){				//Yığının tepesindeki işaret '+' ise çekiyorum
			sayi1=popSayi();			//Toplama işareti olduğundan yığındaki 2 terim çekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//Çekilen sayıların işlem sonucu tekrardan yığına atıldı.
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();	
		}else if(isaret=='-'){
			sayi2=popSayi();			//Yığına ilk giren sayı öncelikli olduğundan ters şekilde sayılar çekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Oluşan işlem sonucu tekrardan yığına atıldı.
			sayiStackYazdir();			//Yazdırma işlemleri.
			isaretStackYazdir();	
		}
		
	}
	
	printf("Islem sonucu : %d ",popSayi());			//Tüm işlemler bittikten sonra Sayi Yığınındaki son değer olan sonucu çekiyorum.
			
	
	return 0;
}
