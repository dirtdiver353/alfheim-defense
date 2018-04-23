/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interfaz.cpp
 * Author: vik
 * 
 * Created on 10 de abril de 2018, 9:28
 */

#include "Interfaz.h"
namespace Alfheim{

Interfaz::Interfaz(DatosJuegoRef datos): _datos(datos) {
    
    if(!txtFont.loadFromFile("resources/fonts/clacon.ttf")){
            // Error en carga de fuente de texto
            exit(0);
        
            }
    
    txtVida.setFont(txtFont);
    txtVida.setColor(sf::Color::White);
    txtVida.setString(personaje->getVida());
    // title.setScale(1.1, 1.1);
    txtVida.setPosition(sf::Vector2f(640/2-170, 80));
    
}

void Interfaz::Pintar(){
_datos->ventana.draw(txtVida);
}

void Interfaz::Update(){}


}
