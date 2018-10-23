#include <SFML/Graphics.hpp>
#include <iostream>
#include "chessboard.h"
#include "whiteRook.h"
#include "print_sfml.h"
#include "find_piece.h"
#include <string>
#include <math.h>
#include <time.h>
#include "button_press.h"
#include <utility>
#include <vector>
#include "key_memory.h"
#include "chess_ai_main.h"

int main() {
   std::vector < std::string > id_memory(33);
   std::map < std::string, int > memory_map;
   std::map < std::string, int > memory_map_old;

   sf::RenderWindow window(sf::VideoMode(675, 675), "Playing board"); // Rutan som brädet ska ligga i
       srand ( (unsigned) time(NULL) );
   key_mem mem;
   chessPieces cp;
   button_pess bp;
   ai_move ai;
   std::string piece_name; //
   piece_name = "start";
   window.clear();
   id_memory = mem.keymem();
   std::pair < std::string, int > piecepos;
   int count1 = 0;
   bool white =1;
   memory_map = cp.piece_pos(piece_name, 0, 1, id_memory);
   memory_map_old = memory_map;
   print_function(window, 1, memory_map);
   while (window.isOpen()) {

     sf::Event event;

     while (window.pollEvent(event)) {
       if (event.type == sf::Event::Closed)
         window.close();

     } //Event handling done
if(white==1){

     piecepos = bp.find_button_pos(window, event, memory_map, id_memory);
}else {
   piecepos = ai.aimove(memory_map,id_memory);
}

     if (piecepos.first.length() > 0) { //Printa bara om vi måste
       memory_map = cp.piece_pos(piecepos.first, piecepos.second, 0, id_memory);
       print_function(window, 1, memory_map);
       if(memory_map_old!=memory_map){
       memory_map_old = memory_map;
       white= !white;
       }
     }
     if ((memory_map["wkk"] == 70 || memory_map["bkk"] == 70)) {
       std::cout << "Game over " << std::endl;
       return 0;
     }
   }

  return 0;
}
