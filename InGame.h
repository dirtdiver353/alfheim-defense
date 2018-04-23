#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"
#include "Personaje.h"
#include "Interfaz.h"
#include "Pocion.h"
#include "Mapa.h"

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
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
        Personaje *personaje;
        Mapa *mapa; 
        int xd = 0, yd = 0, xu = 0, ys = 0;
        int yu = 4, xs = 4;
        sf::Clock pasos;
      
        
        
        sf::Font txtFont;
        sf::Text _txtVida;
        sf::Text _txtMana;
        sf::Text _txtPuntos;
        
        
       Pocion *pocPrueba;
        
        
        
    };
}