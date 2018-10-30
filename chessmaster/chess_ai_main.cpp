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

void ai_move::piece_value(int a, int i,std::vector < std::string > id_memory, std::string piece_name ) //Funktion som kollar vilken pjäs som är mest värd att ta
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
            if(take_true.first.at(2)=='k')
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
            max_point=2;
            break;

        }
        if(max_point_earlier<=max_point)
        {
            std::cout<<"Nytt max värde : "<<piece_name<<" move_pair.second  "<<move_pair.second<<std::endl;

            max_point_earlier=max_point;
            move_pair.second=a;
            move_pair.first=piece_name;
        }
    }
}

std::map <std::string, int> ai_move::count_score(std::map < std::string, int > memory_map,std::vector < std::string > id_memory, int move)
{
//Här måste vi räkna om vit eller svart har flesta poäng som inte är utanför brädet

    if (movep)   //Gör om brädet
    {
        memory_map[piece_name] = move;

        memory_map=pu.pawnupp(memory_map,id_memory,piece_name,move);

        if (take_true.second)
        {
            memory_map[take_true.first] = 79;
            id_memory[move] = "gone";

        }
    }

    return memory_map;
}

std::pair < std::string, int > ai_move::Random_move(std::map < std::string, int > memory_map, std::vector < std::string > id_memory, std::string piece) // Funktion som gör ett random drag om inget annat finns
{
    if(move_pair.second==87)
    {
        if(memory_map["bp4"]==12)
        {
            move_pair.first="bp4";
            move_pair.second = 28;
        }
        else if (piece!="nothing"){
            random_numb = rand() % 64 + 1;
            move_pair.second = random_numb;
move_pair.first = piece;
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
int ai_move::take_piece_b(std::map < std::string, int > memory_map, std::vector < std::string > id_memory) //Kolla om vit kan ta någon pjäs
{
    for(int i =24; i <42; i++)
    {

        piece_name = id_memory[i];

        if(memory_map[id_memory[i]]!=83) // kollar så att pjäsen inte är tagen
        {

            for(int a=0; a<65; a++)
            {
                {
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
                        movep = kr.kingrule(piece_name, memory_map,a );

                    }
                    else if (piece_name.at(1) == 'k')
                    {
                        movep = kn.knightrule(piece_name, memory_map, a);
                    }

                    if (movep && piece_name.at(1) != 'p' || take_true.second)
                    {
                        take_true = tk.takepiece(memory_map, id_memory, piece_name, a);
                        movep = crash.piece_colission(memory_map, a, id_memory, piece_name);
                        if(take_true.first.length()>0){
                      //  std::cout<<"id : "<<take_true.first<<" move "<<a<<std::endl; // flytta den pjäsen som är här
                        return a;
                        }

                    }

                }
            }
        }
    }
    return 1337;
}


std::pair <std::string,int > ai_move::min_max(std::map < std::string, int > memory_map, std::vector < std::string > id_memory, std::string piece) // Loppar över alla möjliga drag som finns.
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
        if(piece=="nothing"){
           piece_name = id_memory[i];

                    }else {
        piece_name = piece;


        }

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
                piece_value( a,  i, id_memory, piece_name);

            }
        }
        if(piece!="nothing"){
            i=20;
            move_pair.first=piece;
        }
    }
}


std::pair < std::string, int > ai_move::aimove(std::map < std::string, int > memory_map, std::vector < std::string > id_memory) // Skickar vilket drag som ska göras.
{
    std::string threat_piece="nothing";
    int threat_piece_pos=0;
    threat_piece_pos=take_piece_b(memory_map,id_memory);
   // std::cout<<"threat_piece : "<<threat_piece_pos<<std::endl;

    for (int i = 1; i <49 ; i++)
    {
        if(memory_map[id_memory[i]] == threat_piece_pos )
        {
            threat_piece=id_memory[i];
        //   std::cout<<"Här skickar vi break till loppen " <<id_memory[i]<<" :: "<<threat_piece_pos<<std::endl;
            break;
        }
    }

    movep=false;
    min_max(memory_map,id_memory, threat_piece);

    Random_move(memory_map,id_memory,threat_piece);
    return move_pair;
}
