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

Carta* CrearCarta(int valor, TipoPalo palo);
Carta* CrearCartaTruco(int numero, TipoPalo palo)
void DestruirMazoCartas(Mazo* mazo);
void MostrarMazo(Mazo* mazo);
void CrearCartasEspanolasPorPalo(Carta** cartas, TipoPalo palo);
void CrearCartasTrucoPorPalo(Carta** cartas, TipoPalo palo);
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
			cout<<"Esp.";
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
	cout<<endl;
	for(int i=0; i<mazo->cantidadCartas; ++i){
		cout<<"["<<mazo->cartas[i]->valor<<"]";
	    MostrarCarta(mazo->cartas[i]);
	    if(((i+1)%(mazo->cantidadCartas/4)) == 0)
		   cout<<endl;
	    else
	       cout<<" -> ";
	}
	cout<<endl<<"==========================================================="<<endl<<endl;
}

void CrearCartasEspanolasPorPalo(Carta** cartas, TipoPalo palo){
	for(int i = 0 ; i < 12; ++i){
		cartas[i] = CrearCarta(i+1, palo);
		//cartas[i]->palo= palo;
		//cartas[i]->valor = i + 1;
	}
}


Carta* CrearCarta(int valor, TipoPalo palo) {
	Carta* nuevaCarta = NULL;
	nuevaCarta = new Carta;
	nuevaCarta->valor = valor;
	nuevaCarta->palo = palo;
	return nuevaCarta;
}

Carta* CrearCartaTruco(int numero, TipoPalo palo){
	return CrearCarta(numero + (numero > 7 ? 2 : 0), palo);
}

void CrearCartasTrucoPorPalo(Carta** cartas, TipoPalo palo){
	for(int i=0; i<10; ++i){
		cartas[i] = CrearCartaTruco(i+1, palo);
	}
}

Mazo* CrearMazoEspanol(){
	Mazo* mazoEspanol = new Mazo;
	mazoEspanol->cantidadCartas = 48;
	mazoEspanol->cartas = new Carta*[mazoEspanol->cantidadCartas];
	CrearCartasEspanolasPorPalo(mazoEspanol->cartas, Espada);
	CrearCartasEspanolasPorPalo(&mazoEspanol->cartas[12], Oro);
	CrearCartasEspanolasPorPalo(&mazoEspanol->cartas[24], Basto);
	CrearCartasEspanolasPorPalo(&mazoEspanol->cartas[36], Copa);
	return mazoEspanol;
}

Mazo* CrearMazoTruco(){
	Mazo* mazoTruco = new Mazo;
	mazoTruco->cantidadCartas = 40;
	mazoTruco->cartas = new Carta*[mazoTruco->cantidadCartas];
	CrearCartasTrucoPorPalo(mazoTruco->cartas, Espada);
	CrearCartasTrucoPorPalo(&mazoTruco->cartas[10], Oro);
	CrearCartasTrucoPorPalo(&mazoTruco->cartas[20], Basto);
	CrearCartasTrucoPorPalo(&mazoTruco->cartas[30], Copa);
	return mazoTruco;
}
