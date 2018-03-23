#pragma once

#include <SFML/Graphics.hpp>
#include "Estado.h"
#include "Juego.h"
#include "Personaje.h"

namespace Galaga
{
    class EstadoInGame : public Estado
    {
    public:
        EstadoInGame(DatosJuegoRef datos);
        
        void Init();
        
        void ManejarEventos();
        void Update(float dt);
        void Render(float dt);
        
    private:
        DatosJuegoRef _datos;
        sf::Clock _clock;
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
        Personaje *personaje;
        int k, x, y;
        
    };
}