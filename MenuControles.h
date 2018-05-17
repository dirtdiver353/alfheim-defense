#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"
#include "Personaje.h"


#define MAX_NUM_ITEMS 2

namespace Alfheim
{
    class MenuControles : public State
    {
    public:
        MenuControles(DatosJuegoRef datos);
        
        void Init();
        
        void ManejarEventos();
        void Update(float dt);
        void Render(float pt);
        
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
        sf::Text c1, c2, c3;
       
//        Musica* musica;
    };
}


