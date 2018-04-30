/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.cpp
 * Author: vik
 * 
 * Created on 27 de abril de 2018, 0:19
 */

#include "Enemigo.h"
#include <iostream>
#include <sstream>

namespace Alfheim{
    
Enemigo::Enemigo(DatosJuegoRef datos, int tipo, sf::Vector2f pos) : _datos(datos) {
    
    if(tipo == 1){
        if (!_enemigoTexture.loadFromFile("resources/enemy1.png"))
            {
                       exit(0);
            }    
            
            _enemigo.setTexture(_enemigoTexture);
            //_enemigo.setScale(0.5,0.5);
             //Le pongo el centroide donde corresponde
             _enemigo.setOrigin(64/2,64/2);
             //Cojo el sprite que me interesa por defecto del sheet
             _enemigo.setTextureRect(sf::IntRect(0*64, 0*64, 64, 64));
             //_personaje.setScale(0.75,0.75);
             // Lo dispongo en su posicion en la pantalla
             _enemigo.setPosition(pos.x, pos.y);
             
             
             // Inicializo contadores de vida, mana y puntos
             vida = 5;
             danyo = 1;
    
    }else if (tipo == 2){
    
    
    }
             
}

void Enemigo::setEnemigo(int tipo, sf::Vector2f pos){

    

}

void Enemigo::Pintar()
{
    //_personaje.setScale(0.75,0.75);
    _datos->ventana.draw(_enemigo);   
    
}

int Enemigo::getVida(){
    return vida;
}

void Enemigo::recibeDanyo(int cant){
    if(cant <= vida)
        vida -=cant;
    if(vida <= 0)
        muerto = true;
    
    
}





}

