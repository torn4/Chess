#include "chess_ai_main.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "print_sfml.h"
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ai_move::piece_value(int a, int i,std::vector < std::string > id_memory ) //Funktion som kollar vilken pjäs som är mest värd att ta
{
    if(take_true.first.length() > 0 && (movep || take_true.second))
    {
        switch(take_true.first.at(1))
        {
        case 'q' :
            max_point=8;
            break;
        case 'k' :
            max_point=4;
            if(take_true.first.at(2)='k')
            {
                max_point=10;
            }
            break;
        case 'r' :

            max_point=6;
            break;
        case 'b' :

            max_point=5;
            break;
        case 'p' :
            max_point=1;
            break;
        }
        if(max_point_earlier<max_point)
        {
            max_point_earlier=max_point;
            move_pair.second=a;
            move_pair.first=id_memory[i];
            std::cout<<max_point_earlier<<" "<<id_memory[i]<<" take_true.first"<<take_true.first<<std::endl;
        }
    }
}

std::pair < std::string, int > ai_move::Random_move(std::map < std::string, int > memory_map, std::vector < std::string > id_memory) // Funktion som gör ett random drag om inget annat finns
{
    if(move_pair.second==87)
    {
        if(memory_map["bp4"]==12)
        {
            move_pair.first="bp4";
            move_pair.second = 28;
        }
        else
        {
            random_numb = rand() % 16 + 1;
            move_pair.first = id_memory[random_numb];
            random_numb = rand() % 64 + 1;
            move_pair.second = random_numb;
        }
    }
}

std::pair <std::string,int > ai_move::min_max(std::map < std::string, int > memory_map, std::vector < std::string > id_memory) // Loppar över alla möjliga drag som finns.
{
    max_point=0;
    max_point_earlier=0;
    take_true.first = "nomove";
    take_true.second = false;
    piece_name="pppp";
    movep = false;
    move_pair.second=87;
    random_numb = rand() % 16 + 1;
    for(int i =1; i <18; i++)
    {
        //   std::cout<<i<<std::endl;
        piece_name = id_memory[i];
        if(memory_map[id_memory[i]]!=83)
        {
            for(int a=0; a<65; a++)
            {
                max_point=0;
                take_true.first="";
                take_true.second=false;
                if (piece_name.at(1) == 'p')   //Kollar regler för varje pjäs
                {
                    movep = pr.pawnRule(piece_name, memory_map, a,id_memory);
                    take_true = pr.takePawn(memory_map, id_memory, piece_name, a);
                }
                else if (piece_name.at(1) == 'r')
                {
                    movep = rr.rookrule(piece_name, memory_map, a, id_memory);

                }
                else if (piece_name.at(1) == 'b')
                {
                    movep = br.bishoprule(piece_name, memory_map, a, id_memory);

                }
                else if (piece_name.at(1) == 'q')
                {
                    movep = br.bishoprule(piece_name, memory_map, a, id_memory) || rr.rookrule(piece_name, memory_map, a, id_memory);

                }
                else if (piece_name.at(1) == 'k' && piece_name.at(2) == 'k')
                {
                    movep = kr.kingrule(piece_name, memory_map, a);

                }
                else if (piece_name.at(1) == 'k')
                {
                    movep = kn.knightrule(piece_name, memory_map, a);
                }

                if (movep && piece_name.at(1) != 'p' || take_true.second)
                {
                    take_true = tk.takepiece(memory_map, id_memory, piece_name, a);
                    movep = crash.piece_colission(memory_map, a, id_memory, piece_name);
                }
                piece_value( a,  i, id_memory);
            }
        }
    }
}


std::pair < std::string, int > ai_move::aimove(std::map < std::string, int > memory_map, std::vector < std::string > id_memory) // Skickar vilket drag som ska göras.
{
    min_max(memory_map,id_memory);
    Random_move(memory_map,id_memory);
    return move_pair;
}
