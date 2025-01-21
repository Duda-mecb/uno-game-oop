#ifndef BARALHO_H_INCLUDED
#define BARALHO_H_INCLUDED

#include <vector>
#include "Carta.h"

using namespace std;

class Baralho{
private:
  vector<Carta> cartas;

public:
  Baralho();

  void criarBaralho();
  void embaralhar();
  Carta comprarCarta();
  void mostrarBaralho() const;

};


#endif
