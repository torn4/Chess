#include <SFML/Graphics.hpp>
#include <iostream>
#include "WhiteKing.h"
#include "chessboard.h"
#include "WhiteBishop.h"
#include "whiteKnight.h"
#include "whitePawn.H"
#include "whiteQueen.h"
#include "whiteRook.h"


int main()
{
     sf::Sprite whiteKingn;
     sf::Sprite whiteKnightn;
     sf::Sprite whiteBishopn;
     sf::Sprite whitePawnn;
     sf::Sprite whiteQueenn;
     sf::Sprite whiteRookn;
     sf::Sprite spriteBoard;

sf::RenderWindow window(sf::VideoMode(675, 675), "Playing board");// Rutan som brädet ska ligga i


whiteRook wr;
whiteRookn = wr.wksetvar();

whiteQueen wq;
whiteQueenn = wq.wksetvar();

whitePawn wp;
whitePawnn = wp.wksetvar();

whiteKing wk;
whiteKingn=wk.wksetvar();

whiteBishop wb;
whiteBishopn = wb.wksetvar();

whiteKnight wkn;
whiteKnightn = wkn.wksetvar();

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

       //Vita torn
        whiteRookn = wr.wksetPos(0,7,whiteRookn);
       wr.wkdraw(window,whiteRookn);

       whiteRookn = wr.wksetPos(7,7,whiteRookn);
       wr.wkdraw(window,whiteRookn);
       //Vit drottning
       whiteQueenn = wq.wksetPos(3,7,whiteQueenn);
       wq.wkdraw(window,whiteQueenn);
  //Vita bönder
       whitePawnn=wp.wksetPos(0,6,whitePawnn);
       wp.wkdraw(window,whitePawnn);

       whitePawnn=wp.wksetPos(1,6,whitePawnn);
       wp.wkdraw(window,whitePawnn);

       whitePawnn=wp.wksetPos(2,6,whitePawnn);
       wp.wkdraw(window,whitePawnn);

       whitePawnn=wp.wksetPos(3,6,whitePawnn);
       wp.wkdraw(window,whitePawnn);

       whitePawnn=wp.wksetPos(4,6,whitePawnn);
       wp.wkdraw(window,whitePawnn);

       whitePawnn=wp.wksetPos(5,6,whitePawnn);
       wp.wkdraw(window,whitePawnn);

       whitePawnn=wp.wksetPos(6,6,whitePawnn);
       wp.wkdraw(window,whitePawnn);

       whitePawnn=wp.wksetPos(7,6,whitePawnn);
       wp.wkdraw(window,whitePawnn);

// Vita hästar
       whiteKnightn=wkn.wksetPos(1,7,whiteKnightn);
       wkn.wkdraw(window,whiteKnightn);

       whiteKnightn=wkn.wksetPos(6,7,whiteKnightn);
       wkn.wkdraw(window,whiteKnightn);
// Vita löpare

        whiteBishopn= wb.wksetPos(5,7,whiteBishopn);
        wb.wkdraw(window,whiteBishopn);

        whiteBishopn= wb.wksetPos(2,7,whiteBishopn);
        wb.wkdraw(window,whiteBishopn);
// vit kung
        whiteKingn =  wk.wksetPos(4,7,whiteKingn);
        wk.wkdraw(window,whiteKingn );
      //
        window.display();
    }

    return 0;
}
