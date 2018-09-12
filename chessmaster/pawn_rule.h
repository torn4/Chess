#include <map>
#include <string>
#include <vector>
#include "Rule_piece_collision.h"
#include <utility>
class pawn_rule : public collision {
    public:
bool pawnRule(std::string piece_name, std::map<std::string,int> memory_map,int move);
    std::pair<std::string,bool> takePawn(std::map<std::string,int> memory_map,std::vector<std::string>id_memory,std::string piece_name,int move);
};
