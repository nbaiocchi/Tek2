/*
** EPITECH PROJECT, 2022
** cpp_test
** File description:
** libSfml
*/

#include "../include/Core.hpp"
#include "../include/libSfml.hpp"

const int WIDTH = 900;
const int HEIGHT = 901;
const int MAX_WIDTH = 1920;
const int MAX_HEIGHT = 1080;
const int X_GAP = 510;
const int Y_GAP = 90;

Arcade::LibSfml::LibSfml()
{
}

Arcade::LibSfml::~LibSfml()
{
}

void Arcade::LibSfml::clear()
{
    this->window->clear();
}

void Arcade::LibSfml::display(std::vector<std::unique_ptr<IComponent>> &components)
{

    for (size_t i = 0; i != components.size(); i += 1) {
        if (components[i]->getType() == Arcade::IComponent::OBJECT && components[i]->getWidth() == 100 && components[i]->getHeight() == 100) {
            std::string pathName = components[i]->getFile() + ".png";
            sf::Texture texture;
            sf::Sprite sprite;
            sf::IntRect rect;
            sf::Vector2f pos;
            texture.loadFromFile(pathName);
            sprite.setTexture(texture);
            pos.x = components[i]->getX() * MAX_WIDTH / 100;
            pos.y = components[i]->getY() * MAX_HEIGHT / 100;
            rect.top = 0;
            rect.left = components[i]->getRect().x;
            //std::cout << "after :  " << rect.left << std::endl;
            rect.width = components[i]->getWidth() * MAX_WIDTH / 100;
            rect.height = components[i]->getHeight() * MAX_HEIGHT / 100;
            sprite.setPosition(pos);
            sprite.setTextureRect(rect);
            window->draw(sprite);
        } else if (components[i]->getType() == Arcade::IComponent::OBJECT) {
            std::string pathName = components[i]->getFile() + ".png";
            sf::Texture texture;
            sf::Sprite sprite;
            sf::IntRect rect;
            sf::Vector2f pos;
            texture.loadFromFile(pathName);
            sprite.setTexture(texture);
            pos.x = components[i]->getX() * WIDTH / 100 + X_GAP;
            pos.y = components[i]->getY() * HEIGHT / 100 + Y_GAP;
            rect.top = 0;
            rect.left = components[i]->getRect().x;
            rect.width = components[i]->getWidth() * WIDTH / 100;
            rect.height = components[i]->getHeight() * HEIGHT / 100;
            sprite.setPosition(pos);
            sprite.setTextureRect(rect);
            window->draw(sprite);
        } else if (components[i]->getType() == Arcade::IComponent::TEXT) {
            text.setPosition(sf::Vector2f{static_cast<float>(components[i]->getX() * WIDTH / 100 + X_GAP),
                                          static_cast<float>(components[i]->getY() * HEIGHT / 100 + Y_GAP)});
            text.setString(components[i]->getText()); 
            window->draw(text);
        } else {
            // sound
        }
    }
    this->window->display();
};

void Arcade::LibSfml::init()
{
    window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Fullscreen);
	window->setActive(false);
	window->clear();
	font.loadFromFile("Font/EquinoxRegular.ttf");
	text.setCharacterSize(20);
	text.setFont(font);

};

void Arcade::LibSfml::stop()
{
    this->window->close();
};

std::string Arcade::LibSfml::getLibName() const
{
    return "arcade_sfml.so";
};

std::vector<std::unique_ptr<Arcade::IEvent>> &Arcade::LibSfml::getEvents()
{
    Arcade::Pos tmp;

    this->events.clear();
    while (this->window->pollEvent(this->event)) {
        sf::Event::EventType ev = event.type;
        if (ev == sf::Event::KeyPressed) {
            if (KEYCODES_TRANSLATION.count(event.key.code)) {
                tmp = {this->event.mouseButton.y, this->event.mouseButton.y};
                this->events.push_back(std::make_unique<Arcade::Event>(KEYCODES_TRANSLATION.find(event.key.code)->second, tmp));
            }
        } else if (ev == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            tmp = {(sf::Mouse::getPosition(*this->window).x - X_GAP)  * 100 / 900, (sf::Mouse::getPosition(*this->window).y - Y_GAP)  * 100 / 901};
            this->events.push_back(std::make_unique<Arcade::Event>(33, tmp)); // force to hardcode because sf::Keyboard::A = sf::Mouse::Left = 0 
        }
        

    }
	return this->events;
};