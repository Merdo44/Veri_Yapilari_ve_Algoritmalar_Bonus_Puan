#include <stdio.h>

// İsim Soyisim: Mert Ali YILMAZ
// Öğrenci Numarası: 2420171021

#define N 8

void dizi_yazdir(int dizi[], int tane) {
    int i;
    for (i = 0; i < tane; i++) {
        printf(" %d", dizi[i]);
    }
}

void araya_ekle_sirala(int A[], int n) {
    int i, j, anahtar;
    for (i = 1; i < n; i++) {
        anahtar = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > anahtar) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = anahtar;

        printf("\n %d. Adim (Eleman %d yerlestirildi):", i, anahtar);
        dizi_yazdir(A, n);
    }
}

int ikili_arama(int A[], int bas, int son, int aranan) {
    while (bas <= son) {
        int orta = (bas + son) / 2;

        if (A[orta] == aranan) 
            return orta; 
        
        if (A[orta] < aranan)
            bas = orta + 1; 
        else
            son = orta - 1; 
    }
    return -1; 
}

int main() {
    int A[] = {64, 25, 12, 22, 3, 96, 44, 30};
    int aranan_sayi, sonuc;

    printf("--- Baslangic Dizisi ---\n");
    dizi_yazdir(A, N);
    printf("\n\n--- Siralama Islemi Basliyor ---");

    araya_ekle_sirala(A, N);

    printf("\n\nSiralanmis Son Dizi:");
    dizi_yazdir(A, N);

    printf("\n\n-----------------------------------------");
    printf("\nAranacak sayiyi giriniz: ");
    scanf("%d", &aranan_sayi);

    sonuc = ikili_arama(A, 0, N - 1, aranan_sayi);

    if (sonuc != -1)
        printf("\nSonuc: %d sayisi dizinin %d. indeksinde bulundu.\n", aranan_sayi, sonuc);
    else
        printf("\nSonuc: %d sayisi maalesef dizide bulunamadi.\n", aranan_sayi);
    return 0;
}