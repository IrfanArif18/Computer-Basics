#include <math.h>

float luasSegitiga(float alas, float tinggi) {
	float luas = 0.5 * alas * tinggi;
	
	return luas;
}

float luasSegiempat(float alas, float tinggi, float panjang) {
	float miring = sqrt(alas * alas + tinggi * tinggi);
	
	float panjangAlas = panjang * alas;
	float panjangTinggi = panjang * tinggi;
	float panjangMiring = panjang * miring;
	
	float luas = panjangAlas + panjangTinggi + panjangMiring;
	
	return luas;
}
