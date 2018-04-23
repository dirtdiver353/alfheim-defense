/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.h
 * Author: vik
 *
 * Created on 27 de marzo de 2018, 10:08
 */

#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <SFML/Graphics.hpp>
#include "Juego.h"

namespace Alfheim
{
    class Enemigo {
    public:
        Enemigo(DatosJuegoRef datos);
        void Pintar();
        void Update( float dt);
        int GetVida();
        void RestaVida();
        void Atacar();
        bool DetectaPersonaje(DatosJuegoRef datos);
       // Enemigo(const Enemigo& orig);
        virtual ~Enemigo();
    private:
        
        DatosJuegoRef _datos;
        
        sf::Texture _enemigoTexture;
        sf::Sprite _enemigo;
        sf::Clock clock;
        
        int vida;
        int ptsAtaque;
        

    };
}

#endif /* ENEMIGO_H */

