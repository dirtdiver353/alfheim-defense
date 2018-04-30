#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include <vector>

namespace Alfheim
{

    class Arma
    {
    public:
        Arma( DatosJuegoRef datos);
        void Pintar();
        void Update(float dt);
        void Spawn(char dir, float x, float y);
        void Borrar(int x);
        void setFiring(bool estado);
        const std::vector<sf::Sprite> &GetSprites() const;
        
    private:
        DatosJuegoRef _datos;        
        std::vector<sf::Sprite> armaSprites;          
        std::vector<int> speedFire1;
        std::vector<int> speedFire2;
        sf::Texture armaTexture;
        sf::Clock clock;
        bool firing;
        int animate;
        char dire;
    };
}