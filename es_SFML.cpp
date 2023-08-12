#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp> //per i threads

int main() {
     sf::RenderWindow nome_finestra(sf::VideoMode(1000,500),"finestra");
     nome_finestra.setPosition(sf::Vector2i(100,100));  
     nome_finestra.setVerticalSyncEnabled(true);
     nome_finestra.setFramerateLimit(60);

//per disgnare un testo
/*  sf::Font font;
    font.loadFromFile("./font/grasping.ttf");
    sf::Text stringa;
    stringa.setFont(font);
    stringa.setString("caccamerda");
    stringa.setCharacterSize(100);
    stringa.setFillColor(sf::Color::Red);
    stringa.setPosition(80,80);

    //in più aggiungo "nome_finestra.draw(stringa);" tra clear() e display() 
*/
    while (nome_finestra.isOpen())
    {
        sf::Event event;

        while (nome_finestra.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                nome_finestra.close();
            }
        }
        nome_finestra.clear();
    //nome_finestra.draw(stringa);
        nome_finestra.display();
    }

 
}