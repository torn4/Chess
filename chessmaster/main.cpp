#include <SFML/Graphics.hpp>
#include <iostream>
#include "chessboard.h"
#include "whiteRook.h"
#include "print_sfml.h"
#include "find_piece.h"
#include <string>
#include <math.h>


int main()
{

   std::map<std::string,int> memory_map;
sf::RenderWindow window(sf::VideoMode(675, 675), "Playing board");// Rutan som br�det ska ligga i
chessPieces cp;
std::string piece_name;
piece_name="bp2";
int start_print;
 start_print =1;
 window.clear();


std::cout<<cp.piece_pos(piece_name,0,1)<<std::endl; // namn p� pj�s, v�rde man ska plussa, init eller ej
    while (window.isOpen())
    {
     sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();

                        }//Event handling done

       print_function(window,start_print);
       start_print=0;//Printa bara br�det n�r det beh�vs


    }

    return 0;
}
