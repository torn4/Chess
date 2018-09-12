#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "button_press.h"
#include <cmath>
#include <map>
#include <utility>

std::pair < std::string, int > button_pess::find_button_pos(sf::RenderWindow & window,
  const sf::Event & event, std::map < std::string, int > memory_map) {
  std::vector < std::string > id_memory(42);
  std::pair < std::string, int > piecepos;
  id_memory[1] = "bp1";
  id_memory[2] = "bp2";
  id_memory[3] = "bp3";
  id_memory[4] = "bp4";
  id_memory[5] = "bp5";
  id_memory[6] = "bp6";
  id_memory[7] = "bp7";
  id_memory[8] = "bp8";
  id_memory[9] = "bb1";
  id_memory[10] = "bb2";
  id_memory[11] = "bkk";
  id_memory[12] = "bq";
  id_memory[13] = "bk1";
  id_memory[14] = "bk2";
  id_memory[15] = "br1";
  id_memory[16] = "br2";
  id_memory[17] = "wp1";
  id_memory[18] = "wp2";
  id_memory[19] = "wp3";
  id_memory[20] = "wp4";
  id_memory[21] = "wp5";
  id_memory[22] = "wp6";
  id_memory[23] = "wp7";
  id_memory[24] = "wp8";
  id_memory[25] = "wb1";
  id_memory[26] = "wb2";
  id_memory[27] = "wkk";
  id_memory[28] = "wq";
  id_memory[29] = "wk1";
  id_memory[30] = "wk2";
  id_memory[31] = "wr1";
  id_memory[32] = "wr2";

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
        //    std::cout<<"found piece : "<<id_memory[i]<<" at: "<<  chess_place <<std::endl;
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
    //  std::cout<<"Droping piece: "<<piece_name <<" at: "<<  chess_place <<std::endl;
    found_button = 1;
    piecepos.first = piece_name;
    piecepos.second = chess_place;

  }
  return piecepos;
}
