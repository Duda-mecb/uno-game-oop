#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED

#include "Baralho.h"
#include "Carta.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Jogador{
private:
    vector<Carta> mao;
    string nome;
    int id;

public:
    Jogador();
    Jogador(const string& nome, int id);

    void adicionarCarta(const Carta& carta);
    void removerCarta(int indice);
    Carta jogarCarta(int indice);
    bool podeJogar(const Carta& cartaAtual);

    void mostrarMao() const;

    string getNome() const;
    int getId() const;
    const vector<Carta>& getMao() const;


};

#endif
