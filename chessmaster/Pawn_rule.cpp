#include "Pawn_rule.h"
#include <iostream>


bool pawn_rule::pawnRule(std::string piece_name, std::map < std::string, int > memory_map, int move, std::vector < std::string > id_memory) {
  bool move_allowedp;
  collision crash;
  int place = 0;
  if (piece_name.length() > 0) { //Kollar om bonden kan r�ra sig dit
    if (piece_name.at(0) == 'w' && memory_map[piece_name] == move + 8) {
      move_allowedp = true;
    } else if (piece_name.at(0) == 'w' && memory_map[piece_name] == move + 16 && memory_map[piece_name] <= 56 && 49 <= memory_map[piece_name]) {
      move_allowedp = true;
    } else if (piece_name.at(0) == 'b' && memory_map[piece_name] == move - 8) {
      move_allowedp = true;
    } else if (piece_name.at(0) == 'b' && memory_map[piece_name] == move - 16 && 9 <= memory_map[piece_name] && memory_map[piece_name] <= 16) {
      move_allowedp = true;
    } else {
      move_allowedp = false;
      std::cout << "A Pawn cannot move this way" << std::endl;
    }
  }

  if (move_allowedp) {//Kollar om en pj�s st�r d�r redan
    move_allowedp = crash.piece_colission(memory_map, move, id_memory);
  }

  return move_allowedp;
}
