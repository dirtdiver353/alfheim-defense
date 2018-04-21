#pragma once

#include <sstream>
#include "InGame.h"
#include <iostream>

namespace Alfheim
{
   
       InGame::InGame(DatosJuegoRef datos) : _datos(datos)
       {
           mapa = new Mapa(); 
           mapa->leerMapa();  
           
       }
        
        void InGame::Init()
        {
            personaje = new Personaje(_datos);
        }
        
        void InGame::ManejarEventos()
        {
           
                     
            sf::Event event;
            while(_datos->ventana.pollEvent(event))
            {
                
            switch(event.type){
                
                case sf::Event::Closed:
                    _datos->ventana.close();
                break;
                
                case sf::Event::KeyPressed:
                   
                    if(event.key.code == sf::Keyboard::Right){
                            if(pasos.getElapsedTime().asSeconds() > 0.1f){
                                if(xs < 8) xs++;
                                if(xs > 7) xs = 4;
                                if(ys < 4) ys++;                                
                                if(ys > 3) ys = 0;
                                pasos.restart();
                            }
                            personaje->Girar(1,xs,ys);
                    }
                    
                     if(event.key.code == sf::Keyboard::Left){
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xs < 8) xs++;
                                  if(ys < 4) ys++;
                                  if(xs > 7) xs = 4;
                                  if(ys > 3) ys = 0;
                                  pasos.restart();
                            }
                            personaje->Girar(2,xs,ys);
                     }
                        
                     if(event.key.code ==  sf::Keyboard::Up){
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xu < 4) xu++;
                                  if(yu < 8) yu++;
                                  if(xu > 3) xu = 0;
                                  if(yu > 7) yu = 4;
                                  pasos.restart();
                            }
                            personaje->Girar(3,xu,yu);
                     }
                        
                       if(event.key.code ==  sf::Keyboard::Down){
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xd < 4) xd++;
                                  if(yd < 4) yd++; 
                                  if(xd > 3) xd = 0;
                                  if(yd > 3) yd = 0;
                                  pasos.restart();
                            }
                            personaje->Girar(4,xd,yd);
                       }
                        
                       if(event.key.code == sf::Keyboard::Escape)
                            _datos->ventana.close();
                    
                    break;
            }        
            }
        }
        void InGame::Update(float dt)
        {
            if(_clock.getElapsedTime().asSeconds() > 3.0){
                   std::cout << "pasando tiempo "<< std::endl;
                     
            }
        }
        void InGame::Render(float dt)
        {
            _datos->ventana.clear();
            mapa->dibujarMapa(_datos->ventana);
            personaje->Pintar(); 
            _datos->ventana.display();
        }
        
   
}