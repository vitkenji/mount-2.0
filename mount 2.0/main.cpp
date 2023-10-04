#include "graphicmanager.h"
#include "std.h"
#include "player.h"
#include "control.h"
#include "eventmanager.h"

int main()
{
    Managers::GraphicManager* pGraphic = Managers::GraphicManager::getInstance();
    Managers::EventManager* pEvent = Managers::EventManager::getInstance();
    Entities::Characters::Player* player = new Entities::Characters::Player(Math::CoordinateF(400,400));
    Control::PlayerControl* pControl = new Control::PlayerControl(player);

    while (pGraphic->isWindowOpen())
    {
        pGraphic->clear();
        player->render();
        pEvent->pollEvents();
        player->update(0.002);
        pGraphic->display();

       
    }
	return 0;
}