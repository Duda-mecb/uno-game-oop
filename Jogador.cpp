#include "Jogador.h"
#include "Carta.h"

#include <iostream>

using namespace std;

Jogador::Jogador() : nome("Anônimo"), id(0) {}

Jogador::Jogador(const string& nome, int id) : nome(nome), id(id) {}

void Jogador::adicionarCarta(const Carta& carta){
    mao.push_back(carta);
}

void Jogador::removerCarta(int indice){
    if (indice >= 0 && indice < static_cast<int>(mao.size())){
        mao.erase(mao.begin() + indice);
    }else{
        cout << "Índice inválido para remoção de carta!" << endl;
    }
}

Carta Jogador::jogarCarta(int indice){
    if (indice >= 0 && indice < static_cast<int>(mao.size())){
        Carta carta = mao[indice];
        removerCarta(indice);

        return carta;
    }
    throw out_of_range("Índice inválido para jogar carta.");
}

bool Jogador::podeJogar(const Carta& cartaAtual){
    for (const auto& carta : mao){
        if (carta.ehValida(cartaAtual)){
            return true;
        }
    }
    return false;
}

void Jogador::mostrarMao() const {
    cout << "Mão de " << nome << ":" << endl;
    for (size_t i = 0; i < mao.size(); ++i){
        cout << i + 1 << ". ";
        mao[i].exibir();
    }
}

string Jogador::getNome() const {
    return nome;
}

int Jogador::getId() const {
    return id;
}
