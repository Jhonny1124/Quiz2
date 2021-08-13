#include <iostream>
/*
 * Al programa se le pueden ingresar hasta un maximo de 49 caracteres, en los cuales puede estar tanto letras mayusculas
 * como minusculas y un maximo de 9 numeros, ya que a la hora de hacer la suma de los numeros el tipo de dato seleccionado
 * solo permite tener un numero de maximo 9 cifras para tener una suma correcta
*/

using namespace std;

void SepararNumerosLetras(char [], char *, char *);
int cadena_numero(char[], short int);
int Suma_num(char []);


int main()
{
    char original[50] = "", ver[1] = "";
    char texto[50] = "", * point_t = texto;
    char numeros[11] = "", * point_n = numeros;

    for(int i = 0; i < 50; i++){
        cout << "Ingrese un caracter -> ";
        cin >> ver[0];
        if( ver[0] == '*'){
            break;
        }
        else{
            original[i] = ver[0];
        }
    }

    SepararNumerosLetras(original, point_t, point_n);

    cout << "Original: ";
    for(int i = 0; i < 11; i++){
        if(numeros[i] != '\0'){
            cout << numeros[i];
        }
        else{
            break;
        }
    }

    cout << endl << "Suma: " << Suma_num(numeros) << endl;
    return 0;
}


void SepararNumerosLetras(char original[50], char *point_t, char *point_n){

    int contl = 0, contn = 0;

    for(int c = 0; c < 50; c++){
        if(original[c] >= 97 && original[c] < 123){
            *(point_t + contl) = *(original + c);
            contl++;
        }
        else if (original[c] >= 65 && original[c] < 91){
            *(point_t + contl) = *(original + c);
            contl++;
        }
        else if (original[c] >= 48 && original[c] < 58){
            *(point_n + contn) = *(original + c);
            contn++;
        }

        if (original[c] == '\0'){
            break;
        }
    }
}

int cadena_numero(char cadena[], short int longi){

    int valores[11] = {14,74,21,49,65,32,47,85,67,34,99};
    unsigned long long int cont = 0,numero = 0;
    unsigned long long int unidad = 1000000000;

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

int Suma_num(char numero[11]){

    int cifras = 3, suma = 0, divisor = 1, modulo = 0;
    const short int TAM = 11;

    for (int i = 0; i < cifras; i++)
        divisor *= 10;

    unsigned long long int numero_ent = cadena_numero(numero, TAM);

    while(numero_ent > 0){
        modulo = numero_ent%divisor;
        numero_ent -= modulo;
        numero_ent /= divisor;
        suma += modulo;
    }

    return suma;
}
