#include <SFML/Graphics.hpp>
#include <iostream>
#include "function.h"

class whiteKnight{
public:
sf::Sprite wksetvar();
 sf::Sprite wksetPos(int x, int y,sf::Sprite &spriteWhiteKnight);
void wkdraw(sf::RenderWindow &window, sf::Sprite &spriteWhiteKnight);

};

sf::Sprite whiteKnight::wksetvar()   //Här måste vi returna sf::sprite
{
              sf::Image whiteKnight;
        if (!(whiteKnight.loadFromFile("../Figures/whiteKing.png")))
                std::cout << "Cannot load whiteKing image"; //Load Image

        sf::Texture textureWhiteKnight;   //Load Texture from image
        textureWhiteKnight.loadFromImage(whiteKnight);
        sf::Sprite spriteWhiteKnight;
        spriteWhiteKnight.setTexture(textureWhiteKnight);
return spriteWhiteKnight;
}

 sf::Sprite whiteKnight::wksetPos(int x, int y, sf::Sprite &spriteWhiteKnight){ //Här måste vi returna sf::sprite

spriteWhiteKnight.setPosition(84*x,84*y);
return spriteWhiteKnight;
}

 void whiteKnight::wkdraw(sf::RenderWindow &window, sf::Sprite &spriteWhiteKnight){ //Här ska inget returnas
window.draw(spriteWhiteKnight);
}


int main()
{
     sf::Sprite whiteKnightn;
    sf::RenderWindow window(sf::VideoMode(675, 675), "Playing board");// Rutan som brädet ska ligga i
//
          sf::Image board;
        if (!(board.loadFromFile("../Figures/schack.png")))
                std::cout << "Cannot load board image";   //Load Image

        sf::Texture textureBoard;   //Load Texture from image
        textureBoard.loadFromImage(board);
        sf::Sprite spriteBoard;
        spriteBoard.setTexture(textureBoard);

whiteKnight wk;
whiteKnightn=wk.wksetvar();
    while (window.isOpen())
    {

     sf::Event event;


                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();

                        }//Event handling done

        window.clear();
        window.draw(spriteBoard);
        whiteKnightn =  wk.wksetPos(2,2,whiteKnightn);
        wk.wkdraw(window,whiteKnightn );
      //
        window.display();
    }

    return 0;
}
