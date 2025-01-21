#include "Baralho.h"

#include <algorithm>
#include <random>
#include <iostream>
#include <string>

using namespace std;

Baralho::Baralho() {
  criarBaralho();

}

void Baralho::criarBaralho() {
  const vector<string> cores = {"Vermelho", "Azul", "Verde", "Amarelo"};

  for (const auto& cor : cores) {
    cartas.emplace_back(cor, "Normal", 0);

    for (int i = 1; i <= 9; i++){
      cartas.emplace_back(cor, "Normal", i);
      cartas.emplace_back(cor, "Normal", i);
    }

    for (int i = 0; i < 2; i++){
      cartas.emplace_back(cor, "+2", 0);
      cartas.emplace_back(cor, "Inverter", 0);
      cartas.emplace_back(cor, "Pular", 0);
    }

  }

  for (int i = 0; i < 4; i++){
      cartas.emplace_back("Coringa", "Coringa", 0);
      cartas.emplace_back("Coringa", "+4", 0);
  }

}

void Baralho::embaralhar() {
  random_device rd;
  mt19937 g(rd());
  shuffle(cartas.begin(), cartas.end(), g);
}

Carta Baralho::comprarCarta() {
  if (cartas.empty()) {
    throw out_of_range("O baralho está vazio!");
}
  Carta carta = cartas.back();
  cartas.pop_back();
  return carta;
}

void Baralho::mostrarBaralho() const {
    for (const auto& carta : cartas) {
        carta.exibir();
    }
}
