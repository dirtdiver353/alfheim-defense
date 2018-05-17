/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"
#include "Personaje.h"

//#include "Interfaz.h"

namespace Alfheim
{

class Pocion {
public:
    Pocion();
   // Pocion(DatosJuegoRef datos, int t);
    Pocion(DatosJuegoRef datos, int tipo, sf::Vector2f pos);
    void setPocion(sf::Vector2f pos, int t);
    void Pintar();
    void Update(float dt);
    void Eliminar();
    void elimina();
    int getCantidad();
    int getTipo();
    
    void setTexture(sf::Texture tx);
    //sf::Texture getTexture();
    void setSprite(sf::Sprite sp);
    sf::Sprite getSprite();
    
private:
    DatosJuegoRef _datos;
    
    int tipo;
    int cantidad;
    int xCoord, yCoord;
    sf::Texture pocionTexture;
    sf::Sprite pocionSprite;
    

};

}

