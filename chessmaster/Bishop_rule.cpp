#include "bishop_rule.h"
#include <iostream>
#include <cmath>
#include "Rule_piece_collision.h"
#include <vector>
bool bishop_rule::bishoprule(std::string piece_name, std::map < std::string, int > memory_map, int move, std::vector < std::string > id_memory) {
  int piece_in_the_way;
  if (((memory_map[piece_name] - move) % 9) == 0 || ((memory_map[piece_name] - move) % 7) == 0) {
    for (int i = 1; i < 33; i++) { //
      piece_in_the_way = memory_map[id_memory[i]]; // H�r kollar vi om det �r n�gon pj�s imellan d�r vi �r och dit vi ska.
      if ((((memory_map[piece_name] < piece_in_the_way) == false && (piece_in_the_way < move) == false) && memory_map[piece_name] != piece_in_the_way) && (piece_in_the_way % 7 == move % 7) && piece_in_the_way != move) {
        return false;
      } else if ((((memory_map[piece_name] > piece_in_the_way) == false && (piece_in_the_way > move) == false) && memory_map[piece_name] != piece_in_the_way) && (piece_in_the_way % 9 == move % 9) && piece_in_the_way != move) {
        return false;
      }
    }
    return true;
  }
  return false;
}
