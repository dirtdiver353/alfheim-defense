#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include <vector>
#include <stdlib.h>

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
        float GetRandom() const;
        void SetRandom(float random);

        bool IsFiring() const;

        bool IsFirstime(int i) const ;

        void SetFirstime(int i, bool firstime);

        
    private:
        DatosJuegoRef _datos;        
        std::vector<sf::Sprite> proyectilSprites;
                std::vector<bool> firstime;   
        std::vector<float> speedFire1;
        std::vector<float> speedFire2;
        sf::Texture proyectilTexture;
        sf::Clock fuego;
        sf::Clock clock;
        sf::Clock _updateClock;
        bool firing;
        int animate;
        char dire;
        float random=((float)(rand()%600+101))/100;
                    

    };
}