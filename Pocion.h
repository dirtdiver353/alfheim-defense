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
#include "Interfaz.h"

namespace Alfheim
{

class Pocion {
public:
    Pocion(DatosJuegoRef datos, int x, int y, int t);
    void Pintar();
    void Update(float dt);
    void Eliminar();
    
    int getCantidad();
    int getTipo();
    
private:
    DatosJuegoRef _datos;
    
    int tipo;
    int cantidad;
    int xCoord, yCoord;
    sf::Texture pocionTexture;
    sf::Sprite pocionSprite;
    

};

}

