#include <stdio.h>
int jumPeserta,pilihan,i;
int par1 = 0;
int par2 = 0; 
int par3 = 0;
int tidakSah = 0;
int Arr[];

main(){
	
	printf("Jumlah pemilih: ");
	scanf("%d", &jumPeserta);
	int Arr[jumPeserta];
	for(i=0;i<jumPeserta;i++){
		scanf("%d",&pilihan);
		Arr[i]= pilihan;
		if (Arr[i] == 1){
			par1 = par1 + 1;
		}else if(Arr[i] == 2){
			par2 = par2 + 1;
		}else if(Arr[i] == 3){
			par3 = par3 + 1;
		}else{
			tidakSah = tidakSah + 1;
		}
	}
	
	printf("Partai			Suara			Histogram\n");
	printf("1			%d			", par1);
	for(i = 0; i < par1; i ++ ){
		printf("#");
	}
	printf("\n");
	printf("2			%d			", par2);
	for(i = 0; i < par2; i ++ ){
		printf("#");
	}
	printf("\n");
	printf("3			%d			", par3);
	for(i = 0; i < par3; i ++ ){
		printf("#");
	}
	printf("\n");
	printf("Tidak sah		%d\n", tidakSah);
	printf("Total suara		%d", jumPeserta);
	
	return 0;
	
}
