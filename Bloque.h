#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"

namespace Alfheim
{

    class Bloque
    {
    public:
        Bloque( DatosJuegoRef datos);
        void Pintar();

        void Update(float dt);
        void Girar(int dl);
        
        
        sf::Sprite getBloque();

    private:
        DatosJuegoRef _datos;
        sf::Texture _bloqueTexture;
        sf::Sprite _bloque;
        sf::Clock clock;
        
      
        
    };
}