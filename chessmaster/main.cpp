#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(675, 675), "Playing board");// Rutan som brädet ska ligga i

          sf::Image image;
        if (!(image.loadFromFile("../Figures/schack.png")))
                std::cout << "Cannot load image";   //Load Image

        sf::Texture texture;
        texture.loadFromImage(image);  //Load Texture from image

        sf::Sprite sprite;
        sprite.setTexture(texture);

    while (window.isOpen())
    {
     sf::Event event;



                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();

                        }//Event handling done


        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
