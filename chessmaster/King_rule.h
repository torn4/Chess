#include <map>
#include <string>
#include <vector>
#include <utility>

class king_rule{
    public:
bool kingrule(std::string piece_name, std::map<std::string,int> memory_map,int move);
std::pair<bool,int> castle(std::string piece_name, std::map<std::string, int> memory_map, int move,std::vector < std::string > id_memory);
};
