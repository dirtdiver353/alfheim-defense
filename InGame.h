#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"
#include "Personaje.h"
#include "Mapa.h"

namespace Alfheim
{
    class InGame : public State
    {
    public:
        InGame(DatosJuegoRef datos);
        
        void Init();
        
        void ManejarEventos();
        void Update(float dt);
        void Render(float dt);
        
    private:
        DatosJuegoRef _datos;
        sf::Clock _clock;
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
        Mapa *mapa; 
        Personaje *personaje;
        int xd = 0, yd = 0, xu = 0, ys = 0;
        int yu = 4, xs = 4;
        sf::Clock pasos;
        
    };
}