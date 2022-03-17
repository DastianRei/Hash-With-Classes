#include "Hash.h"
#include <fstream>
#include <string>
int main(){
    Hash<string> t; 
    ifstream arch;
    string text, text1;
    string car;
    int opcion=0;
    while (opcion != 6){
        cout << "1--INSERTAR: " << endl;
        cout << "2--ELIMINAR: " << endl;
        cout << "3--BUSCAR: " << endl;
        cout << "4--CONTAR COLISIONES: " << endl;
        cout << "5--MOSTRAR: " << endl;
        cout << "6--SALIR: " << endl;
        cout << "SELEC OPCION: ";
        cin >> opcion;
        switch (opcion){
        case 1:
            arch.open("diccionario.txt");
            while (!arch.eof() && getline(arch, car)){
                t.Insert(car);
            }
            arch.close();
            break;
        case 2:        
            cout << "Ingrese el elemento a Borrar:"; cin >> text;
            t.Delete(text);
            break;
        case 3:           
            cout << "Ingrese el elemento a Buscar:"; cin >> text1;
            cout << "El elemtno buscado es: " << t.Search(text1) << endl;
            break;
        case 4:     
            t.contarColisiones();
            break;
        case 5:
            t.display();
            break;
        }
    }          
}


