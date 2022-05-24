#include <iostream>
using namespace std;

enum TipoPalo {Espada, Oro, Basto, Copa};

struct Carta{
	TipoPalo palo;
	int valor;
};

struct Mazo{
	int cantidadCartas;
	Carta** cartas;
};

void DestruirMazoCartas(Mazo* mazo);
void MostrarMazo(Mazo* mazo);
void InicializarMazoEspanolPorPalo(Mazo* mazoEspanol, int indiceCarta, TipoPalo palo);
void InicializarMazoTrucoPorPalo(Mazo* mazo, int indiceCarta, TipoPalo palo);
Mazo* CrearMazoEspanol();
Mazo* CrearMazoTruco();

int main() {
	Mazo* mazoEspanol = CrearMazoEspanol();
    Mazo* mazoTruco = CrearMazoTruco();
	MostrarMazo(mazoEspanol);
    MostrarMazo(mazoTruco);
    DestruirMazoCartas(mazoEspanol);
    DestruirMazoCartas(mazoTruco);
	return 0;
}

void DestruirMazoCartas(Mazo* mazo){
    if(mazo != NULL){
    	//delete[] mazo;
    	for(int i=0; i < mazo->cantidadCartas; ++i){
    		delete mazo->cartas[i];
    	}
        delete mazo;
    }
}

void MostrarCarta(Carta* cartas){
	switch(cartas->palo){
		case Espada:
			cout<<"Espada";
			break;
		case Oro:
			cout<<"Oro";
			break;
		case Copa:
			cout<<"Copa";
			break;
		case Basto:
			cout<<"Basto";
			break;
		default:
			break;
	}
}

void MostrarMazo(Mazo* mazo){
	for(int i=0; i<mazo->cantidadCartas; ++i){
		cout<<"["<<mazo->cartas[i]->valor<<"]";
	    MostrarCarta(mazo->cartas[i]);
	    if(((i+1)%(mazo->cantidadCartas/4)) == 0)
		   cout<<endl;
	    else
	       cout<<" -> ";
	}
	cout<<"==============================================================================================================="<<endl;
}

void InicializarMazoEspanolPorPalo(Mazo* mazoEspanol, int indiceCarta, TipoPalo palo){
	for(int i = 0 ; i < 12; ++i){
		mazoEspanol->cartas[i+indiceCarta] = new Carta;
		mazoEspanol->cartas[i+indiceCarta]->palo= palo;
		mazoEspanol->cartas[i+indiceCarta]->valor = i + 1;
	}
}

void InicializarMazoTrucoPorPalo(Mazo* mazoTruco, int indiceCarta, TipoPalo palo){
	for(int i=0; i<10;++i){
		mazoTruco->cartas[i+indiceCarta] = new Carta;
		if(i>=7){
			mazoTruco->cartas[i+indiceCarta]->palo = palo;
			mazoTruco->cartas[i+indiceCarta]->valor = i + 3;
		}else{
			mazoTruco->cartas[i+indiceCarta]->palo = palo;
			mazoTruco->cartas[i+indiceCarta]->valor = i + 1;
		}
	}
}

Mazo* CrearMazoEspanol(){
	Mazo* mazo = new Mazo;
	mazo->cantidadCartas = 48;
	mazo->cartas = new Carta*[48];
	InicializarMazoEspanolPorPalo(mazo, 0, Espada);
	InicializarMazoEspanolPorPalo(mazo, 12, Oro);
	InicializarMazoEspanolPorPalo(mazo, 24, Basto);
	InicializarMazoEspanolPorPalo(mazo, 36, Copa);
	return mazo;
}

Mazo* CrearMazoTruco(){
	Mazo* mazoTruco = new Mazo;
	mazoTruco->cantidadCartas = 40;
	mazoTruco->cartas = new Carta*[mazoTruco->cantidadCartas];
	InicializarMazoTrucoPorPalo(mazoTruco, 0, Espada);
	InicializarMazoTrucoPorPalo(mazoTruco, 10, Oro);
	InicializarMazoTrucoPorPalo(mazoTruco, 20, Basto);
	InicializarMazoTrucoPorPalo(mazoTruco, 30, Copa);
	return mazoTruco;
}
