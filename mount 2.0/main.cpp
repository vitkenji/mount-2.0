#include "graphicmanager.h"
#include "std.h"

int main()
{
    Managers::GraphicManager* pGraphic = pGraphic->getInstance();;

    while (pGraphic->isWindowOpen())
    {

        pGraphic->clear();
        sf::RectangleShape* rectangle = new sf::RectangleShape();
        rectangle->setSize(sf::Vector2f(100.f, 100.f));
        rectangle->setFillColor(sf::Color(12,120,12));
        pGraphic->render(rectangle);
        pGraphic->display();

       
    }
	return 0;
}