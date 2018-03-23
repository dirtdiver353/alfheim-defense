#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"

namespace Galaga
{

    class Personaje
    {
    public:
        Personaje( DatosJuegoRef datos);
        void Pintar();
        void Update(float dt);
        void Girar(int dl, int x, int y);
        
    private:
        DatosJuegoRef _datos;
        sf::Texture _personajeTexture;
        sf::Sprite _personaje;
        sf::Clock clock;
    };
}