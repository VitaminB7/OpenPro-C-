#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <cstdlib>
using namespace sf;

class Player
{
    int HP;
    int HPMax;
    
};
class Enemy
{

};
class Bullet
{

};

int main()
{   
    srand(time(NULL));
    RenderWindow window(sf::VideoMode({800, 600}), "SFML works!",Style::Default);
    window.setFramerateLimit(60);

    const Font font("gamefont.ttf");;
    

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        //Update
        
        //Draw
        window.display();
    }
}