#include "bishop_rule.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
bool bishop_rule::bishoprule(std::string piece_name, std::map < std::string, int > memory_map, int move, std::vector < std::string > id_memory) {
   int piece_in_the_way = 71;

   number = memory_map[piece_name];
   if (number % 8 == 0) {
      width = 7;
      height = number / 8 - 1;
   } else { //0 index board
      width = number % 8 - 1;
      height = number / 8;
   }

   if (move % 8 == 0) {
      mwidth = 7;
      mheight = move / 8 - 1;
   } else { //0 index board
      mwidth = move % 8 - 1;
      mheight = move / 8;
   }

   if ((abs(width - mwidth) == abs(height - mheight)) && (memory_map[piece_name] != 79)) {

      for (int i = 1; i < 49; i++) {
         piece_in_the_way = memory_map[id_memory[i]];
         if (piece_in_the_way % 8 == 0) {
            iwidth = 7;
            iheight = piece_in_the_way / 8 - 1;
         } else { //0 index board
            iwidth = piece_in_the_way % 8 - 1;
            iheight = piece_in_the_way / 8;
         }
if((abs(iwidth - mwidth) == abs(iheight - mheight))){
        if((height>iheight && iheight>mheight && iwidth>width && mwidth>iwidth ) //Höger upp
         ||(height>iheight && iheight>mheight && width>iwidth && iwidth>mwidth) //Höger ned
         ||(height<iheight && iheight<mheight && width<iwidth && iwidth<mwidth)//Vänster ned
         ||(height<iheight && iheight<mheight && width>iwidth && iwidth>mwidth))//Höger ned
          {

            return false;
         }
      }
      }
      return true;
   }


   return false;
}
