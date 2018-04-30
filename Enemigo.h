#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"

namespace Alfheim
{
class Enemigo {
public:
    Enemigo(DatosJuegoRef datos,int tipo, sf::Vector2f pos);
    
    
    void setEnemigo(int tipo, sf::Vector2f pos);
    void Pintar();
    void Update(float dt);
    
    int getVida();
    void recibeDanyo(int cant);
    
    
    
private:
    DatosJuegoRef _datos;
    sf::Texture _enemigoTexture;
    sf::Sprite _enemigo;
    sf::Clock clock;
    
    int vida;
    int danyo;
    bool muerto;

};

}

