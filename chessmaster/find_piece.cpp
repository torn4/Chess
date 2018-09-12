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


bool chessPieces::move_ok(std::string piece_name, bool & white) { //Kollar svart/vitt
  bool move_allowed;

  if (piece_name.length() > 0) { //Kollar vitt eller svarts drag
    if (piece_name.at(0) == 'w' && white == 1) {
      move_allowed = 1;
      white = 0;
    } else if (piece_name.at(0) == 'b' && white == 0) {
      move_allowed = 1;
      white = 1;
    } else if ((piece_name.at(0) == 'b' && white == 1) || (piece_name.at(0) == 'w' && white == 0)) {
      std::cout << "It is not your turn yet!" << std::endl;
      move_allowed = 0;
    } else {
      move_allowed = 0;
    }
  }

  return move_allowed;
}

std::map < std::string, int > chessPieces::piece_pos(std::string piece_name, int move, int init, std::vector<std::string> id_memory) //Here we save the posistion of all the values
{

  //högst upp till vänster är 1, längst ned till höger är 64

  if (init == 1) {
    memory_map["bp1"] = 9;
    memory_map["bp2"] = 10;
    memory_map["bp3"] = 11;
    memory_map["bp4"] = 12;
    memory_map["bp5"] = 13;
    memory_map["bp6"] = 14;
    memory_map["bp7"] = 15;
    memory_map["bp8"] = 16;

    memory_map["bb1"] = 6;
    memory_map["bb2"] = 3;
    memory_map["bkk"] = 5;
    memory_map["bq"] = 4;
    memory_map["bk1"] = 2;
    memory_map["bk2"] = 7;
    memory_map["br1"] = 1;
    memory_map["br2"] = 8;

    //Svarta över ^, vita V

    memory_map["wp1"] = 49; //49
    memory_map["wp2"] = 50;
    memory_map["wp3"] = 51;
    memory_map["wp4"] = 52;
    memory_map["wp5"] = 53;
    memory_map["wp6"] = 54;
    memory_map["wp7"] = 55;
    memory_map["wp8"] = 56;

    memory_map["wb1"] = 59;
    memory_map["wb2"] = 62;
    memory_map["wkk"] = 61;
    memory_map["wq"] = 60;
    memory_map["wk1"] = 63;
    memory_map["wk2"] = 58;
    memory_map["wr1"] = 57;
    memory_map["wr2"] = 64;
    white = 1;
    movep = 0;
  } else if (piece_name.length() > 0 && memory_map[piece_name] != move) {

    pawn_rule pr; // Bondens regler
    rook_rule rr;
    bishop_rule br;
    king_rule kr;
    knight_rule kn;

    if (piece_name.at(1) == 'p') {
      movep = pr.pawnRule(piece_name, memory_map, move,id_memory);

    } else if (piece_name.at(1) == 'r') {
      movep = rr.rookrule(piece_name, memory_map, move,id_memory);

    } else if (piece_name.at(1) == 'b') {
      movep = br.bishoprule(piece_name, memory_map, move,id_memory);

    } else if (piece_name.at(1) == 'q') {
      movep = br.bishoprule(piece_name, memory_map, move,id_memory) || rr.rookrule(piece_name, memory_map, move,id_memory);

    } else if (piece_name.at(1) == 'k' && piece_name.at(2) == 'k') {
      movep = kr.kingrule(piece_name, memory_map, move,id_memory);
    } else if (piece_name.at(1) == 'k' ) {
        movep = kn.knightrule(piece_name, memory_map, move,id_memory);
    } else {
      movep = false;

    }

    if (movep == true) {
      legal_move = move_ok(piece_name, white);
    } else {
      movep = false;
      legal_move = false;
    }

    if (legal_move) {
      memory_map[piece_name] = move;
    }

  }
  return memory_map;
}
