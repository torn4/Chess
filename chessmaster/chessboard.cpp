#include <SFML/Graphics.hpp>
#include <iostream>
#include "chessboard.h"



sf::Sprite chessBoard::chessBoardsetvar() //Här måste vi returna sf::sprite
{
  sf::Image board;
  if (!(board.loadFromFile("../Figures/schack.png")))
    std::cout << "Cannot load board image"; //Load Image

  sf::Texture textureBoard; //Load Texture from image
  textureBoard.loadFromImage(board);
  sf::Sprite spriteBoard;
  spriteBoard.setTexture(textureBoard);
  return spriteBoard;
}

void chessBoard::boardDraw(sf::RenderWindow & window,
  const sf::Sprite & spriteChessBoard) { //Här ska inget returnas

  sf::Image chessBoard;
  if (!(chessBoard.loadFromFile("../Figures/schack.png")))
    std::cout << "Cannot load whiteKing image"; //Load Image
  sf::Texture textureBoard; //Load Texture from image
  textureBoard.loadFromImage(chessBoard);

  window.draw(spriteChessBoard);
}
