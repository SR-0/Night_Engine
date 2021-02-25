#include "Engine.h"

Create	n_Create;
Setup	n_Setup;
Update	n_Update;
Render	n_Render;
Destroy	n_Destroy;

int main()
{
	Engine::CreateCore(n_Create, sf::VideoMode(1280, 720), sf::String("Testing"), false, sf::ContextSettings(0, 0, 0));
	Engine::SetupCore(n_Setup);

	while (Engine::IsRunning())
	{
		Engine::UpdateCore(n_Update);
		Engine::RenderCore(n_Render);
	}

	Engine::DestroyCore(n_Destroy);
}
