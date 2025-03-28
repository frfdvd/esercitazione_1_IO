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
    int contatore = 1;
    long double somma_numeri = 0.0;
    
    file << "# N mean" << endl;
    if(ifs.is_open()){
        file << scientific << setprecision(16);
        while(!ifs.eof()){
            long double numero;
            ifs >> numero;
            numero = mappa(numero);
            somma_numeri = somma_numeri + numero;
            file << contatore << ' ' << somma_numeri/contatore << endl;
            contatore = contatore + 1;
        }
    }
    file.close();
    return 0;
}
