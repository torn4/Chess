#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(675, 675), "Playing board");// Rutan som brädet ska ligga i

          sf::Image board;
        if (!(board.loadFromFile("../Figures/schack.png")))
                std::cout << "Cannot load board image";   //Load Image

         sf::Image whiteKnight;
        if (!(whiteKnight.loadFromFile("../Figures/whiteKing.png")))
                std::cout << "Cannot load whiteKing image"; //Load Image

        sf::Texture textureBoard;   //Load Texture from image
        sf::Texture textureWhiteKnight;   //Load Texture from image
        textureBoard.loadFromImage(board);
        textureWhiteKnight.loadFromImage(whiteKnight);  //Det är bara den sista bilden som printas, vi vill lägga den sista över den andra


        sf::Sprite spriteBoard;
        sf::Sprite spriteWhiteKnight;
        spriteBoard.setTexture(textureBoard);
        spriteWhiteKnight.setTexture(textureWhiteKnight);

        int i=0;
int a =0;
    while (window.isOpen())
    {
        i=i+1;
        if(i==8){
            i=0;
            a=a+1;
            if(a==8)
                a=0;
    }
     sf::Event event;
     spriteWhiteKnight.setPosition(100*i,100*a);

                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();

                        }//Event handling done

        window.clear();
        window.draw(spriteBoard);
       window.draw(spriteWhiteKnight);
        window.display();
    }

    return 0;
}
