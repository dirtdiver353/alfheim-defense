#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "JuegoState.h"


namespace Alfheim
{
    struct DatosJuego
    {
        JuegoState state;
        sf::RenderWindow ventana;
    };   
    typedef std::shared_ptr<DatosJuego> DatosJuegoRef;
    
    class Juego
    {
    public:
        Juego(int ancho, int alto, std::string titulo);
    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;        
        sf::Clock _updateClock;
        DatosJuegoRef _datos = std::make_shared<DatosJuego>();
        void Iniciar();
    };
}