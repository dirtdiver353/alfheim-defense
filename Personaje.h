#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"

namespace Alfheim
{

    class Personaje
    {
    public:
        Personaje( DatosJuegoRef datos);
        void Pintar();
        void Update(float dt);
        void Girar(int dl, int x, int y);
        
        void setVida(int i);
        void setMana(int i);
        void setPuntos(int i);
        
        int getVida();
        int getMana();
        int getPuntos();
        
        bool recibeDanyo(int cant);
        
        bool trucoInvencible(bool i);
        
        bool compruebaMuerte();
        
        void cogePocion(int tipo, int cant);
        
    private:
        DatosJuegoRef _datos;
        sf::Texture _personajeTexture;
        sf::Sprite _personaje;
        sf::Clock clock;
        
        int puntos;
        int mana;
        int vida;
        bool muerto = false;
        
        // truco
        bool invencible = false;
        
    };
}