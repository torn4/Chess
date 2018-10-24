#include "Knight_rule.h"
#include <iostream>
#include "Rule_piece_collision.h"
#include <vector>

  bool knight_rule::knightrule(std::string piece_name, std::map < std::string, int > memory_map, int move) {
if(memory_map[piece_name] != 79)
   {


number = memory_map[piece_name];
    if (number % 8 == 0) {
    width = 7;
    height = number / 8 - 1;
  } else { //0 index board
    width = number % 8 - 1;
    height = number / 8;
  }

      if (move % 8 == 0) {
    mwidth = 7;
    mheight = move / 8 - 1;
  } else { //0 index board
    mwidth = move % 8 - 1;
    mheight = move / 8;
  }

    if (width == mwidth+2 && (height == mheight+1 || height == mheight -1)) {
      return true;
    } else if (width == mwidth-2 && (height == mheight+1 || height == mheight -1)){
    return true;
    } else if (height == mheight+2 && (width == mwidth+1 || width == mwidth -1)){
    return true;
    }else if (height == mheight-2 && (width == mwidth+1 || width == mwidth -1)){
    return true;
    }
   }
    return false;
  }
