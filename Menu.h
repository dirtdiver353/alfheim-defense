#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"
#include "Personaje.h"
#include "Musica.hpp"

#define MAX_NUM_ITEMS_INI 4

namespace Alfheim
{
    class Menu : public State
    {
    public:
        Menu(DatosJuegoRef datos);
        
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
        sf::Text options[MAX_NUM_ITEMS_INI];
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
        sf::Font textFontTitle;
        sf::Text title;
        sf::Text titleShadow;
       
        Musica* musica;
    };
}

