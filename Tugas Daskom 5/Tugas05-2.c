#include <stdio.h>

int main() {
    int number, sentinel, count1 = 0, count2 = 0, count3 = 0;

    printf("Masukkan nilai sentinel: ");
    scanf("%d", &sentinel);

    while(1) {
        printf("Masukkan input: ");
        scanf("%d", &number);

        if(number == 1) {
            count1++;
        } else if(number == 2) {
            count2++;
        } else if(number == 3) {
            count3++;
        }
        
        if(number == sentinel) {
            break;
        }

        if(number != 1 && number != 2 && number != 3 && number!= sentinel) {
            printf("Input hanya boleh bilangan bulat antara 1 sampai 3\n");
        }

    }

    printf("Banyaknya input 1: %d\n", count1);
    printf("Banyaknya input 2: %d\n", count2);
    printf("Banyaknya input 3: %d\n", count3);

    return 0;
}