/*  This program uses DO-WHILE and SWITCH only*/
#include <stdio.h>

int main() {
	int input_iter, input_numb;
	int count1 = 0, count2 = 0, count3 = 0, iter = 1;
	
	do { // Asking for number of inputs that is a positive integer
		printf("Masukkan jumlah angka yang akan diminta: ");
		scanf("%d", &input_iter);
		
		switch(input_iter > 0) {
			case 1: printf("\n");
					iter++;
					break;
			case 0: printf("Jumlah angka harus berupa bilangan bulat positif dan bukan nol.\n\n");
					break;
		}
	} while(iter < 2);
	
	iter = 1;
	do { // Counting input 1's, 2's, and 3's
		printf("Masukkan angka ke-%d: ", iter);
		scanf("%d", &input_numb);
		
		switch(input_numb) {
			case 1: count1++;
					break;
			case 2: count2++;
					break;
			case 3: count3++;
					break;
			default: printf("Angka masukan hanya bisa berupa bilangan bulat antara 1 sampai 3.\n\n");
					 iter--;
					 break;
		}	
		
		iter++;
	} while(iter <= input_iter);
	
	printf("\n1: ");
	iter = 1;
	do { // Printing horizontal histogram for number 1 
		switch(count1 == 0) {
			case 1: printf("");
					break;
			case 0: printf("#");
					iter++;
					break;
		}
	} while(iter <= count1);
	printf(" (%d)", count1);
	
	printf("\n2: ");
	iter = 1;
	do { // Printing horizontal histogram for number 2
		switch(count2 == 0) {
			case 1: printf("");
					break;
			case 0: printf("#");
					iter++;
					break;
		}
	} while(iter <= count2);
	printf(" (%d)", count2);
	
	printf("\n3: ");
	iter = 1;
	do { // Printing horizontal histogram for number 3
		switch(count3 == 0) {
			case 1: printf("");
					break;
			case 0: printf("#");
					iter++;
					break;
		}
	} while(iter <= count3);
	printf(" (%d)", count3);
	
	return 0;
}
