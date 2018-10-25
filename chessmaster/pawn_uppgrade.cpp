#include "pawn_uppgrade.h"
#include <iostream>
#include <string>

//Tar in mappen, om en bonde har flyttats s� kollar vi om man kan uppgradera den till en annan pj�s, h�st eller drottning
// Vi ska returna mappen, ta in mappen och draget, samt pj�sen.

  //N�r funktionen kallas vet man redan att det �r AI's tur, man m�ste d� kolla vilka drag som �r m�jliga och hur man f�r s� mycet po�ng som m�jligt.
  //I f�rsta draften flyttar man en pj�s p� random

  std::map <std::string,int> pawn_uppgrade::pawnupp(std::map < std::string, int > memory_map, std::vector < std::string > id_memory, std::string piece_name, int move) {
if(piece_name.at(1) == 'p' &&(move>0 && move <9)  ){

memory_map[piece_name] = 97;
memory_map["wq1"] =move;
} else if (piece_name.at(1)=='p' && (move >55 && move <65))
{
memory_map[piece_name] = 97;
memory_map["bq1"] =move;
}
    return memory_map;

  }
