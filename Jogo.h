#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include "Carta.h"
#include "Baralho.h"
#include "Jogador.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Jogo{
private:
    Baralho baralho;
    vector<Jogador> jogadores;
    Carta cartaAtual;
    int jogadorAtual;
    int direcao;

public:
    Jogo();
    Jogo(int numJogadores, const vector<string>& nomesJogadores);

    void iniciar();
    void executarTurno();
    bool verificarVitoria();
    void aplicarEfeito(const Carta& carta);
    void exibirEstado() const;

};


#endif
