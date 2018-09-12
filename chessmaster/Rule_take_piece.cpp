#include <utility>
#include "Rule_take_piece.h"
#include <string>
#include <iostream>

 std::pair<std::string,bool> take_piece::takepiece(std::map<std::string,int> memory_map,std::vector<std::string>id_memory,std::string piece_name,int move){
 std::pair<std::string,bool> name_take;
int place=0;

     for (int i = 1; i < 33; i++) {
      place = memory_map[id_memory[i]];

      if (place == move && (piece_name.at(0) != id_memory[i].at(0))) {

        name_take.first = id_memory[i];
        name_take.second = true;
        break;
      }
    }

 return name_take;

 }
