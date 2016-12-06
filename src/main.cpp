/*

  description:

  author: Yann Herklotz <ymherklotz@gmail.com>
  date created: DD-MM-YYYY

 */

#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    cout << "executing " << argv[0] << endl;
    cout << "arguments given: " << argc-1 << endl;

    sf::RectangleShape rect(sf::Vector2f(25, 25));
    rect.setFillColor(sf::Color(100, 100, 100));

    sf::RenderWindow window(sf::VideoMode(800, 600), "A* Algorithm");

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && rect.getPosition().x > 0) {
            rect.move(-0.5f, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            rect.move(0.5f, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rect.move(0, -0.5f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rect.move(0, 0.5f);
        }


        window.clear(sf::Color(47, 47, 47));
        window.draw(rect);
        window.display();
    }
    
    return 0;
}
