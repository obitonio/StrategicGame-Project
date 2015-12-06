#include "Main.h"

#include "Editor.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "AOE Editor");
    Editor editor;

    std::cout << "Maximum texture size: "<<sf::Texture::getMaximumSize() << std::endl;


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            window.clear(sf::Color::White);
            editor.update(window);
            editor.draw(window);
            window.display();
        }
    }

    return 0;
}
