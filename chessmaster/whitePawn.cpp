#include <SFML/Graphics.hpp>
#include <iostream>
#include "Whitepawn.h"



sf::Sprite whitePawn::wksetvar()   //H�r m�ste vi returna sf::sprite
{
              sf::Image whiteKnight;
        if (!(whiteKnight.loadFromFile("../Figures/whitePawn.png")))
                std::cout << "Cannot load whiteKing image"; //Load Image

        sf::Texture textureWhiteKnight;   //Load Texture from image
        textureWhiteKnight.loadFromImage(whiteKnight);
        sf::Sprite spriteWhiteKnight;
        spriteWhiteKnight.setTexture(textureWhiteKnight);
      return spriteWhiteKnight;

}

 sf::Sprite whitePawn::wksetPos(int x, int y, sf::Sprite &spriteWhiteKnight)const{ //H�r m�ste vi returna sf::sprite

spriteWhiteKnight.setPosition(84.375*x+12,84.375*y+12);
return spriteWhiteKnight;

}

 void whitePawn::wkdraw(sf::RenderWindow &window,const  sf::Sprite &spriteWhiteKnight){ //H�r ska inget returnas

        sf::Image whiteKnight;
        if (!(whiteKnight.loadFromFile("../Figures/whitePawn.png")))
        std::cout << "Cannot load whiteKing image"; //Load Image
        sf::Texture textureWhiteKnight;   //Load Texture from image
        textureWhiteKnight.loadFromImage(whiteKnight);
window.draw(spriteWhiteKnight);

}
