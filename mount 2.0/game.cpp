#include "game.h"

namespace States
{
	Game::Game() : entitiesList()
	{
        pGraphic = Managers::GraphicManager::getInstance();
        pEvent = Managers::EventManager::getInstance();

        player = new Entities::Characters::Player(Math::CoordinateF(400, 630));
        entitiesList.addEntity(player);
        skeleton = new Entities::Characters::Enemies::Skeleton(Math::CoordinateF(600, 630));
        entitiesList.addEntity(skeleton);
        goblin = new Entities::Characters::Enemies::Goblin(Math::CoordinateF(900, 630));
        entitiesList.addEntity(goblin);
        fire = new Entities::Obstacles::Fire(Math::CoordinateF(100, 660));
        entitiesList.addEntity(fire);
        
        pControl = new Control::PlayerControl(player);

        execute();
	}

    Game::~Game(){}

    void Game::execute()
    {
        while (pGraphic->isWindowOpen())
        {
            pGraphic->clear();
            for (int i = 0; i < 8; i++)
            {
                Entities::Obstacles::Platform* platform = new Entities::Obstacles::Platform(Math::CoordinateF(0 + 192 * i, 700));
                platform->render();

            }

            for (int i = 0; i < entitiesList.getSize(); i++)
            {
                entitiesList[i]->render();
                entitiesList[i]->update(0.001);

            }
            pEvent->pollEvents();
            /*
            fire->render();
            goblin->render();
            skeleton->render();
            player->render();
            pEvent->pollEvents();
            player->update(0.001);
            goblin->update(0.001);
            skeleton->update(0.001);
            fire->update(0.001);
            */
            pGraphic->display();

        }
    }
}