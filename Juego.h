#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "EstadoJuego.h"


namespace Galaga
{
    struct DatosJuego
    {
        EstadoJuego estado;
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
        DatosJuegoRef _datos = std::make_shared<DatosJuego>();
        void Iniciar();
    };
}