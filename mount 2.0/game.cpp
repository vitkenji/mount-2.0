#include "game.h"

namespace States
{
	Game::Game() : movingEntitiesList(), staticEntitiesList(), CollisionManager(&movingEntitiesList, &staticEntitiesList)
	{
        pGraphic = Managers::GraphicManager::getInstance();
        pEvent = Managers::EventManager::getInstance();

        background.initialize(BACKGROUND_PATH, Math::CoordinateF(540,360), Math::CoordinateF(WIDTH, HEIGHT));

        player = new Entities::Characters::Player(Math::CoordinateF(400, 620));
        movingEntitiesList.addEntity(player);
        skeleton = new Entities::Characters::Enemies::Skeleton(Math::CoordinateF(600, 630));
        movingEntitiesList.addEntity(skeleton);
        goblin = new Entities::Characters::Enemies::Goblin(Math::CoordinateF(900, 630));
        movingEntitiesList.addEntity(goblin);
        fire = new Entities::Obstacles::Fire(Math::CoordinateF(100, 650));
        staticEntitiesList.addEntity(fire);
        pControl = new Control::PlayerControl(player);

        for (int i = 0; i < 8; i++)
        {
            Entities::Obstacles::Platform* platform = new Entities::Obstacles::Platform(Math::CoordinateF(0 + 192 * i, 700));
            staticEntitiesList.addEntity(platform);

        }

        skeleton->setPlayer(player);

        execute();
	    
    }

    Game::~Game(){}

    void Game::execute()
    {
        while (pGraphic->isWindowOpen())
        {
            pGraphic->clear();
            background.render();
        
           
            for (int i = 0; i < staticEntitiesList.getSize(); i++)
            {
                staticEntitiesList[i]->render();
                staticEntitiesList[i]->update(0.001);

            }
            
            for (int i = 0; i < movingEntitiesList.getSize(); i++)
            {
                movingEntitiesList[i]->render();
                movingEntitiesList[i]->update(0.001);

            }

            CollisionManager.collide();
            pEvent->pollEvents();
            pGraphic->display();

        }
    }
}