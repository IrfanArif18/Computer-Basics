#include <stdio.h>

int main() {
    int number, count1 = 0, count2 = 0, count3 = 0, i = 0;

    while(i < 20) {
        printf("Masukkan input %d: ", i + 1);
        scanf("%d", &number);

        if(number == 1) {
            count1++;
            i++;
        } else if(number == 2) {
            count2++;
            i++;
        } else if(number == 3) {
            count3++;
            i++;
        } else {
            printf("Input hanya boleh bilangan bulat antara 1 sampai 3\n");
        }
    }

    printf("Banyaknya input 1: %d\n", count1);
    printf("Banyaknya input 2: %d\n", count2);
    printf("Banyaknya input 3: %d\n", count3);

    return 0;
}