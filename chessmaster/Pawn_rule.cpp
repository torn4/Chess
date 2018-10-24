#include "Pawn_rule.h"
#include <iostream>
#include <string>
#include <iostream>
#include "Rule_take_piece.h"



bool pawn_rule::pawnRule(std::string piece_name, std::map < std::string, int > memory_map, int move,std::vector<std::string>id_memory) {
  bool move_allowedp;
bool double_move_8=false;
bool double_move=false;
move_allowedp = false;
  if (piece_name.length() > 0) { //Kollar om bonden kan röra sig dit
    if (piece_name.at(0) == 'w' && memory_map[piece_name] == move + 8) {
      move_allowedp = true;
    } else if (piece_name.at(0) == 'w' && memory_map[piece_name] == move + 16 && memory_map[piece_name] <= 56 && 49 <= memory_map[piece_name]) {
      move_allowedp = true;
    double_move=true;
    } else if (piece_name.at(0) == 'b' && memory_map[piece_name] == move - 8) {
      move_allowedp = true;
    } else if (piece_name.at(0) == 'b' && memory_map[piece_name] == move - 16 && 9 <= memory_map[piece_name] && memory_map[piece_name] <= 16) {
      move_allowedp = true;
      double_move_8=true;
    }
  }
  if(move_allowedp){
    for (int i = 1; i < 49; i++) { //
    piece_in_the_way = memory_map[id_memory[i]];
    if(piece_in_the_way==move){
        return false;
    } else if (double_move &&(piece_in_the_way==move || piece_in_the_way==move+8 )) {
     return false;
    }else if (double_move_8 && (piece_in_the_way==move || piece_in_the_way==move-8)){
     return false;
    }
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


