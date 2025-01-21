#include "Carta.h"
#include <iostream>
#include <string>

using namespace std;

Carta::Carta() : cor("Nenhuma"), tipo("Normal"), valor(0) {}

Carta::Carta(const string& c, const string& t, int v)
  : cor(c), tipo(t), valor(v) {}

string Carta::getCor() const {
  return cor;
}

string Carta::getTipo() const {
  return tipo;
}

int Carta::getValor() const {
  return valor;
}

bool Carta::ehValida(const Carta& outraCarta) const {
    return (cor == outraCarta.cor || tipo == outraCarta.tipo || valor == outraCarta.valor);
}

void Carta::exibir() const {
    cout << "Carta: " << cor << " " << tipo << " " << valor << endl;
}
