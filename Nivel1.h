#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include <vector>
#include "Mapa.h"
#include "Bloque.h"

namespace Alfheim
{

    class Nivel1
    {
    public:
        Nivel1( DatosJuegoRef datos);
        void setMapa(const char * nombre);
        Mapa *getMapa();
        void setBloque(int i, int x, int y);
        void setBloques();
        Bloque *getBloque(int i);
        void PintarBloques(sf::RenderWindow& window, float pt);
        void MoverBloques(int x, int i, sf::Sprite personaje);
        int ColisionBloque(int dire);
        
    private:
        DatosJuegoRef _datos;        
        Mapa *mapa; 
        Bloque *bloques[6];  
    };
}