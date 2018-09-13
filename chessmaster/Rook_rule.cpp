#include "Rook_rule.h"
#include <iostream>
#include "Rule_piece_collision.h"
#include <cstdlib>
bool rook_rule::rookrule(std::string piece_name, std::map < std::string, int > memory_map, int move, std::vector < std::string > id_memory) {

  int hn;
  int hp;
  int place;
  int piece_in_the_way;

  hn = move / 8; // hittar rätt rad för vart pjäsen ska
  if (move % 8 == 0) {
    hn = move / 8 - 1;
  }
  hp = memory_map[piece_name] / 8;
  place = memory_map[piece_name] / 8;
  if (memory_map[piece_name] % 8 == 0) { //Hi
    hp = memory_map[piece_name] / 8 - 1;
  }

  if ((memory_map[piece_name] - move) % 8 == 0) { //upp o ned

      for (int i = 1; i < 33; i++) { //
        piece_in_the_way = memory_map[id_memory[i]];

        if (((memory_map[piece_name] > piece_in_the_way) && (piece_in_the_way > move) && memory_map[piece_name] != piece_in_the_way) && (piece_in_the_way % 8 == move % 8)) { // Kollar om man kan gå upp&& piece_in_the_way != move
          return false;
          break;
        } else if ((((memory_map[piece_name] < piece_in_the_way)  && (piece_in_the_way < move)) && memory_map[piece_name] != piece_in_the_way) && (piece_in_the_way % 8 == move % 8)) {
          return false;
          break;
        }
      }

    return true;
  } else if (hp == hn) { // sidled

      for (int i = 1; i < 33; i++) { //
        piece_in_the_way = memory_map[id_memory[i]];
        if (((memory_map[piece_name] > piece_in_the_way) && (piece_in_the_way > move)) && (memory_map[piece_name] != piece_in_the_way)  ) { // Kollar om man kan gå åt sidan
          return false;
          break;
        } else if (((memory_map[piece_name] < piece_in_the_way) && (piece_in_the_way < move) ) && (memory_map[piece_name] != piece_in_the_way)  ) {
          return false;
          break;
        }
      }

    return true;
  }
  return false;
}
