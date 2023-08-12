#include<iostream>
#include<SFML/Graphics.hpp>
#include "complex.hpp"

void fun(){
    
}

int main(){
    sf::RenderWindow window(sf::VideoMode(1000,500),"finestra");
     window.setPosition(sf::Vector2i(100,100));  
     window.setVerticalSyncEnabled(true);
     window.setFramerateLimit(60);



    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();

        window.display();
    }
}