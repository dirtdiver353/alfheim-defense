#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "Personaje.h"


namespace Alfheim
{

class Hud {
public:
    Hud(DatosJuegoRef datos);
    Hud(const Hud& orig);
    virtual ~Hud();
    
    void SetPuntos(int p);
    void SetVida(int p);
    void SetMana(int p);
    
    sf::Text GetTxtVida();
    sf::Text GetTxtMana();
    sf::Text GetTxtPuntos();
    
    void Update(int v, int m, int p);
    void Pintar();
    
private:
    
    sf::Text txtVida;
    sf::Text txtMana;
    sf::Text txtPuntos;
    sf::Font txtFont;
    
    Personaje *personaje;
    DatosJuegoRef _datos;

};

}

