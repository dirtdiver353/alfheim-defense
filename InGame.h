#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"
#include "Personaje.h"
#include "Hud.h"
#include "Pocion.h"
#include "Mapa.h"
#include "Enemigo.h"
#include "Nivel1.h"
#include "Arma.h"
#include "Bloque.h"

namespace Alfheim
{
    class InGame : public State
    {
    public:
        InGame(DatosJuegoRef datos);
        
        void Init();
        
        void ManejarEventos();
        void Update(float dt);
        void Render(float dt);
        
    private:
        DatosJuegoRef _datos;
        sf::Clock _clock;
         sf::Clock _updateClock;
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
        Personaje *personaje;
         Bloque *bloque;
        Arma *arma;
        Nivel1 *nivel1;
        int xd = 0, yd = 0, xu = 0, ys = 0;
        int yu = 4, xs = 4;
        char dire;
        sf::Clock pasos;
        bool level1, level2;
        Hud *hud;
        
        
       
        
        
      sf::Vector2f* posPocionesVida;
      int numPocionesVida;
      sf::Vector2f* posPocionesMana;
      int numPocionesMana;
      Pocion *pVida;
      Pocion *pMana;
      
      sf::Vector2f posPJ;
      
      sf::FloatRect recPJ;
      
      Enemigo *enemy;
      
        
        
        
    };
}