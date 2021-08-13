#include <iostream>

using namespace std;

int cadena_numero(char[], short int);


int main()
{
    int cifras = 3, suma = 0, divisor = 1, modulo = 0;
    const short int TAM = 11;
    char numero[TAM] = "87512395";

    for (int i = 0; i < cifras; i++)
        divisor *= 10;

    unsigned int numero_ent = cadena_numero(numero, TAM);

    while(numero_ent > 0){
        modulo = numero_ent%divisor;
        numero_ent -= modulo;
        numero_ent /= divisor;
        suma += modulo;
    }

    cout << "Original: ";
    for(int i = 0; i < 11; i++){
        if(numero[i] == '\0'){
            break;
        }
        else{
            cout << numero[i];
        }
    }

    cout << endl << "Suma: " << suma << endl;
    return 0;
}
int cadena_numero(char cadena[], short int longi){

    int valores[10] = {14,74,21,49,65,32,47,85,67,34};
    unsigned int cont = 0,numero = 0;
    unsigned int unidad = 1000000000;

    for(int i = 0; i < longi; i++){
        cont = 0;
        for(int n = 48; n < 58; n++){
            if( cadena[i] == char(n) ){
                valores[i] = cont;
                break;
            }
            cont++;
        }
    }

    for(int i = 0; i < 10; i++){
        if((valores[i]/10) != 0 ){
            unidad /= 10;
        }
    }

    for(int v = 0; v < 10; v++){
        numero += valores[v]*unidad;
        unidad /= 10;
    }

    return numero;
}
