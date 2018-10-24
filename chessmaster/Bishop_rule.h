#include <map>
#include <string>
#include <vector>

class bishop_rule{
    public:
bool bishoprule(std::string piece_name, std::map<std::string,int> memory_map,int move,std::vector<std::string>id_memory);
int width;
int height;
int mwidth;
int mheight;
int iwidth;
int iheight;
int number;
};
