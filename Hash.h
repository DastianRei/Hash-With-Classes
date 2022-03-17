#pragma once
#include "List.h"
#define TAM 28411 
template <class T>
class Hash{
private:
	List<T> TH[TAM];
	int colisiones[100];
public:
	Hash();
	~Hash();
	void Insert(T elem);
	void Delete(T elem);
	T Search(T elem);
	int long long CharToInt(char car){
		unsigned long long output=car;	
		return output;
	}
	int long long getNum(string text){
		unsigned long long output = 0;
		for (int i = 0; text[i] != '\0'; i++){
			if (text[i + 1] == '\0' && i == 0) { 
				output += CharToInt(text[i]); 
			}	
			else{
				if (i == 0){
					output += CharToInt(text[i]);
					continue;
				}
				else{
					int miChar = CharToInt(text[i]);
					if (miChar > 99){
						output *= 1000;
					}
					else if (miChar > 9){
						output *= 100;
					}
					output += miChar;
				}
			}
		}
		return output;
	}
	int ReturnPos(int x){
		return x % TAM;
	}
	int ReturnPos(string text){
		int num = getNum(text);
		return num % TAM;
	}
	void display();
	void contarColisiones();
};
template <class T>
Hash<T>::Hash(){
	
}
template <class T>
Hash<T>::~Hash(){
	
}
template <class T>
void Hash<T>::Insert(T elem){
	int index = ReturnPos(elem);
	if (index < 0){
		index = index * -1;
	}
	TH[index].pushFront(elem);	
}
template <class T>
void Hash<T>::Delete(T elem)
{
	int index = ReturnPos(elem);
	TH[index].DeleteElem(elem);
}
template <class T>
T Hash<T>::Search(T elem){
	T dato;
	int index = ReturnPos(elem);
	dato=TH[index].SearchNoRec(elem);
	return dato;
}
template <class T>
void Hash<T>::display(){
	for (int i = 0; i < TAM; i++){
		cout << i<<": ==> ";
		TH[i].showList();
		cout << endl;
	}
}
template <class T>
void Hash<T>::contarColisiones(){
	int cont=0;
	int total = 0;
	for (int i = 0; i < 100; i++){
		colisiones[i] = 0;
	}
	for (int i = 0; i < TAM; i += 1){
		Node<T>* aux = TH[i].getFirst();
		while (aux!= NULL){
			cont += 1;
			aux = aux->getSig();
		}
		colisiones[cont] += 1;
		total = total + cont;
		cont = 0;
	}
	for (int i = 0; i < 100; i++){
		cout << "["<<i<<"]"<<"==> "<<colisiones[i] <<" Atributes"<< endl;
	}
	cout <<"Total of words : "<< total<<endl;
}