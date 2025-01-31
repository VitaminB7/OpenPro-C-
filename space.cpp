#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

using namespace std;

class Player
{ 
public: 

    int HP;
    int HPmax;

    Player(){
        HPmax=10;
        HP=HPmax;
    }

};

class Enemy
{
public: 
     
    int HP;
    int HPmax;
    
    Enemy(){
        HPmax=3;//enemy true hp +1 
        HP=HPmax;
    }

};

int main()
{
    sf::ContextSettings setting;
    setting.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800,800}),"Orbital", sf::State::Windowed, setting);
    window.setFramerateLimit(60);



    //texture
    sf::Texture playerTexture("SpaceShooterShipConstructor/PNG/Example/01.png");
    sf::Texture enemyTexture("SpaceShooterShipConstructor/PNG/Example/05.png");
    sf::Texture bulletTexture("SpaceShooterShipConstructor/PNG/Bullets/01.png");
        

    
    //player
    Player player;
    sf::Sprite playerShape(playerTexture);
    playerShape.setScale({0.5f,0.5f});



    //enemy
    Enemy e1;
    sf::Sprite enemyShape(enemyTexture);
    enemyShape.scale({0.8f,0.8f});
    int enemySpawnTimer=20;
    std::vector<sf::Sprite> vEnemyTexture;
    std::vector<Enemy> vEnemyHP;
    
    
    //bullet
    sf::Sprite bulletShape(bulletTexture);
    std::vector<sf::Sprite> vBullet;
    
    int shootTimer = 100;

//***************************************************************************************** 
    while (window.isOpen())
        {
            while(std::optional event = window.pollEvent())
            {
                //close
                if(event->is<sf::Event::Closed>()) window.close();
            }

        //update
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        playerShape.move({0.f,-10.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        playerShape.move({-10.f,0.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        playerShape.move({0.f,10.f});
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        playerShape.move({10.f,0.f});

        if(playerShape.getPosition().x <= 0) playerShape.setPosition({0.f,playerShape.getPosition().y});//left
        if(playerShape.getPosition().x + playerShape.getGlobalBounds().size.x  >= window.getSize().x) playerShape.setPosition({window.getSize().x - playerShape.getGlobalBounds().size.x ,playerShape.getPosition().y});//right
        if(playerShape.getPosition().y <= 0) playerShape.setPosition({playerShape.getPosition().x,0.f});//top
        if(playerShape.getPosition().y + playerShape.getGlobalBounds().size.y >= window.getSize().y) playerShape.setPosition({playerShape.getPosition().x,window.getSize().y - playerShape.getGlobalBounds().size.y});//bottom

        if(shootTimer < 10) shootTimer++;

        //shoot
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && shootTimer >=10)
        {
            vBullet.push_back(bulletShape);
            vBullet.back().setScale({0.5,0.5});
            vBullet.back().setPosition(playerShape.getPosition());
            shootTimer = 0;
        }
        
        //clear
        window.clear(sf::Color(124,124,124));
        //draw
        window.draw(playerShape);

            //EnemySpawn 
        if(enemySpawnTimer<200) enemySpawnTimer++;
        if(enemySpawnTimer>=200) 
        {
        enemySpawnTimer=0;
        vEnemyTexture.push_back(enemyShape);
        vEnemyHP.push_back(e1);
        float R = rand()%(int)window.getSize().x ;
        if(R > window.getSize().x/2) R-= enemyShape.getGlobalBounds().size.x;
        vEnemyTexture.back().setPosition({R ,0.f}); 

        };
            //Enemy
        for (int i = 0; i < vEnemyTexture.size() ; i++)
        {
            window.draw(vEnemyTexture[i]);//draw
            vEnemyTexture[i].move({0.f,2.f});//move
            //collision
            if(vEnemyTexture[i].getGlobalBounds().findIntersection(playerShape.getGlobalBounds())) {vEnemyTexture.erase(vEnemyTexture.begin()+i); vEnemyHP.erase(vEnemyHP.begin()+i); player.HP--; break;} //player
            if(vEnemyTexture[i].getPosition().y>window.getSize().y){vEnemyTexture.erase(vEnemyTexture.begin()+i); vEnemyHP.erase(vEnemyHP.begin()+i); break;} //pass
            
        }
        
            //Bullet
        for (int i = 0; i < vBullet.size() ; i++)
        {
            window.draw(vBullet[i]);
            vBullet[i].move({0.f,-10.f});
            //out
            if(vBullet[i].getPosition().y <= -10) {vBullet.erase(vBullet.begin() + i); break;}
              
                //enemy collision
            
            for (int k = 0; k < vEnemyTexture.size(); k++)
            {
                if(vBullet[i].getGlobalBounds().findIntersection(vEnemyTexture[k].getGlobalBounds()))
                {
                    if (vEnemyHP[k].HP<=0)
                    {
                        vEnemyTexture.erase(vEnemyTexture.begin()+k); vEnemyHP.erase(vEnemyHP.begin()+k); //die
                    }
                    else
                    {
                        vEnemyHP[k].HP--;//dmg
                    }
                    if (vEnemyHP[k].HP<=0)
                    {
                        vEnemyTexture.erase(vEnemyTexture.begin()+k); vEnemyHP.erase(vEnemyHP.begin()+k); //die
                    }
                    
                    vBullet.erase(vBullet.begin() + i);
                    break;
                }
            }
        }

        window.display();
       
        }

    return 0;

}