#include "chess_ai_main.h"
#include <stdlib.h >
#include <time.h>
#include <iostream>
  //N�r funktionen kallas vet man redan att det �r AI's tur, man m�ste d� kolla vilka drag som �r m�jliga och hur man f�r s� mycet po�ng som m�jligt.
  //I f�rsta draften flyttar man en pj�s p� random

  std::pair < std::string, int > ai_move::aimove(std::map < std::string, int > memory_map, std::vector < std::string > id_memory) {

    random_numb = rand() % 16 + 1;

    move_pair.first = id_memory[random_numb];
    random_numb = rand() % 64 + 1;
    move_pair.second = random_numb;
    std::cout<<move_pair.first<<" "<<move_pair.second<<std::endl;
    return move_pair;

  }
