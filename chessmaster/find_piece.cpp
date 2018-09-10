#include <SFML/Graphics.hpp>
#include <iostream>
#include "find_piece.h"
#include <vector>
#include <map>
#include <string>
#include "print_sfml.h"

std::map<std::string,int> chessPieces::piece_pos(std::string piece_name, int move, int init) //Here we save the posistion of all the values
{

//högst upp till vänster är 1, längst ned till höger är 64

   if(init==1 ){
  memory_map["bp1"]=9 ;
  memory_map["bp2"]=10;
  memory_map["bp3"]=11;
  memory_map["bp4"]=12;
  memory_map["bp5"]=13;
  memory_map["bp6"]=14;
  memory_map["bp7"]=15;
  memory_map["bp8"]=16;

  memory_map["bb1"]=6;
  memory_map["bb2"]=3;
  memory_map["bkk"]=5;
  memory_map["bq"]=4;
  memory_map["bk1"]=2;
  memory_map["bk2"]=7;
  memory_map["br1"]=1;
  memory_map["br2"]=8;

//Svarta över ^, vita V

  memory_map["wp1"]=49;//49
  memory_map["wp2"]=50;
  memory_map["wp3"]=51;
  memory_map["wp4"]=52;
  memory_map["wp5"]=53;
  memory_map["wp6"]=54;
  memory_map["wp7"]=55;
  memory_map["wp8"]=56;

  memory_map["wb1"]=59;
  memory_map["wb2"]=62;
  memory_map["wkk"]=61;
  memory_map["wq"]=60;
  memory_map["wk1"]=63;
  memory_map["wk2"]=58;
  memory_map["wr1"]=57;
  memory_map["wr2"]=64;
   }
   else {
   memory_map[piece_name]= memory_map[piece_name] + move;
   //std::cout<<memory_map[piece_name]<<std::endl;
   }


return memory_map;
}
