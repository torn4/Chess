#include <map>

class chessPieces{
    public:
std::map<std::string,int> piece_pos(std::string piece_name, int move, int init);

std::map<std::string,int> memory_map;
bool movep;
bool white;
bool legal_move;
};
