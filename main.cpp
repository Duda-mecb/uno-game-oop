#include <iostream>
#include <vector>
#include "Jogo.h"

int main() {
    std::cout << "Bem-vindo ao UNO!" << std::endl;

    // Configurações iniciais do jogo
    int numJogadores = 2;
    std::vector<std::string> nomesJogadores = {"Alice", "Bob"};

    // Cria o jogo
    Jogo jogo(numJogadores, nomesJogadores);

    // Inicia o jogo
    jogo.iniciar();

    return 0;
}
