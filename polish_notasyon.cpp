 #include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define YBOYUT 30

typedef struct yigin{
	int dizi[YBOYUT];
	int indis;
}Yiginlar;
    Yiginlar yeni;
int cikar();
int hesapla();
 
void yigin_ekle(int eklenecek){
 	if(yeni.indis>=(YBOYUT-1)){
 		printf("yigin dolu!!!");
    }
	else {
	 	yeni.indis++;
	 	yeni.dizi[yeni.indis]=eklenecek;
	}
}
 int yigin_cikar(){
 	if(yeni.indis==-1){
 		return -1;
    }
	else{
	 	int eleman;
	 	yeni.dizi[yeni.indis]=eleman;
	 	yeni.indis--;
	 	return eleman;
	}
	return 0;
 }

int hesapla(int deger1, char operator1,int deger2){
	int sonuc;
	switch(operator1){
		case  '+': return sonuc=(int)(int)deger1+(int)deger2;
		    break;
		case '-': return sonuc=(int)deger2-(int)deger1;
		    break;
		case '*': return sonuc=(int)deger1*(int)deger2;
		    break;
		case '/':return sonuc=(int)deger2/(int)deger1;
		    break;
		default: return 0; printf("yanlis giris");
	}

}

int polish_algo(char dizi[],int dizi_boyut){
	int index=dizi_boyut;
    int operand1=0,operand2=0,yeni_deger=0;
	int sonuc=0,ondalik_deger=0;
	char operator1;
	for(index=dizi_boyut-1;index>=0;index--){
		if(dizi[index]>='0' && dizi[index]<=9){
			yigin_ekle(dizi[index]);
			printf("eklenen deger:%c",dizi[index]);	
		}
		else if(dizi[index]==' '){
			index--;
		}
		else {
			operand2=(int)yigin_cikar(); 
			operand1=(int)yigin_cikar();
			operator1=dizi[index];
			yeni_deger=hesapla(operand1,operator1,operand2);
			yigin_ekle(yeni_deger); 
	    }
	    index--;
	}
	sonuc=yigin_cikar();
	return sonuc;
}

int main(){
	yeni.indis=-1;
	char dizi1[30];
	printf("polish notasyonu giriniz(her girdi arasinda bosluk birakiniz): ");
	gets(dizi1);
	int boyut=strlen(dizi1);
	polish_algo(dizi1,boyut);
	int sonuc=polish_algo(dizi1,boyut);
	printf(" polish notasyonun degeri:%d",sonuc);
	
	return 0;
}
