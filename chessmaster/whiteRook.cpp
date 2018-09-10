
#include <SFML/Graphics.hpp>
#include <iostream>
#include "whiteRook.h"



sf::Sprite whiteRook::wksetvar()   //Här måste vi returna sf::sprite
{
              sf::Image whiteKnight;
        if (!(whiteKnight.loadFromFile("../Figures/whiteRook.png")))
                std::cout << "Cannot load whiteKing image"; //Load Image

        sf::Texture textureWhiteKnight;   //Load Texture from image
        textureWhiteKnight.loadFromImage(whiteKnight);
        sf::Sprite spriteWhiteKnight;
        spriteWhiteKnight.setTexture(textureWhiteKnight);
      return spriteWhiteKnight;

}

 sf::Sprite whiteRook::wksetPos(int number, sf::Sprite &spriteWhiteKnight)const{ //Här måste vi returna sf::sprite
     int height;
     int width;
    if(number%8==0){
    width=7;
    height = number/8-1;
    } else{ //0 index board
    width = number%8-1;
    height = number/8;
    }
spriteWhiteKnight.setPosition(84.375*width+12,84.375*height+12);
return spriteWhiteKnight;

}

 void whiteRook::wkdraw(sf::RenderWindow &window,const  sf::Sprite &spriteWhiteKnight,const char* piece){ //Här ska inget returnas

        sf::Image whiteKnight;
        if (!(whiteKnight.loadFromFile(piece)))
        std::cout << "Cannot load whiteKing image"; //Load Image

        sf::Texture textureWhiteKnight;   //Load Texture from image
        textureWhiteKnight.loadFromImage(whiteKnight);
window.draw(spriteWhiteKnight);

}
