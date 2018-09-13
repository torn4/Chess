#include "Pawn_rule.h"
#include <iostream>
#include <string>
#include <iostream>
#include "Rule_take_piece.h"
bool pawn_rule::pawnRule(std::string piece_name, std::map < std::string, int > memory_map, int move) {
  bool move_allowedp;

move_allowedp = false;
  if (piece_name.length() > 0) { //Kollar om bonden kan röra sig dit
    if (piece_name.at(0) == 'w' && memory_map[piece_name] == move + 8) {
      move_allowedp = true;
    } else if (piece_name.at(0) == 'w' && memory_map[piece_name] == move + 16 && memory_map[piece_name] <= 56 && 49 <= memory_map[piece_name]) {
      move_allowedp = true;
    } else if (piece_name.at(0) == 'b' && memory_map[piece_name] == move - 8) {
      move_allowedp = true;
    } else if (piece_name.at(0) == 'b' && memory_map[piece_name] == move - 16 && 9 <= memory_map[piece_name] && memory_map[piece_name] <= 16) {
      move_allowedp = true;
    }
  }
   return move_allowedp;
}

 std::pair<std::string,bool> pawn_rule::takePawn(std::map<std::string,int> memory_map,std::vector<std::string>id_memory,std::string piece_name,int move){
    std::pair<std::string,bool> take_true;
   take_piece tp;
   take_true.second = false;
      if (piece_name.length() > 0) { //Kollar om bonden kan röra sig dit
    if (piece_name.at(0) == 'w' && memory_map[piece_name] == move + 9) {
     take_true=tp.takepiece(memory_map,id_memory,piece_name,move);
    } else if (piece_name.at(0) == 'w' && memory_map[piece_name] == move + 7 ) {
     take_true=tp.takepiece(memory_map,id_memory,piece_name,move);
    } else if (piece_name.at(0) == 'b' && memory_map[piece_name] == move - 9) {
     take_true=tp.takepiece(memory_map,id_memory,piece_name,move);
    } else if (piece_name.at(0) == 'b' && memory_map[piece_name] == move - 7 ) {
     take_true=tp.takepiece(memory_map,id_memory,piece_name,move);
    }

  }

  return take_true;
}


