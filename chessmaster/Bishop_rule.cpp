#include "bishop_rule.h"
#include <iostream>
#include <cmath>
#include "Rule_piece_collision.h"
#include <vector>
bool bishop_rule::bishoprule(std::string piece_name, std::map < std::string, int > memory_map, int move, std::vector<std::string> id_memory) {
    bool move_allowedb;

    if (piece_name.length() > 0) {
      if (((memory_map[piece_name] - move) % 9) == 0 || ((memory_map[piece_name] - move) % 7) == 0)
        move_allowedb = true;
      if (piece_name.length() > 0) {}
    } else {
      move_allowedb = false;

    }
   collision crash;
  if (move_allowedb) {//Kollar om en pjäs står där redan
    move_allowedb = crash.piece_colission(memory_map, move, id_memory);
  }
    return move_allowedb;
}
