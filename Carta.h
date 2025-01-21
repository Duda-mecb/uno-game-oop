#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta{

private:
  string tipo;
  string cor;
  int valor;

public:
  Carta();
  Carta(const string& cor, const string& tipo, int valor);

  string getTipo() const;
  string getCor() const;
  int getValor() const;

  bool ehValida(const Carta& outraCarta) const;

  void exibir() const;

};

 #endif
