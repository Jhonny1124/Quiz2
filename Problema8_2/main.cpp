#include <iostream>

using namespace std;

int main()
{
    char original[50] = "abc54rst";
    char texto[50] = "";
    char numeros[50] = "";
    char especiales[50] = "";
    int contl = 0, contn = 0, conte = 0;

    for(int c = 0; c < 50; c++){

        if(original[c] >= 97 && original[c] < 123){
            texto[contl] = *(original + c);
            contl++;
        }

        else if (original[c] >= 65 && original[c] < 91){
            texto[contl] = *(original + c);
            contl++;
        }

        else if (original[c] >= 48 && original[c] < 58){
            numeros[contn] = *(original + c);
            contn++;
        }
        else if (original[c] != '\0'){
            especiales[conte] = *(original + c);
            conte++;
        }

        if (original[c] == '\0'){
            break;
        }
    }

    cout << "original: ";

    for(int i = 0; i < 50; i++){
        if(original[i] == '\0'){
            break;
        }
        else{
            cout << original[i];
        }
    }

    cout << endl << "texto: ";

    for(int i = 0; i < 50; i++){
        if(texto[i] == '\0'){
            break;
        }
        else{
            cout << texto[i];
        }
    }

    cout << endl << "numeros: ";

    for(int i = 0; i < 50; i++){
        if(numeros[i] == '\0'){
            break;
        }
        else{
            cout << numeros[i];
        }
    }

    cout << endl << "Caracteres especiales: ";

    for(int i = 0; i < 50; i++){
        if(especiales[i] == '\0'){
            cout << "No hay caracteres especiales";
            break;
        }
        else{
            cout << especiales[i];
        }
    }

    cout << endl;
    return 0;
}
