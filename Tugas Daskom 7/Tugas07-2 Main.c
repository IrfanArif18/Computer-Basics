#include <stdio.h>
#include <stdlib.h>

#include "Tugas07-2 Header.h"
#include "Tugas07-2 Definitions.c"

int main() {
	float inputAlas, inputTinggi, inputPanjang, Volume, luasPermukaan;
	char reset;
	
	do {
		while(1) {
			printf("Masukkan input alas segitiga: ");
			scanf("%f", &inputAlas);
			
			if(inputAlas > 0) {
				break;
			} else {
				printf("Input alas segitiga hanya bisa berupa bilangan positif.\n\n");
			}
		}
		
		while(1) {
			printf("Masukkan input tinggi segitiga: ");
			scanf("%f", &inputTinggi);
			
			if(inputTinggi > 0) {
				break;
			} else {
				printf("Input tinggi segitiga hanya bisa berupa bilangan positif.\n\n");
			}
		}
	
		while(1) {
			printf("Masukkan input panjang prisma: ");
			scanf("%f", &inputPanjang);
			
			if(inputPanjang > 0) {
				break;
			} else {
				printf("Input panjang prisma hanya bisa berupa bilangan positif.\n\n");
			}
		}
		
		Volume = 0.5 * inputAlas * inputTinggi * inputPanjang;
		luasPermukaan = 2 * luasSegitiga(inputAlas, inputTinggi) + luasSegiempat(inputAlas, inputTinggi, inputPanjang);
	
		printf("\nVolume prisma: %.2f", Volume);
		printf("\nLuas permukaan prisma: %.2f", luasPermukaan);
	
		while(1) {
			printf("\n\nApakah Anda ingin me-reset?");
			printf("\nMasukkan \"Y\" atau \"y\" untuk iya atau masukkan \"N\" atau \"n\" untuk tidak: ");
			scanf(" %c", &reset);
			
			if(reset == 'Y' || reset == 'y' || reset == 'N' || reset == 'n') {
				system("cls");
				break;
			} else {
				printf("Masukan %c tidak tersedia. Harap masukkan kembali input.", reset);
			}
		}
		
	} while(reset == 'Y' || reset == 'y');
	
	printf("Terima kasih!");
	
	return 0;
}
