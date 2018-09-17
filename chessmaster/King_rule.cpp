#include "King_rule.h"
#include <iostream>
#include "Rule_piece_collision.h"
#include <vector>
#include <utility>
  bool king_rule::kingrule(std::string piece_name, std::map < std::string, int > memory_map, int move) {
    bool move_allowedr = false;

    switch (memory_map[piece_name] - move) { // Kollar på rutorna runt kungen
    case 1:
    case -1:
    case 7:
    case -7:
    case 8:
    case -8:
    case 9:
    case -9:
      return true;
    }
    return false;
  }

  std::pair < bool, int > king_rule::castle(std::string piece_name, std::map < std::string, int > memory_map, int move, std::vector < std::string > id_memory) { // Kollar på castling reglen
    std::pair < bool, int > return_pair;
    return_pair.first = false;
    return_pair.second = 0;

    if (memory_map["wkk"] == 61 && move == 63 && memory_map["wr2"] == 64) { // Höger sida vit

      for (int i = 1; i < 33; i++) { //
        switch (memory_map[id_memory[i]]) {
        case 62:
        case 63:
        std::cout<<"switch_case1"<<std::endl;

          return return_pair;
          break;
        }
      }
      return_pair.first = true;
      return_pair.second = 63;
      return return_pair;
    } else if (memory_map["wkk"] == 61 && move == 59 && memory_map["wr1"] == 57) { // vänster sida vit
      for (int i = 1; i < 33; i++) { //
        switch (memory_map[id_memory[i]]) {

        case 58:
        case 59:
        case 60:
            std::cout<<"switch_case2"<<std::endl;
          return return_pair;
          break;
        }
      }

      return_pair.first = true;
      return_pair.second = 59;
      return return_pair;
    } else if (memory_map["bkk"] == 5 && move == 3 && memory_map["br1"] == 1) { // vänster sida svart
      for (int i = 1; i < 33; i++) { //
        switch (memory_map[id_memory[i]]) {

        case 2:
        case 3:
        case 4:
            std::cout<<"switch_case3"<<std::endl;
          return return_pair;
          break;
        }
      }

      return_pair.first = true;
      return_pair.second = 3;
      return return_pair;
    }else if (memory_map["bkk"] == 5 && move == 7 && memory_map["br2"] == 8) { // höger sida svart
      for (int i = 1; i < 33; i++) { //
        switch (memory_map[id_memory[i]]) {

        case 6:
        case 7:
            std::cout<<"switch_case4"<<std::endl;
          return return_pair;
          break;
        }
      }

      return_pair.first = true;
      return_pair.second = 7;
      return return_pair;
    }
    return return_pair;
  }
