#include <SFML/Graphics.hpp>
#include <iostream>
#include "WhiteKing.h"




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
        whiteKnightn =  wk.wksetPos(5,5,whiteKnightn);
        wk.wkdraw(window,whiteKnightn );
      //
        window.display();
    }

    return 0;
}
