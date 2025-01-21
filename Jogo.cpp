#include "Jogo.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Jogo::Jogo(){
}

Jogo::Jogo(int numJogadores, const vector<string>& nomesJogadores) : jogadorAtual(0), direcao(1) {
    for (int i = 0; i < numJogadores; ++i) {
        jogadores.emplace_back(nomesJogadores[i], i + 1);
    }

    baralho.embaralhar();

    for (auto& jogador : jogadores) {
        for (int j = 0; j < 7; ++j) {
            jogador.adicionarCarta(baralho.comprarCarta());
        }
    }

    do {
        cartaAtual = baralho.comprarCarta();
    } while (cartaAtual.getTipo() == "Coringa" || cartaAtual.getTipo() == "+4");
}

void Jogo::iniciar() {
    cout << "Jogo iniciado! A carta atual é: ";
    cartaAtual.exibir();
}

void Jogo::executarTurno() {
    Jogador& jogador = jogadores[jogadorAtual];

    cout << "Turno de " << jogador.getNome() << "!" << endl;
    jogador.mostrarMao();

    if (jogador.podeJogar(cartaAtual)) {
        int indice;
        cout << "Escolha uma carta para jogar (índice): ";
        cin >> indice;

        Carta jogada = jogador.jogarCarta(indice - 1);
        if (jogada.ehValida(cartaAtual)) {
            cartaAtual = jogada;
            cout << "Jogador jogou: ";
            cartaAtual.exibir();
            aplicarEfeito(cartaAtual);
        } else {
            cout << "Jogada inválida! Perdeu a vez." << endl;
            jogador.adicionarCarta(jogada);
        }
    } else {
        cout << "Nenhuma carta válida. Comprando uma carta..." << endl;
        jogador.adicionarCarta(baralho.comprarCarta());
    }

    if (verificarVitoria()) {
        cout << "Jogador " << jogador.getNome() << " venceu!" << endl;
        exit(0);
    }

    jogadorAtual = (jogadorAtual + direcao + jogadores.size()) % jogadores.size();
}


bool Jogo::verificarVitoria() {
    for (const auto& jogador : jogadores) {
        if (jogador.getMao().empty()) {
            return true;
        }
    }
    return false;
}


void Jogo::aplicarEfeito(const Carta& carta) {
    if (carta.getTipo() == "+2") {
        int proximo = (jogadorAtual + direcao + jogadores.size()) % jogadores.size();
        jogadores[proximo].adicionarCarta(baralho.comprarCarta());
        jogadores[proximo].adicionarCarta(baralho.comprarCarta());
    } else if (carta.getTipo() == "Inverter") {
        direcao *= -1;
    } else if (carta.getTipo() == "Pular") {
        jogadorAtual = (jogadorAtual + direcao + jogadores.size()) % jogadores.size();
    }
}

void Jogo::exibirEstado() const {
    cout << "Carta no descarte: ";
    cartaAtual.exibir();
    cout << "Jogador atual: " << jogadores[jogadorAtual].getNome() << endl;
}
