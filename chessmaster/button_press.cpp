#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "button_press.h"
#include <cmath>
#include <map>
#include <utility>
#include "key_memory.h"

   std::pair < std::string, int > button_pess::find_button_pos(sf::RenderWindow & window,
      const sf::Event & event, std::map < std::string, int > memory_map, std::vector < std::string > id_memory) {
      std::pair < std::string, int > piecepos;

      std::map < std::string, int > xy;
      sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
      int chess_place;
      float x = 99999;
      float y = 99999;

      sf::Vector2i pixelPospress;
      sf::Vector2i pixelPosres;

      if (event.type == sf::Event::MouseButtonPressed && pixelPos != pixelPospress && found_button == 1) {

         sf::Vector2i pixelPospress = sf::Mouse::getPosition(window);
         x = pixelPospress.x;
         y = pixelPospress.y;
         chess_place = round((y - 42) / 84.375) * 8 + round((x - 42) / 84.375) + 1;
         for (int i = 0; i < 33; i++) {
            if (memory_map[id_memory[i]] == chess_place) {
               piece_name = id_memory[i];
               found_button = 0;
               //När jag hittat ID kan jag lämna ID till main, sen ge ID + nya posen till print_sfml
               break;
            }
         }

      } else if (event.type == sf::Event::MouseButtonReleased && pixelPos != pixelPosres && found_button == 0) {

         sf::Vector2i pixelPosres = sf::Mouse::getPosition(window);
         x = pixelPosres.x;
         y = pixelPosres.y;
         chess_place = round((y - 42) / 84.375) * 8 + round((x - 42) / 84.375) + 1;
         found_button = 1;
         piecepos.first = piece_name;
         piecepos.second = chess_place;

      }
      return piecepos;
   }
