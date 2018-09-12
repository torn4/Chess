#include "bishop_rule.h"
#include <iostream>
#include <cmath>

bool bishop_rule::bishoprule(std::string piece_name, std::map < std::string, int > memory_map, int move) {
    bool move_allowedb;

    if (piece_name.length() > 0) {
      if (((memory_map[piece_name] - move) % 9) == 0 || ((memory_map[piece_name] - move) % 7) == 0)
        move_allowedb = true;
      if (piece_name.length() > 0) {}
    } else {
      move_allowedb = false;

    }

    return move_allowedb;
}
