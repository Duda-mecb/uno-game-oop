#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "UNO");

    // carregar imagem da carta
    sf::Texture cardTexture;
    if (!cardTexture.loadFromFile("carta uno.jpeg")) {
        std::cerr << "Erro ao carregar a textura da carta!" << std::endl;
        return -1;
    }

    // configurar o sprite da carta
    sf::Sprite cardSprite;
    cardSprite.setTexture(cardTexture);

    // escala da carta
    float scaleFactor = 0.3f; 
    cardSprite.setScale(scaleFactor, scaleFactor);

    // centralizar
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;
    float cardWidth = cardTexture.getSize().x * scaleFactor;
    float cardHeight = cardTexture.getSize().y * scaleFactor;

    cardSprite.setPosition(
        (windowWidth - cardWidth) / 2,  
        windowHeight - cardHeight - 20 
    );

    // loop principal do jogo
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(cardSprite);

        window.display();
    }

    return 0;
}
