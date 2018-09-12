#include <map>
#include <string>
#include <vector>
#include "Rule_piece_collision.h"
class pawn_rule : public collision {
    public:
bool pawnRule(std::string piece_name, std::map<std::string,int> memory_map,int move,std::vector<std::string> id_memory);
};
