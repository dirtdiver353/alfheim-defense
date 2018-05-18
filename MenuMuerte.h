#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"
#include "Personaje.h"
//#include "Musica.hpp"

#define MAX_NUM_ITEMS 2

namespace Alfheim
{
    class MenuMuerte : public State
    {
    public:
        MenuMuerte(DatosJuegoRef datos, int nivel);
        
        void Init();
        
        void ManejarEventos();
        void Update(float dt);
        void Render(float dt);
        
        void MoveUp();
        void MoveDown();
    
        int GetSelectedItem();
    
        
        
    private:
        DatosJuegoRef _datos;
        int selectedItem;
        sf::Font textFont;
        sf::Text options[MAX_NUM_ITEMS];
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
        sf::Font textFontTitle;
        sf::Text title;
        sf::Text titleShadow;
        int nivel;
//        Musica* musica;
    };
}


