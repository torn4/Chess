#include "chess_ai_main.h"
#include <stdlib.h >
#include <time.h>
#include <iostream>
#include <string>
  //När funktionen kallas vet man redan att det är AI's tur, man måste då kolla vilka drag som är möjliga och hur man får så mycet poäng som möjligt.
  //I första draften flyttar man en pjäs på random

  std::pair < std::string, int > ai_move::aimove(std::map < std::string, int > memory_map, std::vector < std::string > id_memory) {

    random_numb = rand() % 16 + 1;

    move_pair.first = id_memory[random_numb];
    if(memory_map[move_pair.first]==79){ //Kollar om pjäsen är tagen
            std::cout<<"Rekurisiv"<<std::endl;
        return aimove(memory_map,id_memory);
    }


    random_numb = rand() % 64 + 1;
    move_pair.second = random_numb;
    std::cout<<move_pair.first<<" "<<move_pair.second<<std::endl;
    return move_pair;

  }
