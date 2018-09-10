#include <utility>
class button_pess{
    public:
std::pair<std::string,int> find_button_pos(sf::RenderWindow &window,const sf::Event &event,std::map<std::string,int> memory_map);

bool found_button;
 std::string piece_name;

};
