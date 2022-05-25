#include <stdio.h> 
/*Algoritma ini menggunakan for loop dan switch*/
int jumlahAngka, input, i, frekuensi1 = 0, frekuensi2 = 0, frekuensi3 = 0;

int main() {
    
    for(i = 1; i < 2; i++) {
        printf("Jumlah angka: ");
        scanf("%d", &jumlahAngka );

        switch(jumlahAngka >= 0) // Mengecek apakah jumlah angka positif
        {
        	case 1: break; // benar, jumlah angka adalah positif
       		case 0: // salah, jumlah angka adalah negatif
            		i = 0; /*melakukan set i supaya for loop dapat terulang kembali*/
           			printf("\nError!!\nAngka tidak boleh negatif untuk iterasi");
            		printf("\nMasukan Jumlah angka positif saja\n\n");
            		break;
        }
    }

    for(i = 1; i <= jumlahAngka; i++) {
        printf("Masukkan input ke-%d: ", i);
		scanf("%d", &input);

        switch (input) {
        	case 1: frekuensi1++;
            		break;
        	case 2: frekuensi2++;
            		break;
        	case 3: frekuensi3++;
            		break;
        	default: i--;
            	 	 printf("\nError!!\nIterasi anda tidak terhitung");
            	 	 printf("\nMohon masukan angka 1, 2, atau 3 saja\n\n");
            	 	 break;
        }
    }

	// Mencetak histogram horizontal frekuensi angka 1
    printf("\n1: ");
    for(i = 1; i <= frekuensi1; i++) {
        printf("#");
    }
    printf(" (%d)", frekuensi1);
    
    // Mencetak histogram horizontal frekuensi angka 2
    printf("\n2: ");
    for(i = 1; i <= frekuensi2; i++){
        printf("#");
    }
    printf(" (%d)", frekuensi2);
    
    // Mencetak histogram horizontal frekuensi angka 3
    printf("\n3: ");
    for(i = 1; i <= frekuensi3; i++){
        printf("#");
    }
    printf(" (%d)", frekuensi3);
    
    return 0;
}
