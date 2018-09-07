
#include <SFML/Graphics.hpp>
#include <iostream>
#include "WhiteBishop.h"



sf::Sprite whiteBishop::wksetvar()   //Här måste vi returna sf::sprite
{
              sf::Image whiteKnight;
        if (!(whiteKnight.loadFromFile("../Figures/whiteBishop.png")))
                std::cout << "Cannot load whiteBishop image"; //Load Image

        sf::Texture textureWhiteKnight;   //Load Texture from image
        textureWhiteKnight.loadFromImage(whiteKnight);
        sf::Sprite spriteWhiteKnight;
        spriteWhiteKnight.setTexture(textureWhiteKnight);
      return spriteWhiteKnight;

}

 sf::Sprite whiteBishop::wksetPos(int x, int y, sf::Sprite &spriteWhiteKnight)const{ //Här måste vi returna sf::sprite

spriteWhiteKnight.setPosition(84.375*x+12,84.375*y+12);
return spriteWhiteKnight;

}

 void whiteBishop::wkdraw(sf::RenderWindow &window,const  sf::Sprite &spriteWhiteKnight,bool color){ //Här ska inget returnas

        sf::Image whiteKnight;
        if (!(whiteKnight.loadFromFile("../Figures/whiteBishop.png")))
        std::cout << "Cannot load whiteKing image"; //Load Image
        sf::Texture textureWhiteKnight;   //Load Texture from image
        textureWhiteKnight.loadFromImage(whiteKnight);
window.draw(spriteWhiteKnight);

}
