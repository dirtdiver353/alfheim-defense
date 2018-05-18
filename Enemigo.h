#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "Mapa.h"

namespace Alfheim
{
class Enemigo {
public:
    Enemigo(DatosJuegoRef datos,int tipo, sf::Vector2f pos, Mapa* map, int lvl);
    
    
    void setEnemigo(int tipo, sf::Vector2f pos);
    void Pintar(float pt);
    void Update(float dt);
    
    int getVida();
    void recibeDanyo(std::vector<sf::Sprite> sp, int cant);
    
    bool detectaPersonaje(int xpj, int ypj);
    bool detectaPersonaje2(sf::FloatRect fr);
    
    bool caminar();
    bool compruebaMuerte();
    sf::Sprite getEnemigo() const;
    
    
private:
   DatosJuegoRef _datos;
    sf::Texture _enemigoTexture;
    sf::Sprite _enemigo;
    sf::Clock clock;
    sf::Clock _updateClock;
    int vida;
    int danyo;
    bool muerto;
    bool ataca;
    
    
    int direccion;
    
    Mapa *mapa;
    
    sf::Vector2f posicion;
    
    int nivel;

};

}

