#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"
#include "Personaje.h"
#include "Hud.h"
#include "Pocion.h"
#include "Mapa.h"
#include "Enemigo.h"
#include "Nivel2.h"
#include "Arma.h"



namespace Alfheim
{
    class InGame2 : public State
    {
    public:
        InGame2(DatosJuegoRef datos);
        
        void Init();
        
        void ManejarEventos();
        void Update(float dt);
        void Render(float pt);
        
    private:
        DatosJuegoRef _datos;
        sf::Clock _clock;
         sf::Clock _updateClock;
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
        Personaje *personaje;
         
        Arma *arma;
        Nivel2 *nivel2;
        int xd = 0, yd = 0, xu = 0, ys = 0;
        int yu = 4, xs = 4;
        char dire;
        sf::Clock pasos;
        bool level1, level2;
        Hud *hud;
        
        char lastDir;
       
        
        
      
      
      sf::Vector2f posPJ;
      
      sf::FloatRect recPJ;
      
     Enemigo *enemy;
      Pocion *pV1, *pV2;
      Pocion *pM1, *pM2,*pM3;
      
      sf::Vector2f *posPV;
      sf::Vector2f *posPM;
      
        
        
        
    };
}