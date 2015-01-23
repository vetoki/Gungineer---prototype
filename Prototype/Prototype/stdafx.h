// stdafx.h

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <math.h>

#include <fstream>
#include <sstream>
#include <iostream>

#include <string>
#include <vector>
#include <map>

//Maths
const float PI = 3.141592;

//here be SFML
#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

//Here be SFML Lib
#if !defined(NDEBUG)
#pragma comment(lib, "sfml-main-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#else
#pragma comment(lib, "sfml-main.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-audio.lib")
#endif