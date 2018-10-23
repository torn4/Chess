#include <utility>
#include <vector>
#include <map>
class button_pess{
    public:
std::pair<std::string,int> find_button_pos(sf::RenderWindow &window,const sf::Event &event,std::map<std::string,int> memory_map,std::vector<std::string>id_memory);

bool found_button = true;
 std::string piece_name;

};
