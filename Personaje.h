#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"

namespace Alfheim
{

    class Personaje
    {
    public:
        Personaje( DatosJuegoRef datos);
        void Pintar(float pt);

        void Update(float dt);
        void Girar(int dl, int x, int y);
        
        void setVida(int i);
        void setMana(int i);
        void setPuntos(int i);
        
        int getVida();
        int getMana();
        int getPuntos();
        
        bool recibeDanyo(int cant);
        
        bool getInvencible();
        void setInvencible(bool i);
        
        
        bool compruebaMuerte();
        
        sf::Vector2f getPosicion();
        sf::FloatRect getRect();
        sf::Sprite getPersonaje();
        void cogePocion(int t);
//        void cogePocion(int tipo, int cant, int xpoti, int ypoti);
        
        void lanzaHechizo();
        
    private:
        DatosJuegoRef _datos;
        sf::Texture _personajeTexture;
        sf::Sprite _personaje;
        sf::Clock clock;
        sf::Clock _updateClock;
        
        int puntos;
        int mana;
        int vida;
        bool muerto = false;
        
        // truco
        bool invencible = false;
        
    };
}