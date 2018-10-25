#include "pawn_uppgrade.h"
#include <iostream>
#include <string>

//Tar in mappen, om en bonde har flyttats så kollar vi om man kan uppgradera den till en annan pjäs, häst eller drottning
// Vi ska returna mappen, ta in mappen och draget, samt pjäsen.

  //När funktionen kallas vet man redan att det är AI's tur, man måste då kolla vilka drag som är möjliga och hur man får så mycet poäng som möjligt.
  //I första draften flyttar man en pjäs på random

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
