#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Juego.h"

#define kVel 5
#define UPDATE_TICK_TIME 1000/30

int main()
{
      
    Alfheim::Juego(640, 480, "Alfheim Defense");
    return EXIT_SUCCESS;
}