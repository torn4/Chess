#include <map>

class chessPieces{
    public:
std::map<std::string,int> piece_pos(std::string piece_name, int move, int init, std::vector<std::string> id_memory);

std::map<std::string,int> memory_map;


bool move_ok(std::string piece_name, bool &init);
bool moveq;
bool movep;
bool mover;
bool moveb;
bool white;
bool legal_move;


};
