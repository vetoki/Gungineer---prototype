// main.cpp

#include "stdafx.h"
#include "Engine.h"

//test2


int main(int argc, char* argv[])
{
	Engine engine;

	if (engine.Initialize())
	{
		engine.Update();
	}
	engine.ShutDown();

	return 0;
}