#include "King_rule.h"
#include <iostream>
#include "Rule_piece_collision.h"
#include <vector>
  bool king_rule::kingrule(std::string piece_name, std::map < std::string, int > memory_map, int move, std::vector<std::string> id_memory) {
    bool move_allowedr;
    bool move_allowedf;
    bool move_alloweds;
    bool clean;

    if ((memory_map[piece_name] - move + 8 == 0) || (memory_map[piece_name] - move - 8 == 0)) {
      move_allowedr = 1;
    } else {
      move_allowedr = 0;
    }

    if ((memory_map[piece_name] - move - 1 == 0) || (memory_map[piece_name] - move + 1 == 0)) {
      move_alloweds = true;
    } else {
      move_alloweds = false;
    }

    if ((memory_map[piece_name] - move - 9 == 0) || (memory_map[piece_name] - move + 9 == 0) || (memory_map[piece_name] - move + 7 == 0) || (memory_map[piece_name] - move + 7 == 0)) {
      move_allowedf = true;
    } else {
      move_allowedf = false;
    }

       collision crash;
  if (move_allowedr || move_allowedf || move_alloweds) {//Kollar om en pjäs står där redan
    clean = crash.piece_colission(memory_map, move, id_memory);
  }


    return (move_allowedr || move_allowedf || move_alloweds)&&clean;
  }
