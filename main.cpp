#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

float prediksiX(float);
float prediksiP(float, float);

float updateX(float, float, float);
float updateK(float, float);
float updateP(float, float);

float predP;
float updX, updK, updP;

int predX;

int main(){
	float nilaiY [1000];
	float x0 = 0;
	float p0 = 1;
	float q = 1;
	float r = 1;

	ofstream file, out;
  	file.open("input.txt");
  	out.open("output.txt");

	srand((unsigned) time(0));
  	int randomNumber;
  	short int sign;
  	int start;
  	for (int index = 0; index < 1000; index++) {
    	randomNumber = (rand() % 35) + 1;
    	sign = rand() % 20 + 1;
    	if (index < 10)
    		cout << sign << endl;
    	
    	if (sign % 3 == 0)
    		start -= randomNumber;
    	else 
    		start += randomNumber;

    	if (start < 0)
    		start += randomNumber;

    	nilaiY[index] = start;
    	// cout << nilaiY[index] << endl;
    	file << nilaiY[index] << endl;
    	// cout << sign << endl;
  	}

  	
  	
  	file.close();

	////prediksi pada awal
	// cout << "predX: " << prediksiX(x0) << ", predP: " << prediksiP(p0, q) << endl;

	// update pada awal
	predX = prediksiX(x0);
	predP = prediksiP(p0, q);
	updK = updateK(predP, r);
	updX = updateX(predX, updK, nilaiY[0]);
	updP = updateP(updK, predP);
	// cout << "x sekarang: " << nilaiY[0] << ", xpred: " << predX << endl;
	out << predX << endl;

	// cout << "pPred: " << predP << ", k: " << updK << endl;
	// cout << "xUpd: " << updX << ", pPred: " << updP << endl;

	for (short i = 1; i < 1000; i++){
		// update pada kedua sampai akhir
		predX = prediksiX(updX);
		predP = prediksiP(updP, q);
		updK = updateK(predP, r);
		updX = updateX(predX, updK, nilaiY[i]);
		updP = updateP(updK, predP);
		// cout << "x sekarang: " << nilaiY[i] << ", x prediksi: " << predX << endl;
		out << predX << endl;
	}

	out.close();
	

	

  	// srand((unsigned) time(NULL));



	// cout << updateX(prediksiX(x0), updateK(prediksiP(x0), r), y[0]) << endl;

	return EXIT_SUCCESS;
}

float prediksiX(float x){
	return x;
}

float prediksiP(float p, float q){
	return (p + q);
}

float updateK(float p, float r){
	return (p / (p + r));
}

float updateX(float x, float k, float y){
	return (x + k * (y - x));
}

float updateP(float k, float p){
	return ((1 - k) * p);
}
