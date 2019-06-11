#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
FILE *dosya;

struct hasta{
	int hastano;
	char hastaadi[50];
	int hastayasi;
	int odano;
	char kayitno[10];
	int ilacno;
	char ilacadi[50];
	int gunlukilacadet;
};


void ekle(){
	dosya=fopen("Kayit.txt","a");
	struct hasta hst;
	printf("Hasta No Giriniz:\n");
	scanf("%s",&hst.hastano);
	fprintf(dosya,"\n%s ",&hst.hastano);
	printf("Hasta Ismini Giriniz: ÷r(Berk_Dusunur)\n");
	scanf("%s",&hst.hastaadi);
	fprintf(dosya,"#%s# ",&hst.hastaadi);
	printf("Hasta Yasini Giriniz:\n");
	scanf("%s",&hst.hastayasi);
	fprintf(dosya,"#%s# ",&hst.hastayasi);
	printf("Hastanin Oda Numarasini Giriniz:\n");
	scanf("%s",&hst.odano);
	fprintf(dosya,"#%s# ",&hst.odano);
	printf("Kayit Numarasi Giriniz:\n");
	scanf("%s",&hst.kayitno);
	fprintf(dosya,"#%s# ",&hst.kayitno);
	printf("Hastanin Ilac Numarasini Giriniz:\n");
	scanf("%s",&hst.ilacno);
	fprintf(dosya,"#%s# ",&hst.ilacno);
	printf("Ilac Adini Giriniz:\n");
	scanf("%s",&hst.ilacadi);
	fprintf(dosya,"#%s# ",&hst.ilacadi);
	printf("Hastanin Gunluk Alacagi Ilac Adedini Giriniz:\n");
	scanf("%s",&hst.gunlukilacadet);
	fprintf(dosya,"#%s#",&hst.gunlukilacadet);
	//fwrite(&hst,sizeof(struct hasta),1,dosya);
	fclose(dosya);
}
void sil(){
	char silinecekbilgi[50],yedekbilgi[10000];
	dosya=fopen("Kayit.txt","r");
	FILE *tempdosya=fopen("Kayityedek.txt","w");
	printf("Silinecek Hastanin Hasta Numarasini Giriniz:\n");
	scanf("%s",&silinecekbilgi);
	int j=0,bulundu=0;
	while(!feof(dosya)){
		fscanf(dosya,"%s\n",&yedekbilgi);
		if(strcmp(yedekbilgi,silinecekbilgi)==0&&bulundu==0){
			printf("Kayit Silindi.\n");
			j=1; bulundu=1;
		}
		else{
			if(j>0&&j<8){
				j++;
		}
			 else{
			 	fputs(yedekbilgi,tempdosya);
			fputs(" ",tempdosya);
		}
		}
	}
	bulundu=0;
	fclose(dosya);
	fclose(tempdosya);
	remove("Kayit.txt");
	rename("Kayityedek.txt","Kayit.txt");
}
void ara(){
	char aranacakbilgi[50],karsilastirma[50];
	dosya=fopen("Kayit.txt","r");
	printf("Aradiginiz Hastanin Hasta Numarasini Giriniz:\n");
	scanf("%s",&aranacakbilgi);
	int j=0,bulundu=0,i=0,dongu=0;printf("H.No\tH.Ad\t\tH.Yas\tO.No\tK.No\tI.No\tI.Adi\t\tI.Adet\n");
	while(!feof(dosya)){
		while(fscanf(dosya,"%s",&karsilastirma)==1){
		if(strcmp(aranacakbilgi,karsilastirma)==0){
			bulundu=1; j=1; printf("\n");
		}
		if(bulundu==1){
			if(j>0&&j<=8){
				printf("%s\t",karsilastirma);
				j++;
				}
			}			
	}
}
if(bulundu==0)printf("Bu Hasta Numarasina Ait Hasta Bulunamadi.\n");
fclose(dosya);
printf("\n\n");
}
void listele(){
	printf("H.No\tH.Ad\t\tH.Yas\tO.No\tK.No\tI.No\tI.Adi\t\tI.Adet\n");
	dosya=fopen("Kayit.txt","r");
	char str[50]={""}; int i=0;
	while(!feof(dosya)){
		if(i==8){
		printf("\n");
		i=0;
		}
		fscanf(dosya,"%s",&str);
		printf("%s\t",str);
		i++;				
	}
		printf("\n");
		fclose(dosya);
}
void guncelle(){
char guncellenecekbilgi[50],yedekbilgi[10000];
	dosya=fopen("Kayit.txt","r");
	FILE *tempdosya=fopen("Kayityedek.txt","w");
	printf("Guncellenecek Hastanin Hasta Numarasini Giriniz:\n");
	scanf("%s",&guncellenecekbilgi);
	int i=0,j=0,bulundu=0;
	while(!feof(dosya)){
		fscanf(dosya,"%s\n",&yedekbilgi);
		if(strcmp(yedekbilgi,guncellenecekbilgi)==0&&bulundu==0){
			printf("Kayit Guncelleniyor..\n");
			j=1; bulundu=1;
		}
		else{
			if(j>0&&j<8){
				j++;
		}
			 else{
			 	i++;
			 	fputs(yedekbilgi,tempdosya);
			fputs(" ",tempdosya);
			 if(i==8){
			 fputs("\n",tempdosya);
			 i=0;
			 }
		}
		}
	}
	bulundu=0;
		struct hasta hst;
	fprintf(tempdosya,"%s ",&guncellenecekbilgi);
	printf("Yeni Hasta Ismini Giriniz:\n");
	scanf("%s",&hst.hastaadi);
	fprintf(tempdosya,"#%s# ",&hst.hastaadi);
	printf("Yeni Hasta Yasini Giriniz:\n");
	scanf("%s",&hst.hastayasi);
	fprintf(tempdosya,"#%s# ",&hst.hastayasi);
	printf("Yeni Oda Numarasini Giriniz:\n");
	scanf("%s",&hst.odano);
	fprintf(tempdosya,"#%s# ",&hst.odano);
	printf("Yeni Kayit Numarasi Giriniz:\n");
	scanf("%s",&hst.kayitno);
	fprintf(tempdosya,"#%s# ",&hst.kayitno);
	printf("Yeni  Ilac Numarasini Giriniz:\n");
	scanf("%s",&hst.ilacno);
	fprintf(tempdosya,"#%s# ",&hst.ilacno);
	printf("Yeni Ilac Adini Giriniz:\n");
	scanf("%s",&hst.ilacadi);
	fprintf(tempdosya,"#%s# ",&hst.ilacadi);
	printf("Yeni Gunluk Alinacak Ilac Adedini Giriniz:\n");
	scanf("%s",&hst.gunlukilacadet);
	fprintf(tempdosya,"#%s#",&hst.gunlukilacadet);
	fclose(dosya);
	fclose(tempdosya);
	remove("Kayit.txt");
	rename("Kayityedek.txt","Kayit.txt");
}
int main(int argc, char *argv[]) {
	int secim;
	while(secim!=6){
		printf("1-Hasta Kaydi Ekle\n2-Hasta Kaydi Sil\n3-Hasta Ara\n4-Hastalari Listele\n5-Hasta Bilgisi Guncelle\n6-Cikis.\n");
	scanf("%d",&secim);
		if(secim==1)ekle();
		else if (secim==2)sil();
		else if(secim==3)ara();
		else if(secim==4)listele();
		else if(secim==5)guncelle();
		else if(secim==6)exit(0);
		else printf("\nGecersiz secim.\n");
	}
	return 0;
}

