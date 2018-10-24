#include "chess_ai_main.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "find_piece.h"
#include <vector>
#include <map>
#include <string>
#include "print_sfml.h"
#include "pawn_rule.h"
#include "Rook_rule.h"
#include "Bishop_rule.h"
#include "King_rule.h"
#include "Knight_rule.h"
#include "Rule_take_piece.h"
#include <utility>
#include "pawn_uppgrade.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//När funktionen kallas vet man redan att det är AI's tur, man måste då kolla vilka drag som är möjliga och hur man får så mycet poäng som möjligt.
//I första draften flyttar man en pjäs på random



std::pair < std::string, int > ai_move::aimove(std::map < std::string, int > memory_map, std::vector < std::string > id_memory)
{
    int max_point=0;
    int max_point_earlier=0;
    int move=0;
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

    take_true.first = "nomove";
    take_true.second = false;
    piece_name="pppp";
    movep = false;
    move_pair.second=87;
    random_numb = rand() % 16 + 1;
    for(int i =1; i <17; i++)
    {
        //   std::cout<<i<<std::endl;
        piece_name = id_memory[i];

        for(int a=0; a<64; a++)
        {
            move=a;
            if (piece_name.at(1) == 'p')   //Kollar regler för varje pjäs
            {
                movep = pr.pawnRule(piece_name, memory_map, move,id_memory);
                take_true = pr.takePawn(memory_map, id_memory, piece_name, move);
            }
            else if (piece_name.at(1) == 'r')
            {
                movep = rr.rookrule(piece_name, memory_map, move, id_memory);

            }
            else if (piece_name.at(1) == 'b')
            {
                movep = br.bishoprule(piece_name, memory_map, move, id_memory);

            }
            else if (piece_name.at(1) == 'q')
            {
                movep = br.bishoprule(piece_name, memory_map, move, id_memory) || rr.rookrule(piece_name, memory_map, move, id_memory);

            }
            else if (piece_name.at(1) == 'k' && piece_name.at(2) == 'k')
            {
                movep = kr.kingrule(piece_name, memory_map, move);

            }
            else if (piece_name.at(1) == 'k')
            {
                movep = kn.knightrule(piece_name, memory_map, move);
            }

            if (movep && piece_name.at(1) != 'p' || take_true.second)
            {

                take_true = tk.takepiece(memory_map, id_memory, piece_name, move);
                movep = crash.piece_colission(memory_map, move, id_memory, piece_name);

            }


            if(take_true.first.length() > 0 && (movep || take_true.second))
            {
                std::cout<<take_true.first<<std::endl;
                std::cout<<a<<" "<<take_true.first<<std::endl;
                switch(take_true.first.at(1))
                {
                case 'k' :
                    max_point=10;
                      std::cout<<a<<"a "<<id_memory[i]<<std::endl;
                case 'q' :
                    max_point=8;
                      std::cout<<a<<" b"<<id_memory[i]<<std::endl;
                case 'r' :
                    max_point=6;
                      std::cout<<a<<"c "<<id_memory[i]<<std::endl;
                case 'p' :
                    max_point=1;
                      std::cout<<a<<"d "<<id_memory[i]<<std::endl;
                case 'b' :
                    max_point=5;
                      std::cout<<a<<"r "<<id_memory[i]<<std::endl;
                }
                if(max_point_earlier<=max_point)
                {
                    max_point_earlier=max_point;
                    move_pair.second=a;
                    move_pair.first=id_memory[i];
                    std::cout<<a<<" "<<id_memory[i]<<std::endl;
                }
            }
        }
    }

if(move_pair.second==87){
        if(memory_map["bp4"]==12)
        {
            move_pair.first="bp4";
            move_pair.second = 28;
        }else{
  random_numb = rand() % 16 + 1;

    move_pair.first = id_memory[random_numb];

    random_numb = rand() % 64 + 1;
    move_pair.second = random_numb;
   // std::cout<<move_pair.first<<" hej "<<move_pair.second<<std::endl;

}
}

   // std::cout<<move_pair.first<<" "<<move_pair.second<<std::endl;
    return move_pair;

}
