
#include "Knight_rule.h"
#include <iostream>
#include "Rule_piece_collision.h"
#include <vector>
  bool knight_rule::knightrule(std::string piece_name, std::map < std::string, int > memory_map, int move) {
    bool move_allowedr;
std::cout<<"knight " <<std::endl;

    if ((memory_map[piece_name] - move - 6 == 0) || (memory_map[piece_name] - move + 6 == 0) || (memory_map[piece_name] - move - 17 == 0) || (memory_map[piece_name] - move + 17 == 0)) {
      move_allowedr = true;
    } else if((memory_map[piece_name] - move - 10 == 0) || (memory_map[piece_name] - move + 10 == 0) || (memory_map[piece_name] - move + 15 == 0) || (memory_map[piece_name] - move - 15 == 0)) {
      move_allowedr = true;
      }else{
        move_allowedr = false;
      }

    return move_allowedr;
  }
