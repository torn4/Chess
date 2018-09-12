#include "Pawn_rule.h"

bool pawn_rule::pawnRule(std::string piece_name, std::map<std::string,int> memory_map,int move){
bool move_allowedp;

if(piece_name.length()>0 && piece_name.at(1)=='p'){
 if(piece_name.at(0)=='w' && memory_map[piece_name]==move+8)
    {
    move_allowedp=true;
    }else if(piece_name.at(0)=='w' && memory_map[piece_name]==move+16 && memory_map[piece_name]<=56 && 49<=memory_map[piece_name])
    {
       move_allowedp=true;
    }
    else if(piece_name.at(0)=='b' && memory_map[piece_name]==move-8){
    move_allowedp=true;
    }else if(piece_name.at(0)=='b' && memory_map[piece_name]==move-16 && 9<=memory_map[piece_name] && memory_map[piece_name]<=16)
    {
       move_allowedp=true;
    }
    else
    {
    move_allowedp=false;
        std::cout<<"A Pawn cannot move this way"<<std::endl;
    }
 }
return move_allowedp;
}
