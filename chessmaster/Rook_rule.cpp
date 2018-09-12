#include "Rook_rule.h"
#include <iostream>
#include "Rule_piece_collision.h"
bool rook_rule::rookrule(std::string piece_name, std::map < std::string, int > memory_map, int move, std::vector<std::string> id_memory) {
  bool move_allowedr;

  int hn;
  int hp;
  if (move % 8 == 0) {
    hn = move / 8 - 1;
  } else { //0 index board
    hn = move / 8;
  }

  if (memory_map[piece_name] % 8 == 0) {
    hp = memory_map[piece_name] / 8 - 1;
  } else { //0 index board
    hp = memory_map[piece_name] / 8;
  }

  if (piece_name.length() > 0) {
    if ((memory_map[piece_name] - move) % 8 == 0) {
      move_allowedr = 1;
    } else if (hp == hn) {
      move_allowedr = 1;
    } else {
      move_allowedr = 0;
    }

  }

   collision crash;
  if (move_allowedr) {//Kollar om en pjäs står där redan
    move_allowedr = crash.piece_colission(memory_map, move, id_memory);
  }

  return move_allowedr;
}
