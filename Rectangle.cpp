#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800,600}), "First game");//window

    sf::RectangleShape rectangle({400.f, 200.f});//rectangle

    //corners
    sf::RectangleShape topLeft({200.f,100.f});

    sf::RectangleShape topRight({200.f,100.f});
    topRight.setOrigin({200.f,0.f});
   
    sf::RectangleShape bottomLeft({200.f,100.f});
    bottomLeft.setOrigin({0,100.f});
    
    sf::RectangleShape bottomRight({200.f,100.f});
    bottomRight.setOrigin({200.f,100.f});
    
    //edges
    sf::RectangleShape top({200.f,100.f});
    top.setOrigin({100.f,0.f});

    sf::RectangleShape bottom({200.f,100.f});
    bottom.setOrigin({100.f,100.f});

    sf::RectangleShape left({200.f,100.f});
    left.setOrigin({0.f,50.f});

    sf::RectangleShape right({200.f,100.f});
    right.setOrigin({200.f,50.f});

    //center
    sf::RectangleShape center({200.f,100.f});
    center.setOrigin({100.f,50.f});



    //order --> scale rotate translate
    rectangle.setOrigin({200.f,100.f});//origin
    rectangle.setPosition({200.f,100.f});
    rectangle.setRotation(sf::degrees(30.f));
    //rectangle.setScale({1.5f,1.f});
    rectangle.setPosition({400.f,300.f});

    rectangle.setFillColor(sf::Color(255,216,38));//color
    rectangle.setOutlineThickness(-5.f);//outline
    rectangle.setOutlineColor(sf::Color(50,123,90));
    
    while (window.isOpen())
    {
        while(std::optional event = window.pollEvent())
        {
            //close
            if(event->is<sf::Event::Closed>()) window.close();
            else if(event->is<sf::Event::Resized>()) {
                //std::cout << "Window " << window.getSize().x << " , " << window.getSize().y << '\n'; 
                //std::cout << "View " << window.getView().getSize().x << " , " << window.getView().getSize().y << '\n';   
                sf::View view(sf::FloatRect({0.f,0.f}, sf::Vector2f(window.getSize()))); //top left lock
                //sf::View view({400.f,300.f}, sf::Vector2f(window.getSize()));//lock center at 400,300
                window.setView(view);
            }
        }

        window.clear(sf::Color(124,124,124));//clear


        //set position
        float window_w = static_cast<float>(window.getSize().x);
        float window_h = static_cast<float>(window.getSize().y);

        topRight.setPosition({window_w, 0.f});
        bottomLeft.setPosition({0.f, window_h});
        bottomRight.setPosition({window_w, window_h});

        top.setPosition({window_w/2,0.f});
        bottom.setPosition({window_w/2,window_h});
        left.setPosition({0.f,window_h/2});
        right.setPosition({window_w,window_h/2});
        
        center.setPosition({window_w/2,window_h/2});



        //window.draw(rectangle);
        window.draw(topLeft);
        window.draw(topRight);
        window.draw(bottomLeft);
        window.draw(bottomRight);

        window.draw(top);
        window.draw(bottom);
        window.draw(left);
        window.draw(right);

        window.draw(center);


        window.display();//finish

    }

    

    return 0;
}