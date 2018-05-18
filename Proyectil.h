#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include <vector>

namespace Alfheim
{

    class Proyectil
    {
    public:
        Proyectil( DatosJuegoRef datos);
        void Pintar(float pt);
        void Update(float dt);
        void Spawn(sf::Sprite personaje, float x, float y);
        void Borrar(int x);
        void setFiring(bool estado);
        const std::vector<sf::Sprite> &GetSprites() const;
        sf::Clock GetFuego() const;
        void SetFuego();

        
    private:
        DatosJuegoRef _datos;        
        std::vector<sf::Sprite> proyectilSprites;          
        std::vector<float> speedFire1;
        std::vector<float> speedFire2;
        sf::Texture proyectilTexture;
        sf::Clock fuego;
        sf::Clock clock;
        sf::Clock _updateClock;
        bool firing;
        int animate;
        char dire;
    };
}