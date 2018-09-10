#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "button_press.h"
#include <cmath>

   std::vector<int> find_button_pos(sf::RenderWindow &window, const sf::Event &event,std::map<std::string,int> memory_map )
   {
std::vector<int> xy(2);
 sf::Vector2i pixelPos= sf::Mouse::getPosition(window);
int chess_place;
    float x=99999;
    float y=99999;

    sf::Vector2i pixelPospress;
        sf::Vector2i pixelPosres;

    if (event.type == sf::Event::MouseButtonPressed && pixelPos != pixelPospress){
        sf::Vector2i pixelPospress = sf::Mouse::getPosition(window);
        x=pixelPospress.x;
        y=pixelPospress.y;
        chess_place = round((y-42)/84.375)*8+round((x-42)/84.375)+1;

      //  std::cout<<"Pressed at x,y :"<<round((x-42)/84.375)<<"."<<round((y-42)/84.375)<<std::endl;
      std::cout<<chess_place<<::std::endl;
       } else if(event.type == sf::Event::MouseButtonReleased && pixelPos != pixelPosres ){

        sf::Vector2i pixelPosres = sf::Mouse::getPosition(window);
        x=pixelPosres.x;
        y=pixelPosres.y;
        chess_place = round((y-42)/84.375)*8+round((x-42)/84.375)+1;
        std::cout<<chess_place<<::std::endl;
       // std::cout<<"Released at x,y :"<<round((x-42)/84.375)<<"."<<round((y-42)/84.375)<<std::endl;
       }



       return xy;
    }
