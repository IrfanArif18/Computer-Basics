#include <stdio.h>
#include <stdlib.h>

// Ubah makro ini manakala jumlah partai berubah
#define PRT 4 // Jumlah partai + 1 (1 baris untuk "tidak sah")

void initHitung(int hitungPar[PRT][2]);
void isiHitung(int hitungPar[PRT][2], int);
void printHistogram(int hitungPar[PRT][2]);

int inputPosInt();


int main() {
    int peserta;
    int hitung[PRT][2];

    // Mengisi nilai awal matriks "hitung"
    // Sesuai dengan no. partai dan jumlah frekuensi awal = 0
    initHitung(hitung);

    system("cls");
    printf("PROGRAM MENGHITUNG SUARA DALAM PILKADA");
    printf("\n(%d partai)\n\n\n", PRT - 1);
    
    // Meminta banyaknya peserta dengan syarat bil. bulat positif
    peserta = inputPosInt();
    printf("\n");

    // Meminta pilihan partai berulang sebanyak jumlah peserta
    // Kemudian mengisi frekuensi pilihan partai pada matriks "hitung"
    isiHitung(hitung, peserta);

    // Mencetak output
    printf("\nPartai\t\tSuara\t\tHistogram"); // Mencetak judul tabel
    printHistogram(hitung); // Mencetak no. partai, frekuensi pilihan, dan histogram
    printf("\nTotal suara\t%d", peserta); // Mencetak total suara

    return 0;
}


void initHitung(int hitungPar[PRT][2]) {
    int i;

    for(i = 0; i < PRT; i++) {
        hitungPar[i][0] = i + 1; // Mengisi kolom ke-1 dengan no. partai
        hitungPar[i][1] = 0; // Mengisi kolom ke-2 dengan 0 (frekuensi pilihan awal)
    }

}

void isiHitung(int hitungPar[PRT][2], int pesertaPar) {
    int pilihan, i;

    // Meminta input pilihan partai berulang sebanyak jumlah peserta
    for(i = 1; i <= pesertaPar; i++) {
        printf("%d. Input partai: ", i);
        scanf("%d", &pilihan);

        // Menentukan pada baris berapa input mesti dimasukkan
        if(pilihan >= 1 && pilihan <= PRT - 1) {
            hitungPar[pilihan - 1][1]++; // Menambah frekuensi partai yang bersesuaian
        } else {
            hitungPar[PRT - 1][1]++; // Menambah frekuensi tidak sah
        }
    }

}

void printHistogram(int hitungPar[PRT][2]) {
    int i, j;

    for(i = 0; i < PRT; i++) {
        if(hitungPar[i][0] == PRT) {
            printf("\nTidak sah\t%d\t\t", hitungPar[i][1]); // Mencetak baris tidak sah + frekuensinya
        } else {
            printf("\n%d\t\t%d\t\t", hitungPar[i][0], hitungPar[i][1]); // Mencetak baris no. partai + frekuensinya
        }

        // Mencetak histogram horizontal
        for(j = 0; j < hitungPar[i][1]; j++) {
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
            printf("Masukan jumlah pemilih hanya bisa berupa bilangan bulat positif.\n\n");
        }
    }

    return input;
}
