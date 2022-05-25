#include <stdio.h>
#include <stdlib.h>

// Ubah makro ini manakala jumlah partai berubah
#define PRT 4 // Jumlah partai + 1 (1 baris untuk "tidak sah")

void initHitung(int*);
void isiHitung(int*, int);
void printHistogram(int*);

int inputPosInt();

int main() {
    int peserta;
    int hitung[PRT][2];

    // Mengisi nilai awal matriks "hitung"
    initHitung(&hitung);

    system("cls");
    printf("PROGRAM MENGHITUNG SUARA DALAM PILKADA");
    printf("\n(%d partai)\n\n\n", PRT - 1);

    // Meminta banyaknya peserta dengan syarat bil. bulat positif
    peserta = inputPosInt();
    printf("\n");

    // Meminta pilihan partai berulang sebanyak jumlah peserta
    // Kemudian mengisi frekuensi pilihan partai pada matriks "hitung"
    isiHitung(&hitung, peserta);

    // Mencetak output
    printf("\nPartai\t\tSuara\t\tHistogram");
    printHistogram(&hitung);
    printf("\nTotal suara\t%d", peserta);

    return 0;
}

void initHitung(int* pHitung) {
    int i;

    // Mengisi seluruh isi matriks hitung dengan nilai awal 0
    for(i = 0; i < PRT; i++) {
        *(pHitung + (i * 2)) = i + 1; // Mengisi kolom ke-1 dengan no. partai
        *(pHitung + (i * 2) + 1) = 0; // Mengisi kolom ke-2 dengan 0 (frekuensi pilihan awal)
    }
}

void isiHitung(int* pHitung, int pesertaPar) {
    int pilihan, i;

    // Meminta input pilihan partai berulang sebanyak jumlah peserta
    for(i = 1; i <= pesertaPar; i++) {
        printf("%d. Input partai: ", i);
        scanf("%d", &pilihan);

        // Menentukan pada kolom berapa input mesti dimasukkan
        if(pilihan >= 1 && pilihan <= PRT - 1) {
            *(pHitung + ((pilihan - 1) * 2 + 1)) += 1;
        } else {
            *(pHitung + ((PRT - 1) * 2 + 1)) += 1;
        }
    }
}

void printHistogram(int* pHitung) {
    int i, j;

    for(i = 0; i < PRT; i++) {
        if(*(pHitung + (i * 2)) == PRT) {
            printf("\nTidak sah\t%d\t\t", *(pHitung + (i * 2) + 1));
        } else {
            printf("\n%d\t\t%d\t\t", *(pHitung + (i * 2)), *(pHitung + (i * 2) + 1));
        }

        // Mencetak histogram horizontal
        for(j = 0; j < *(pHitung + (i * 2) + 1); j++) {
            printf("#");
        }
    }

}

int inputPosInt() {
    int input;

    while(1) {
        printf("Jumlah pemilih: ");
        scanf("%d", &input);

        // Membatasi masukan jumlah pemilih
        if(input >= 0) {
            break;
        } else {
            printf("Masukan jumlah pemilih hanya bisa berupa bilangan bulat positif!\n\n");
        }
    }

}