#include "King_rule.h"
#include <iostream>
#include "Rule_piece_collision.h"
#include <vector>
  bool king_rule::kingrule(std::string piece_name, std::map < std::string, int > memory_map, int move) {
    bool move_allowedr=false;


    if ((memory_map[piece_name] - move + 8 == 0) || (memory_map[piece_name] - move - 8 == 0)) {
      move_allowedr = 1;
    } else if ((memory_map[piece_name] - move - 1 == 0) || (memory_map[piece_name] - move + 1 == 0)) {
      move_allowedr = true;
    } else if ((memory_map[piece_name] - move - 9 == 0) || (memory_map[piece_name] - move + 9 == 0) || (memory_map[piece_name] - move + 7 == 0) || (memory_map[piece_name] - move - 7 == 0)) {
      move_allowedr = true;
    }

    return (move_allowedr );
  }
