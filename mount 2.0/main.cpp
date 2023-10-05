#include "graphicmanager.h"
#include "std.h"
#include "player.h"
#include "control.h"
#include "eventmanager.h"
#include "platform.h"
#include "skeleton.h"
#include "goblin.h"
#include "fire.h"

int main()
{
    Managers::GraphicManager* pGraphic = Managers::GraphicManager::getInstance();
    Managers::EventManager* pEvent = Managers::EventManager::getInstance();

    Entities::Characters::Player* player = new Entities::Characters::Player(Math::CoordinateF(400,630));
    Entities::Characters::Enemies::Skeleton* skeleton = new Entities::Characters::Enemies::Skeleton(Math::CoordinateF(600,630));
    Entities::Characters::Enemies::Goblin* goblin = new Entities::Characters::Enemies::Goblin(Math::CoordinateF(900, 630));
    Entities::Obstacles::Fire* fire = new Entities::Obstacles::Fire(Math::CoordinateF(100, 660));

    Control::PlayerControl* pControl = new Control::PlayerControl(player);

    while (pGraphic->isWindowOpen())
    {
        pGraphic->clear();
        for (int i = 0; i < 8; i++)
        {
            Entities::Obstacles::Platform* platform = new Entities::Obstacles::Platform(Math::CoordinateF(0 + 192 * i, 700));
            platform->render();

        }
        fire->render();
        goblin->render();
        skeleton->render();
        player->render();
        pEvent->pollEvents();
        player->update(0.001);
        goblin->update(0.001);
        skeleton->update(0.001);
        fire->update(0.001);
        pGraphic->display();

    }
	return 0;
}