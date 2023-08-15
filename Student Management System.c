#include <stdio.h>
#include <math.h>
#include <string.h>

void KayitEkle();
void KayitlariListele();
void BasariNotlariHesapla();
void BasariNotlariniYazdir();
void Sirala();
void IstatistikleriGoster();

#define OGR_SAYISI 10

char isim[OGR_SAYISI][50]={0};
char soyIsim[OGR_SAYISI][50]={0};
int vize1[OGR_SAYISI]={0};
int vize2[OGR_SAYISI]={0};
int final[OGR_SAYISI]={0};
float basariNotu[OGR_SAYISI]={0};
char harfNotu[OGR_SAYISI][3];
char gecmeDurumu[OGR_SAYISI][20];
int ogr=0;

int main(void)
{
    int secim;
    int ilkSecim=0;
    int bittiMi=0;
    do
    {
        printf("\nMENU\n");
        printf("1-Kayit ekle\n");
        printf("2-Kayitlari listele\n");
        printf("3-Sinif basari notlarini hesapla\n");
        printf("4-Kayitlari basari notuna gore sirala\n");
        printf("5-Istatistiki bilgiler\n");
        printf("6-Cikis\n\n");
        printf("ISLEM NUMARASINI GIRINIZ = ");

        scanf("%d",&secim);
        
        if(secim==1)
            ilkSecim=1;

        while(ilkSecim==0)
            if(secim==2 || secim==3 || secim==4 || secim==5)
            {
                printf("Once kayit eklenmelidir. Lutfen kayit ekleyiniz.\n\nISLEM NUMARASINI GIRINIZ = ");
                scanf("%d",&secim);
                if(secim==1)
                    ilkSecim=1;
            }
            else
                break;

        switch (secim)
        {
        case 1:
            if(ogr>=OGR_SAYISI)
                printf("\nSinif mevcudu doldu!\n");
            else
                KayitEkle();
            break;   
        case 2:
            printf("\n---Kayitlari Listele---\n");
            KayitlariListele();
            break;
        case 3:
            BasariNotlariniYazdir();
            break;
        case 4:
            Sirala();
            break;
        case 5:
            IstatistikleriGoster();
            break;
        case 6:
            printf("Cikis Yapiliyor...");
            bittiMi = 1;
            break;
        default:
            printf("\nGecersiz islem numarasi !\n\n");
            break;
        }
    } while (bittiMi==0);
}

void KayitEkle()
{
    int i=0;

    if(final[ogr]==0)
    {
        printf("\n---Kayit Ekle---\n\n");
        printf("Ad : ");
        scanf("%s",isim[ogr]);
        printf("Soyad : ");
        scanf("%s",soyIsim[ogr]);
        printf("1.Ara Sinav, 2.Ara Sinav, Final : ");
        scanf("%d %d %d",&vize1[ogr],&vize2[ogr],&final[ogr]);
        printf("\n%-14s %-14s %-10s %-10s %-10s\n","Ad","Soyad","Vize1","Vize2","Final");
        ogr++;
    }
    for (i; i<OGR_SAYISI; i++)
    {
        printf("%-14s %.1s%-13s %-10d %-10d %-10d\n",isim[i],soyIsim[i],".",vize1[i],vize2[i],final[i]);
        if(final[i+1]==0)
            break;
    }
    BasariNotlariHesapla();
}

void KayitlariListele()
{
    int i=0;
    printf("\n%-14s %-14s %-10s %-10s %-10s %-10s %-10s %-10s\n","Ad","Soyad","Vize1","Vize2","Final","Notu","Harf","Durumu");
    for (i; i<OGR_SAYISI; i++)
    {
        printf("%-14s %.1s%-13s %-10d %-10d %-10d %-10.0f %-10s %s\n",isim[i],soyIsim[i],".",vize1[i],vize2[i],final[i],basariNotu[i],harfNotu[i],gecmeDurumu[i]);
        if(final[i+1]==0)
            break;
    }
}

void BasariNotlariHesapla()
{
    int i = 0;

    for (i; i<ogr; i++)
    {
        basariNotu[i] = ((float)(vize1[i]*0.2))+((float)(vize2[i]*0.3))+((float)(final[i]*0.5));

        if (round(basariNotu[i]) >= 90)
        {
            strcpy(harfNotu[i], "AA");
        }
        else if (round(basariNotu[i]) >= 85 && round(basariNotu[i]) < 90)
        {
            strcpy(harfNotu[i], "BA");
        }
        else if (round(basariNotu[i]) >= 80 && round(basariNotu[i]) < 85)
        {
            strcpy(harfNotu[i], "BB");
        }
        else if (round(basariNotu[i]) >= 75 && round(basariNotu[i]) < 80)
        {
            strcpy(harfNotu[i], "CB");
        }
        else if (round(basariNotu[i]) >= 70 && round(basariNotu[i]) < 75)
        {
            strcpy(harfNotu[i], "CC");
        }
        else if (round(basariNotu[i]) >= 65 && round(basariNotu[i]) < 70)
        {
            strcpy(harfNotu[i], "DC");
        }
        else if (round(basariNotu[i]) >= 60 && round(basariNotu[i]) < 65)
        {
            strcpy(harfNotu[i], "DD");
        }
        else if (round(basariNotu[i]) >= 50 && round(basariNotu[i]) < 60)
        {
            strcpy(harfNotu[i], "FD");
        }
        else if (round(basariNotu[i]) < 50)
        {
            strcpy(harfNotu[i], "FF");
        }
        if (harfNotu[i][1] == 'F')
            strcpy(gecmeDurumu[i], "Kaldi");
        else if (harfNotu[i][0] == 'F' && harfNotu[i][1] == 'D')   
            strcpy(gecmeDurumu[i], "Sartli gecti");
        else
            strcpy(gecmeDurumu[i], "Gecti");
    }
}

void BasariNotlariniYazdir()
{
    int i = 0;
    BasariNotlariHesapla();
    
    printf("\n---Sinif Basari Notlarini Hesapla---\n");
    printf("\n%-14s %-14s %-14s\n","Ad","Soyad","Notu");
    for(i; i<OGR_SAYISI; i++)
    {
        printf("%-14s %.1s%-13s %.0f\n",isim[i],soyIsim[i],".",basariNotu[i]);
        if(basariNotu[i+1]==0)
            break;
    }
}

void Sirala()
{
    int temp = 0;
    char tempChar[50]={0};
    if(ogr >= 2)
    {
        for(int i = 0; i<ogr; i++)
            for(int j = 1; j<ogr-i; j++)
                if(basariNotu[j-1] < basariNotu[j])
                {
                strcpy(tempChar, isim[j]);
                strcpy(isim[j], isim[j-1]);
                strcpy(isim[j-1], tempChar);

                strcpy(tempChar, soyIsim[j]);
                strcpy(soyIsim[j], soyIsim[j-1]);
                strcpy(soyIsim[j-1], tempChar);
                
                temp = vize1[j];
                vize1[j] = vize1[j-1];
                vize1[j-1] = temp;

                temp = vize2[j];
                vize2[j] = vize2[j-1];
                vize2[j-1] = temp;

                temp = final[j];
                final[j] = final[j-1];
                final[j-1] = temp;

                temp = round(basariNotu[j]);
                basariNotu[j] = round(basariNotu[j-1]);
                basariNotu[j-1] = temp;

                strcpy(tempChar, harfNotu[j]);
                strcpy(harfNotu[j], harfNotu[j-1]);
                strcpy(harfNotu[j-1], tempChar);

                strcpy(tempChar, gecmeDurumu[j]);
                strcpy(gecmeDurumu[j], gecmeDurumu[j-1]);
                strcpy(gecmeDurumu[j-1], tempChar);
                }
    }
    printf("\n---Kayitlari Basari Notuna Gore Sirala---\n");
    KayitlariListele();     
}

void IstatistikleriGoster()
{
    int toplam=0,basariliOgrenci=0,basariOrani=0;
    float standartSapma=0;
    float ortalama=0;
    int enYuksek = basariNotu[0];
    int enDusuk = basariNotu[0];

    for(int i = 0; i<ogr; i++)
        if(basariNotu[i] > enYuksek)
            enYuksek = basariNotu[i];
    
    for(int i = 0; i<ogr; i++)
        if(basariNotu[i] < enDusuk)
            enDusuk = basariNotu[i];

    for(int i = 0; i<ogr; i++)
        toplam += basariNotu[i];

    ortalama = toplam/ogr;

    for(int i = 0; i<ogr; i++)
        if(basariNotu[i] >= ortalama)
            basariliOgrenci++;
    
    basariOrani = (basariliOgrenci*100)/ogr;

    if(ogr >= 2)
    {
        for(int i = 0; i<ogr; i++)
            standartSapma += pow((ortalama - basariNotu[i]),2);
        
        standartSapma = sqrt(standartSapma/(ogr-1));
    }

    printf("\n---Istatistiki Bilgiler---\n\n");
    printf("En Yuksek Not : %d\nEn Dusuk Not : %d\n",enYuksek,enDusuk);
    printf("Ortalama : %.0f\n",round(ortalama));
    printf("Ortalama Ustu Kisi Sayisi : %d - Basari Orani : %s%d\n",basariliOgrenci,"%",basariOrani);
    if(ogr >= 2)
    printf("Standart Sapma : %.2f\n",standartSapma);
    else
    printf("Standart Sapma : Hesaplanmadi.(Birden fazla kayit girilmesi gerek!)\n");
}