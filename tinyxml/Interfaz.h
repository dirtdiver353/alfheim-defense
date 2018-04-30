#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "Personaje.h"

namespace Alfheim
{

class Interfaz {
public:
    Interfaz(DatosJuegoRef datos);
    void Pintar();
    void Update(float dt);
    
private:
    sf::Clock _clock;
    sf::Font txtFont;
    sf::Text _txtVida;
    sf::Text _txtMana;
    sf::Text _txtPuntos;

};

}

