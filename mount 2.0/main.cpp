#include "graphicmanager.h"
#include "std.h"
#include "enemy.h"

int main()
{
    Managers::GraphicManager* pGraphic = pGraphic->getInstance();;
    Enemy enemy;

    while (pGraphic->isWindowOpen())
    {
        pGraphic->clear();
        sf::RectangleShape* rectangle = new sf::RectangleShape();
      
        pGraphic->render(enemy.body);
        pGraphic->display();

       
    }
	return 0;
}