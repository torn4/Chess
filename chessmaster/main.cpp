#include <SFML/Graphics.hpp>
#include <iostream>
#include "WhiteKing.h"
#include "chessboard.h"




int main()
{
     sf::Sprite whiteKnightn;
     sf::Sprite spriteBoard;
sf::RenderWindow window(sf::VideoMode(675, 675), "Playing board");// Rutan som brädet ska ligga i

whiteKnight wk;
whiteKnightn=wk.wksetvar();

chessBoard cb;
spriteBoard = cb.chessBoardsetvar();
    while (window.isOpen())
    {

     sf::Event event;


                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();

                        }//Event handling done

        window.clear();
       cb.boardDraw(window,spriteBoard);

        whiteKnightn =  wk.wksetPos(3,7,whiteKnightn);
        wk.wkdraw(window,whiteKnightn );
      //
        window.display();
    }

    return 0;
}
