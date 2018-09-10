#include <SFML/Graphics.hpp>
#include <iostream>
#include "chessboard.h"
#include "whiteRook.h"


void print_function(sf::RenderWindow &window, int start,std::map<std::string,int> memory_map )
{

        sf::Sprite whiteRookn;
        sf::Sprite spriteBoard;
        whiteRook wr;
        whiteRookn = wr.wksetvar();
        int width;
        int height;
        int number;
        chessBoard cb;
        if(start){
            //    std::cout<<"First print"<<std::endl;
        spriteBoard = cb.chessBoardsetvar();

        cb.boardDraw(window,spriteBoard);

//number = memory_map["wr1"];


        whiteRookn = wr.wksetPos(memory_map["wr1"],whiteRookn); //Width & height
        wr.wkdraw(window,whiteRookn,"../Figures/whiteRook.png");

        whiteRookn = wr.wksetPos(memory_map["wr2"],whiteRookn); //Width & height
        wr.wkdraw(window,whiteRookn,"../Figures/whiteRook.png");
        //White bonds
        whiteRookn = wr.wksetPos(memory_map["wp8"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(memory_map["wp7"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(memory_map["wp6"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(memory_map["wp5"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(memory_map["wp4"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(memory_map["wp3"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(memory_map["wp2"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        whiteRookn = wr.wksetPos(memory_map["wp1"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whitePawn.png");
        //WhiteBishop
        whiteRookn = wr.wksetPos(memory_map["wb2"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteBishop.png");
        whiteRookn = wr.wksetPos(memory_map["wb1"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteBishop.png");
        //White knight
        whiteRookn = wr.wksetPos(memory_map["wk1"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteKnight.png");
        whiteRookn = wr.wksetPos(memory_map["wk2"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteKnight.png");
        //White king and queen
        whiteRookn = wr.wksetPos(memory_map["wkk"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteKing.png");
        whiteRookn = wr.wksetPos(memory_map["wq"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/whiteQueen.png");
//Svarta pjäser
////////////

        whiteRookn = wr.wksetPos(memory_map["br1"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackRook.png");
        whiteRookn = wr.wksetPos(memory_map["br2"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackRook.png");
        //White bonds
        whiteRookn = wr.wksetPos(memory_map["bp8"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(memory_map["bp7"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(memory_map["bp6"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(memory_map["bp5"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(memory_map["bp4"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(memory_map["bp3"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(memory_map["bp2"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        whiteRookn = wr.wksetPos(memory_map["bp1"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackPawn.png");
        //WhiteBishop
        whiteRookn = wr.wksetPos(memory_map["bb1"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackBishop.png");
        whiteRookn = wr.wksetPos(memory_map["bb2"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackBishop.png");
        //White knight
        whiteRookn = wr.wksetPos(memory_map["bk2"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackKnight.png");
        whiteRookn = wr.wksetPos(memory_map["bk1"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackKnight.png");
        //White king and queen
        whiteRookn = wr.wksetPos(memory_map["bkk"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackKing.png");
        whiteRookn = wr.wksetPos(memory_map["bq"],whiteRookn);
        wr.wkdraw(window,whiteRookn,"../Figures/blackQueen.png");

            window.display();
        } //När man uppdaterar pringen


        }
