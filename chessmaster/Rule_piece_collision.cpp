#include "Rule_piece_collision.h"

bool collision::piece_colission( std::map < std::string, int > memory_map, int move, std::vector < std::string > id_memory, std::string piece_name){
bool move_ok=false;
int place;
    for (int i = 1; i < 33; i++) {
      place = memory_map[id_memory[i]];
      if (place == move) {
        return false;
        break;
      }
    }

return true;
}
