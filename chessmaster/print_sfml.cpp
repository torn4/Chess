#include <SFML/Graphics.hpp>
#include <iostream>
#include "chessboard.h"
#include "whiteRook.h"


void print_function(sf::RenderWindow &window, int start)
{

 int test; //Funktion som hittar rätt kordinat
 test=56;
 if(test%8==0){
 std::cout<<"Height is: "<<test/8-1<<std::endl;
  std::cout<<"width is: "<<7<<std::endl;
 } else{ //0 index board
  std::cout<<"Number is: "<<test <<std::endl;
 std::cout<<"Height is: "<<test/8<<std::endl;
 std::cout<<"width is: "<<test%8-1<<std::endl;
 }
        sf::Sprite whiteRookn;
        sf::Sprite spriteBoard;
        whiteRook wr;
        whiteRookn = wr.wksetvar();

        chessBoard cb;
        if(start){
                std::cout<<"First print"<<std::endl;
        spriteBoard = cb.chessBoardsetvar();

        cb.boardDraw(window,spriteBoard);


        whiteRookn = wr.wksetPos(0,7,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteRook.png");
        whiteRookn = wr.wksetPos(7,7,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteRook.png");
        //White bonds
        whiteRookn = wr.wksetPos(7,6,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(6,6,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(5,6,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(4,6,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(3,6,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(2,6,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(1,6,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(0,6,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        //WhiteBishop
        whiteRookn = wr.wksetPos(5,7,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteBishop.png");
        whiteRookn = wr.wksetPos(2,7,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteBishop.png");
        //White knight
        whiteRookn = wr.wksetPos(6,7,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteKnight.png");
        whiteRookn = wr.wksetPos(1,7,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteKnight.png");
        //White king and queen
        whiteRookn = wr.wksetPos(4,7,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteKing.png");
        whiteRookn = wr.wksetPos(3,7,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteQueen.png");
//Svarta pjäser
////////////
        whiteRookn = wr.wksetPos(0,0,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackRook.png");
        whiteRookn = wr.wksetPos(7,0,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackRook.png");
        //White bonds
        whiteRookn = wr.wksetPos(7,1,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(6,1,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(5,1,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(4,1,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(3,1,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(2,1,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(1,1,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(0,1,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        //WhiteBishop
        whiteRookn = wr.wksetPos(5,0,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackBishop.png");
        whiteRookn = wr.wksetPos(2,0,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackBishop.png");
        //White knight
        whiteRookn = wr.wksetPos(6,0,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackKnight.png");
        whiteRookn = wr.wksetPos(1,0,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackKnight.png");
        //White king and queen
        whiteRookn = wr.wksetPos(4,0,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackKing.png");
        whiteRookn = wr.wksetPos(3,0,whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackQueen.png");
            window.display();
        }
        }
