#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BOYUT 25
typedef enum { false, true } bool;

static int sayilar[BOYUT];						//Sayilarý tutacaðým yýðýn.
static char isaretler[BOYUT];					//Ýþaretleri tutacaðým yýðýn.
static int isaretler_indis=-1,sayilar_indis=-1;	//Ýndisleri -1 den baþlatýyorum.
	

bool isSayiEmpty(){
	if(sayilar_indis==-1){
		return true;
	}
	else return false;
}
//******************************************************************

bool isSayiFull(){
	if(sayilar_indis==BOYUT-1){			//Eger yigin max kapasiteye ulaþmýþsa bir uyarý mesajý yollanacak.
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
	if(isaretler_indis==BOYUT-1){			//Eger yigin max kapasiteye ulaþmýþsa bir uyarý mesajý yollanacak.
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

int popSayi(){							//Eger yigin suanda boþ ise bir uyarý mesajý yollanacak.
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
	if(isIsaretFull()){			//Eger yigin max kapasiteye ulaþmýþsa bir uyarý mesajý yollanacak.
		printf("Yigin max kapasiteye ulasti yükleme yapilamiyor!");
		return;
	}
	isaretler_indis++;
	isaretler[isaretler_indis]=ch;
	
	
}
//******************************************************************
char popIsaret(){
	char isaret;
	if(isIsaretEmpty()){				//Eger yigin suanda boþ ise bir uyarý mesajý yollanacak.
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
	
	char islem[BOYUT],buff[5];		//buff stringten int deðer dönüþümünde kullanýlacaktýr.
	int islem_length;				//Girilen iþlemin string olarak uzunluðunu hesaplamak için kullanýlacaktýr.
	int i,sayi;						//i : döngü deðiþkeni, sayi Stringten int deðerine dönüþümde int deðerini tutan deðiþken olarak kullanýlacak.
	char isaret;					//Yýðýndan çekilen iþareti tutmak için kullanýlacak deðiþken
	int sayi1,sayi2;				//Yýðýn çekilecek 2 sayýyý tutmak için kullanýlacak deðiþkenler.
	int sonuc;						//Çekilen 2 sayýnýn iþlemleri sonucu oluþacak sayýyý tutmak için kullanýlacak deðiþken.
	
	printf("Islemi giriniz : ");
	scanf("%s",islem);
	islem_length=strlen(islem);		//Ýþlemin uzunluðu alýndý.
	
	for(i=0;i<islem_length;i++){
	
		if(islem[i]>=48&&islem[i]<=57){
			int j=0;
			buff[j]=islem[i];
			j++;
			while(islem[i+1]>=48&&islem[i+1]<=57){  //Ýþlemde verilen sayýnýn bir basamaklýdan daha fazla basamaklý olup olmadýðýnýn kontrolü.
			buff[j]=islem[i+1];
			i++;
			j++;
		}
		sayi=atoi(buff);			// Aldýðým string deðerini integer deðere çeviriyorum
		pushSayi(sayi);				//Çevirilen integer deðerini sayi stackine atýyorum.
		memset(buff, 0, 5);			//Buffer olarak kullandýðým deðeri içinde deðer kalmasýn diye sýfýrlýyorum.
		sayiStackYazdir();			//Yazdýrma iþlemleri.
		isaretStackYazdir();	
		
				
	}else if(islem[i]=='('){
		pushIsaret(islem[i]);		//'(' gelirse direkt yýðýna atýlýyor.
		sayiStackYazdir();			//Yazdirma iþlemleri.
		isaretStackYazdir();	
		
	}else if(islem[i]=='*'){
		if(peekIsaret()=='*'||peekIsaret()=='/'){	//Çarpma iþleminde yýðýn içindeki eþit öncelikli terimlere bakýlýyor.
			isaret=popIsaret();		//Eþit öncelikli ise iþaret yýðýndan çekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//Ýþaret '*' ise yýðýndan terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//Ýþlem sonucu tekrardan yýðýna atýlýyor.
			pushSayi(sonuc);
			pushIsaret('*');		//Eþit öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			
			}else {				//Gelen iþaret '*' deðilse '/' dir.
			sayi2=popSayi();	//Yýðýna son giren bölen, ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);	//Ýþlem sonucu tekrardan Sayý Yýðýnýna atýldý.
			pushIsaret('*');	//Eþit öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			
			sayiStackYazdir();	//Yazdýrma iþlemleri.
			isaretStackYazdir();
			
			}
		}else if(peekIsaret()=='('){
			pushIsaret('*');		//Yýðýndaki iþaret '(' ise iþaret direkt yýðýna yerleþtirilir.
		sayiStackYazdir();			//Yazdýrma iþlemleri.
		isaretStackYazdir();
		
		}else{
			pushIsaret('*');		//Çarpma iþlemi iþaret yýðýnýna atýldý.	
		sayiStackYazdir();			//Yazdýrma iþlemleri.
		isaretStackYazdir();
		}

	}else if(islem[i]=='/'){//*************GELEN ÝÞLEM '/' ÝSE *******************
		if(peekIsaret()=='*'||peekIsaret()=='/'){	//Bölme iþleminde yýðýn içindeki eþit öncelikli terimlere bakýlýyor.
			isaret=popIsaret();		//Eþit öncelikli ise iþaret yýðýndan çekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//Ýþaret '*' ise yýðýndan terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//Ýþlem sonucu tekrardan yýðýna atýlýyor.
			pushSayi(sonuc);
			pushIsaret('/');		//Eþit öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();		//Yazdýrma iþlemleri.
			isaretStackYazdir();	
			}else {				//Gelen iþaret '*' deðilse '/' dir.
			sayi2=popSayi();	//Yýðýna son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);	//Ýþlem sonucu tekrardan Sayý Yýðýnýna atýldý.
			pushIsaret('/');	//Eþit öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();	//Yazdýrma iþlemleri
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='('){
			pushIsaret('/');	//Yýðýndaki iþaret '(' ise doðrudan yýðýna atýyorum.	
			sayiStackYazdir();	//Yazdýrma iþlemleri.
		    isaretStackYazdir();
		}else{
		
		pushIsaret('/');		//Bölme iþlemi iþaret yýðýnýna atýldý.
		sayiStackYazdir();		//Yazdýrma iþlemleri. 
		isaretStackYazdir();
	}
	} else if(islem[i]=='+'){	//************************GELEN ÝÞLEM '+' ÝSE********************************
		if(peekIsaret()=='*'||peekIsaret()=='/'){//Toplama iþleminde yýðýn içindeki eþit ve öncelikli terimlere bakýlýyor.
			isaret=popIsaret();		//Öncelikli ise iþaret yýðýndan çekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//Ýþaret '*' ise yýðýndan terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//Ýþlem sonucu tekrardan yýðýna atýlýyor.
			pushSayi(sonuc);
			pushIsaret('+');		//Öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();		//Yazdýrma iþlemleri.
			isaretStackYazdir();	
			}else {						//Gelen iþaret '*' deðilse '/' dir.
			sayi2=popSayi();			//Yýðýna son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//Ýþlem sonucu tekrardan Sayý Yýðýnýna atýldý.
			pushIsaret('+');			//Öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();			//Yazdýrma iþlemleri
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='+'){	//Yýðýnýn tepesindeki iþaret '+' ise çekiyorum
			popIsaret();				//Yýðýndaki iþaret çekildi.
			sayi1=popSayi();			//Toplama iþareti olduðundan yýðýndaki 2 terim çekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//Çekilen sayýlarýn iþlem sonucu tekrardan yýðýna atýldý.
			pushIsaret('+');			//Eþit öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();
		}else if(peekIsaret()=='-'){
			popIsaret();				//Yýðýndan iþaret çekildi.
			sayi2=popSayi();			//Yýðýna ilk giren sayý öncelikli olduðundan ters þekilde sayýlar çekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Oluþan iþlem sonucu tekrardan yýðýna atýldý.
			pushIsaret('+');			//Eþit öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();
		}
		else if(peekIsaret()=='('){
			pushIsaret('+');			//Yýðýndaki iþaret '(' ise doðrudan yýðýna atýyorum.	
			sayiStackYazdir();			//Yazdýrma iþlemleri
			isaretStackYazdir();
		}else{
		pushIsaret('+');				//Toplama iþlemi iþaret yýðýnýna atýldý.
		sayiStackYazdir();				//Yazdýrma iþlemleri
		isaretStackYazdir();
		}
	}else if(islem[i]=='-'){	//************************GELEN ÝÞLEM '-' ÝSE********************************
		if(peekIsaret()=='*'||peekIsaret()=='/'){//Toplama iþleminde yýðýn içindeki eþit ve öncelikli terimlere bakýlýyor.
			isaret=popIsaret();		//Öncelikli ise iþaret yýðýndan çekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//Ýþaret '*' ise yýðýndan terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//Ýþlem sonucu tekrardan yýðýna atýlýyor.
			pushSayi(sonuc);
			pushIsaret('-');		//Öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();		//Yazdýrma iþlemleri.
			isaretStackYazdir();
			}else {						//Gelen iþaret '*' deðilse '/' dir.
			sayi2=popSayi();			//Yýðýna son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//Ýþlem sonucu tekrardan Sayý Yýðýnýna atýldý.
			pushIsaret('-');			//Öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='+'){	//Yýðýnýn tepesindeki iþaret '+' ise çekiyorum
			popIsaret();				//Yýðýndaki iþaret çekildi.
			sayi1=popSayi();			//Toplama iþareti olduðundan yýðýndaki 2 terim çekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//Çekilen sayýlarýn iþlem sonucu tekrardan yýðýna atýldý.
			pushIsaret('-');			//Eþit öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();
		}else if(peekIsaret()=='-'){
			popIsaret();				//Yýðýndan iþaret çekildi.
			sayi2=popSayi();			//Yýðýna ilk giren sayý öncelikli olduðundan ters þekilde sayýlar çekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Oluþan iþlem sonucu tekrardan yýðýna atýldý.
			pushIsaret('-');			//Eþit öncelikli iþlem yapýldýktan sonra gelen iþaretim yýðýna atýlýyor.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();
		}
		else if(peekIsaret()=='('){
			pushIsaret('-');			//Yýðýndaki iþaret '(' ise doðrudan yýðýna atýyorum.	
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();
		}else
		pushIsaret('-');				//Çýkarma iþlemi iþaret yýðýnýna atýldý.
		sayiStackYazdir();				//Yazdýrma iþlemleri.
		isaretStackYazdir();
	}
	//**********************IÞARET ')' ISE******************************
	else if(islem[i]==')'){
		isaret=popIsaret();			//Ýlk iþaret çekiliyor.
		while(isaret!='('){			//Gelen iþaret '(' olmadýðý sürece döngü devam ediyor.
			
			if(isaret=='*'){			
			sayi1=popSayi();		//Ýþaret '*' ise yýðýndan terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//Ýþlem sonucu tekrardan yýðýna atýlýyor.
			pushSayi(sonuc);
			sayiStackYazdir();		//Yazdýrma iþlemleri.
			isaretStackYazdir();	
			}else if(isaret=='/') {		//Gelen iþaret '*' deðilse '/' dir.
			sayi2=popSayi();			//Yýðýna son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//Ýþlem sonucu tekrardan Sayý Yýðýnýna atýldý.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();	
			}
		else if(isaret=='+'){			//Yýðýnýn tepesindeki iþaret '+' ise çekiyorum
			sayi1=popSayi();			//Toplama iþareti olduðundan yýðýndaki 2 terim çekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//Çekilen sayýlarýn iþlem sonucu tekrardan yýðýna atýldý.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();	
		}else if(isaret=='-'){
			sayi2=popSayi();			//Yýðýna ilk giren sayý öncelikli olduðundan ters þekilde sayýlar çekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Oluþan iþlem sonucu tekrardan yýðýna atýldý.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();	
		}
	isaret=popIsaret();					//Döngünün devamý için iþaret çekmeye devam ediyorum.
	}
			sayiStackYazdir();
			isaretStackYazdir();		//En son '(' yýðýndan çekildikten sonraki yazdýrma iþlemi.
			
			
	}
}
	//**********************************ISLEMLER BITTI********************************
		while(!isIsaretEmpty()){	//Ýþlemler bittikten sonra yýðýn boþalana kadar iþaret çekiyorum.
			isaret=popIsaret();
			
			if(isaret=='*'){			
			sayi1=popSayi();		//Ýþaret '*' ise yýðýndan terimler çekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//Ýþlem sonucu tekrardan yýðýna atýlýyor.
			pushSayi(sonuc);		
			sayiStackYazdir();		//Yazdýrma iþlemleri.
			isaretStackYazdir();	
			}else if(isaret=='/') {		//Gelen iþaret '*' deðilse '/' dir.
			sayi2=popSayi();			//Yýðýna son giren bölen ilk giren bölünün olur o sebepten ilk bölen çekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//Ýþlem sonucu tekrardan Sayý Yýðýnýna atýldý.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();	
			}
		else if(isaret=='+'){			//Yýðýnýn tepesindeki iþaret '+' ise çekiyorum
			sayi1=popSayi();			//Toplama iþareti olduðundan yýðýndaki 2 terim çekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//Çekilen sayýlarýn iþlem sonucu tekrardan yýðýna atýldý.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();	
		}else if(isaret=='-'){
			sayi2=popSayi();			//Yýðýna ilk giren sayý öncelikli olduðundan ters þekilde sayýlar çekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Oluþan iþlem sonucu tekrardan yýðýna atýldý.
			sayiStackYazdir();			//Yazdýrma iþlemleri.
			isaretStackYazdir();	
		}
		
	}
	
	printf("Islem sonucu : %d ",popSayi());		//Tüm iþlemler bittikten sonra Sayi Yýðýnýndaki son deðer olan sonucu çekiyorum.
			
	
	return 0;
}
