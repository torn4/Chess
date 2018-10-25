#include <utility>
#include <string>
#include <vector>

#include <vector>
#include <map>
#include "pawn_rule.h"
#include "Rook_rule.h"
#include "Bishop_rule.h"
#include "King_rule.h"
#include "Knight_rule.h"
#include "Rule_take_piece.h"
#include "pawn_uppgrade.h"


class ai_move{
    public:
void piece_value(int a, int i, std::vector < std::string > id_memory);
std::pair<std::string,int> aimove(std::map<std::string,int> memory_map,std::vector<std::string>id_memory);
std::pair < std::string, int > Random_move(std::map < std::string, int > memory_map, std::vector < std::string > id_memory);
std::pair < std::string, int > min_max(std::map < std::string, int > memory_map, std::vector < std::string > id_memory);
int random_numb;
int max_point;
int max_point_earlier;
bool movep;
std::pair<std::string,int>move_pair;
    std::string piece_name;
    pawn_rule pr; // Bondens regler
    rook_rule rr;
    bishop_rule br;
    king_rule kr;
    knight_rule kn;
    collision crash;
    take_piece tk;
    pawn_uppgrade pu;
    std::pair < std::string, bool > take_true;
    std::pair <bool,int>castling_rule;
};
