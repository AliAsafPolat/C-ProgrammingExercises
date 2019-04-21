#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BOYUT 25
typedef enum { false, true } bool;

static int sayilar[BOYUT];						//Sayilar� tutaca��m y���n.
static char isaretler[BOYUT];					//��aretleri tutaca��m y���n.
static int isaretler_indis=-1,sayilar_indis=-1;	//�ndisleri -1 den ba�lat�yorum.
	

bool isSayiEmpty(){
	if(sayilar_indis==-1){
		return true;
	}
	else return false;
}
//******************************************************************

bool isSayiFull(){
	if(sayilar_indis==BOYUT-1){			//Eger yigin max kapasiteye ula�m��sa bir uyar� mesaj� yollanacak.
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
	if(isaretler_indis==BOYUT-1){			//Eger yigin max kapasiteye ula�m��sa bir uyar� mesaj� yollanacak.
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

int popSayi(){							//Eger yigin suanda bo� ise bir uyar� mesaj� yollanacak.
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
	if(isIsaretFull()){			//Eger yigin max kapasiteye ula�m��sa bir uyar� mesaj� yollanacak.
		printf("Yigin max kapasiteye ulasti y�kleme yapilamiyor!");
		return;
	}
	isaretler_indis++;
	isaretler[isaretler_indis]=ch;
	
	
}
//******************************************************************
char popIsaret(){
	char isaret;
	if(isIsaretEmpty()){				//Eger yigin suanda bo� ise bir uyar� mesaj� yollanacak.
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
	
	char islem[BOYUT],buff[5];		//buff stringten int de�er d�n���m�nde kullan�lacakt�r.
	int islem_length;				//Girilen i�lemin string olarak uzunlu�unu hesaplamak i�in kullan�lacakt�r.
	int i,sayi;						//i : d�ng� de�i�keni, sayi Stringten int de�erine d�n���mde int de�erini tutan de�i�ken olarak kullan�lacak.
	char isaret;					//Y���ndan �ekilen i�areti tutmak i�in kullan�lacak de�i�ken
	int sayi1,sayi2;				//Y���n �ekilecek 2 say�y� tutmak i�in kullan�lacak de�i�kenler.
	int sonuc;						//�ekilen 2 say�n�n i�lemleri sonucu olu�acak say�y� tutmak i�in kullan�lacak de�i�ken.
	
	printf("Islemi giriniz : ");
	scanf("%s",islem);
	islem_length=strlen(islem);		//��lemin uzunlu�u al�nd�.
	
	for(i=0;i<islem_length;i++){
	
		if(islem[i]>=48&&islem[i]<=57){
			int j=0;
			buff[j]=islem[i];
			j++;
			while(islem[i+1]>=48&&islem[i+1]<=57){  //��lemde verilen say�n�n bir basamakl�dan daha fazla basamakl� olup olmad���n�n kontrol�.
			buff[j]=islem[i+1];
			i++;
			j++;
		}
		sayi=atoi(buff);			// Ald���m string de�erini integer de�ere �eviriyorum
		pushSayi(sayi);				//�evirilen integer de�erini sayi stackine at�yorum.
		memset(buff, 0, 5);			//Buffer olarak kulland���m de�eri i�inde de�er kalmas�n diye s�f�rl�yorum.
		sayiStackYazdir();			//Yazd�rma i�lemleri.
		isaretStackYazdir();	
		
				
	}else if(islem[i]=='('){
		pushIsaret(islem[i]);		//'(' gelirse direkt y���na at�l�yor.
		sayiStackYazdir();			//Yazdirma i�lemleri.
		isaretStackYazdir();	
		
	}else if(islem[i]=='*'){
		if(peekIsaret()=='*'||peekIsaret()=='/'){	//�arpma i�leminde y���n i�indeki e�it �ncelikli terimlere bak�l�yor.
			isaret=popIsaret();		//E�it �ncelikli ise i�aret y���ndan �ekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//��aret '*' ise y���ndan terimler �ekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//��lem sonucu tekrardan y���na at�l�yor.
			pushSayi(sonuc);
			pushIsaret('*');		//E�it �ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			
			}else {				//Gelen i�aret '*' de�ilse '/' dir.
			sayi2=popSayi();	//Y���na son giren b�len, ilk giren b�l�n�n olur o sebepten ilk b�len �ekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);	//��lem sonucu tekrardan Say� Y���n�na at�ld�.
			pushIsaret('*');	//E�it �ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			
			sayiStackYazdir();	//Yazd�rma i�lemleri.
			isaretStackYazdir();
			
			}
		}else if(peekIsaret()=='('){
			pushIsaret('*');		//Y���ndaki i�aret '(' ise i�aret direkt y���na yerle�tirilir.
		sayiStackYazdir();			//Yazd�rma i�lemleri.
		isaretStackYazdir();
		
		}else{
			pushIsaret('*');		//�arpma i�lemi i�aret y���n�na at�ld�.	
		sayiStackYazdir();			//Yazd�rma i�lemleri.
		isaretStackYazdir();
		}

	}else if(islem[i]=='/'){//*************GELEN ��LEM '/' �SE *******************
		if(peekIsaret()=='*'||peekIsaret()=='/'){	//B�lme i�leminde y���n i�indeki e�it �ncelikli terimlere bak�l�yor.
			isaret=popIsaret();		//E�it �ncelikli ise i�aret y���ndan �ekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//��aret '*' ise y���ndan terimler �ekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//��lem sonucu tekrardan y���na at�l�yor.
			pushSayi(sonuc);
			pushIsaret('/');		//E�it �ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();		//Yazd�rma i�lemleri.
			isaretStackYazdir();	
			}else {				//Gelen i�aret '*' de�ilse '/' dir.
			sayi2=popSayi();	//Y���na son giren b�len ilk giren b�l�n�n olur o sebepten ilk b�len �ekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);	//��lem sonucu tekrardan Say� Y���n�na at�ld�.
			pushIsaret('/');	//E�it �ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();	//Yazd�rma i�lemleri
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='('){
			pushIsaret('/');	//Y���ndaki i�aret '(' ise do�rudan y���na at�yorum.	
			sayiStackYazdir();	//Yazd�rma i�lemleri.
		    isaretStackYazdir();
		}else{
		
		pushIsaret('/');		//B�lme i�lemi i�aret y���n�na at�ld�.
		sayiStackYazdir();		//Yazd�rma i�lemleri. 
		isaretStackYazdir();
	}
	} else if(islem[i]=='+'){	//************************GELEN ��LEM '+' �SE********************************
		if(peekIsaret()=='*'||peekIsaret()=='/'){//Toplama i�leminde y���n i�indeki e�it ve �ncelikli terimlere bak�l�yor.
			isaret=popIsaret();		//�ncelikli ise i�aret y���ndan �ekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//��aret '*' ise y���ndan terimler �ekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//��lem sonucu tekrardan y���na at�l�yor.
			pushSayi(sonuc);
			pushIsaret('+');		//�ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();		//Yazd�rma i�lemleri.
			isaretStackYazdir();	
			}else {						//Gelen i�aret '*' de�ilse '/' dir.
			sayi2=popSayi();			//Y���na son giren b�len ilk giren b�l�n�n olur o sebepten ilk b�len �ekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//��lem sonucu tekrardan Say� Y���n�na at�ld�.
			pushIsaret('+');			//�ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();			//Yazd�rma i�lemleri
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='+'){	//Y���n�n tepesindeki i�aret '+' ise �ekiyorum
			popIsaret();				//Y���ndaki i�aret �ekildi.
			sayi1=popSayi();			//Toplama i�areti oldu�undan y���ndaki 2 terim �ekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//�ekilen say�lar�n i�lem sonucu tekrardan y���na at�ld�.
			pushIsaret('+');			//E�it �ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();
		}else if(peekIsaret()=='-'){
			popIsaret();				//Y���ndan i�aret �ekildi.
			sayi2=popSayi();			//Y���na ilk giren say� �ncelikli oldu�undan ters �ekilde say�lar �ekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Olu�an i�lem sonucu tekrardan y���na at�ld�.
			pushIsaret('+');			//E�it �ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();
		}
		else if(peekIsaret()=='('){
			pushIsaret('+');			//Y���ndaki i�aret '(' ise do�rudan y���na at�yorum.	
			sayiStackYazdir();			//Yazd�rma i�lemleri
			isaretStackYazdir();
		}else{
		pushIsaret('+');				//Toplama i�lemi i�aret y���n�na at�ld�.
		sayiStackYazdir();				//Yazd�rma i�lemleri
		isaretStackYazdir();
		}
	}else if(islem[i]=='-'){	//************************GELEN ��LEM '-' �SE********************************
		if(peekIsaret()=='*'||peekIsaret()=='/'){//Toplama i�leminde y���n i�indeki e�it ve �ncelikli terimlere bak�l�yor.
			isaret=popIsaret();		//�ncelikli ise i�aret y���ndan �ekiliyor .		
			if(isaret=='*'){			
			sayi1=popSayi();		//��aret '*' ise y���ndan terimler �ekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//��lem sonucu tekrardan y���na at�l�yor.
			pushSayi(sonuc);
			pushIsaret('-');		//�ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();		//Yazd�rma i�lemleri.
			isaretStackYazdir();
			}else {						//Gelen i�aret '*' de�ilse '/' dir.
			sayi2=popSayi();			//Y���na son giren b�len ilk giren b�l�n�n olur o sebepten ilk b�len �ekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//��lem sonucu tekrardan Say� Y���n�na at�ld�.
			pushIsaret('-');			//�ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();
			}
		}else if(peekIsaret()=='+'){	//Y���n�n tepesindeki i�aret '+' ise �ekiyorum
			popIsaret();				//Y���ndaki i�aret �ekildi.
			sayi1=popSayi();			//Toplama i�areti oldu�undan y���ndaki 2 terim �ekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//�ekilen say�lar�n i�lem sonucu tekrardan y���na at�ld�.
			pushIsaret('-');			//E�it �ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();
		}else if(peekIsaret()=='-'){
			popIsaret();				//Y���ndan i�aret �ekildi.
			sayi2=popSayi();			//Y���na ilk giren say� �ncelikli oldu�undan ters �ekilde say�lar �ekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Olu�an i�lem sonucu tekrardan y���na at�ld�.
			pushIsaret('-');			//E�it �ncelikli i�lem yap�ld�ktan sonra gelen i�aretim y���na at�l�yor.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();
		}
		else if(peekIsaret()=='('){
			pushIsaret('-');			//Y���ndaki i�aret '(' ise do�rudan y���na at�yorum.	
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();
		}else
		pushIsaret('-');				//��karma i�lemi i�aret y���n�na at�ld�.
		sayiStackYazdir();				//Yazd�rma i�lemleri.
		isaretStackYazdir();
	}
	//**********************I�ARET ')' ISE******************************
	else if(islem[i]==')'){
		isaret=popIsaret();			//�lk i�aret �ekiliyor.
		while(isaret!='('){			//Gelen i�aret '(' olmad��� s�rece d�ng� devam ediyor.
			
			if(isaret=='*'){			
			sayi1=popSayi();		//��aret '*' ise y���ndan terimler �ekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//��lem sonucu tekrardan y���na at�l�yor.
			pushSayi(sonuc);
			sayiStackYazdir();		//Yazd�rma i�lemleri.
			isaretStackYazdir();	
			}else if(isaret=='/') {		//Gelen i�aret '*' de�ilse '/' dir.
			sayi2=popSayi();			//Y���na son giren b�len ilk giren b�l�n�n olur o sebepten ilk b�len �ekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//��lem sonucu tekrardan Say� Y���n�na at�ld�.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();	
			}
		else if(isaret=='+'){			//Y���n�n tepesindeki i�aret '+' ise �ekiyorum
			sayi1=popSayi();			//Toplama i�areti oldu�undan y���ndaki 2 terim �ekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//�ekilen say�lar�n i�lem sonucu tekrardan y���na at�ld�.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();	
		}else if(isaret=='-'){
			sayi2=popSayi();			//Y���na ilk giren say� �ncelikli oldu�undan ters �ekilde say�lar �ekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Olu�an i�lem sonucu tekrardan y���na at�ld�.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();	
		}
	isaret=popIsaret();					//D�ng�n�n devam� i�in i�aret �ekmeye devam ediyorum.
	}
			sayiStackYazdir();
			isaretStackYazdir();		//En son '(' y���ndan �ekildikten sonraki yazd�rma i�lemi.
			
			
	}
}
	//**********************************ISLEMLER BITTI********************************
		while(!isIsaretEmpty()){	//��lemler bittikten sonra y���n bo�alana kadar i�aret �ekiyorum.
			isaret=popIsaret();
			
			if(isaret=='*'){			
			sayi1=popSayi();		//��aret '*' ise y���ndan terimler �ekiliyor.
			sayi2=popSayi();
			sonuc=sayi1*sayi2;		//��lem sonucu tekrardan y���na at�l�yor.
			pushSayi(sonuc);		
			sayiStackYazdir();		//Yazd�rma i�lemleri.
			isaretStackYazdir();	
			}else if(isaret=='/') {		//Gelen i�aret '*' de�ilse '/' dir.
			sayi2=popSayi();			//Y���na son giren b�len ilk giren b�l�n�n olur o sebepten ilk b�len �ekildi.
			sayi1=popSayi();
			sonuc=sayi1/sayi2;
			pushSayi(sonuc);			//��lem sonucu tekrardan Say� Y���n�na at�ld�.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();	
			}
		else if(isaret=='+'){			//Y���n�n tepesindeki i�aret '+' ise �ekiyorum
			sayi1=popSayi();			//Toplama i�areti oldu�undan y���ndaki 2 terim �ekildi.
			sayi2=popSayi();
			sonuc=sayi1+sayi2;		
			pushSayi(sonuc);			//�ekilen say�lar�n i�lem sonucu tekrardan y���na at�ld�.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();	
		}else if(isaret=='-'){
			sayi2=popSayi();			//Y���na ilk giren say� �ncelikli oldu�undan ters �ekilde say�lar �ekildi.
			sayi1=popSayi();
			sonuc=sayi1-sayi2;			
			pushSayi(sonuc);			//Olu�an i�lem sonucu tekrardan y���na at�ld�.
			sayiStackYazdir();			//Yazd�rma i�lemleri.
			isaretStackYazdir();	
		}
		
	}
	
	printf("Islem sonucu : %d ",popSayi());		//T�m i�lemler bittikten sonra Sayi Y���n�ndaki son de�er olan sonucu �ekiyorum.
			
	
	return 0;
}
