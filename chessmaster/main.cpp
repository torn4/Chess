#include <SFML/Graphics.hpp>
#include <iostream>
#include "chessboard.h"
#include "whiteRook.h"
#include "print_sfml.h"
#include "find_piece.h"
#include <string>


int main()
{

sf::RenderWindow window(sf::VideoMode(675, 675), "Playing board");// Rutan som br�det ska ligga i

std::string piece_name;
piece_name="bp1";
int start_print;
 start_print =1;
 window.clear();
std::cout<<piece_pos(piece_name,0,1)<<std::endl;
    while (window.isOpen())
    {
     sf::Event event;
std::cout<<piece_pos(piece_name,0,0)<<std::endl;
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
