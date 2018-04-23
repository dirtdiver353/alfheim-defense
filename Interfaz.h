/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interfaz.h
 * Author: vik
 *
 * Created on 10 de abril de 2018, 9:28
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "Personaje.h"


namespace Alfheim
{

class Interfaz {
public:
    Interfaz(DatosJuegoRef datos);
    void Pintar();
    void Update();
private:
    DatosJuegoRef _datos;
    
    sf::Font txtFont;
    sf::Text txtVida;
    sf::Text txtMana;
    sf::Text txtPuntos;
    Personaje *personaje;

};

}

