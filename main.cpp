#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

double mappa(long double x){
    return 0.75*x - 1.75;
}


int main(void){
    string filename = "data.txt";
    ifstream ifs(filename);
    ofstream file("result.txt");
    double contatore = 1.0;
    long double somma_numeri;
    

    file << "# N mean" << endl;
    if(ifs.is_open()){
        file << scientific << setprecision(16);
        while(!ifs.eof()){
            long double numero;
            ifs >> numero;
            numero = mappa(numero);
            if(contatore == 1.0){
                file << numero << endl;
                somma_numeri = numero;
            }else{
                somma_numeri = somma_numeri + numero;
                file << somma_numeri/contatore << endl;
            }
            contatore = contatore + 1.0;
        }
    }
    file.close();
    return 0;
}
