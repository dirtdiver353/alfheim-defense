#pragma once

#include <sstream>
#include "EstadoInGame.h"
#include <iostream>

namespace Alfheim
{
   
       EstadoInGame::EstadoInGame(DatosJuegoRef datos) : _datos(datos)
       {
           
            if (!_backgroundTexture.loadFromFile("resources/outer.png"))
            {
                std::cerr << "Error cargando la imagen fondo.png";
                exit(0);
            }    
            
            _background.setTexture(_backgroundTexture);
       }
        
        void EstadoInGame::Init()
        {
            personaje = new Personaje(_datos);
        }
        
        void EstadoInGame::ManejarEventos()
        {
           
                     
            sf::Event event;
            while(_datos->ventana.pollEvent(event))
            {
                
            switch(event.type){
                
                case sf::Event::Closed:
                    _datos->ventana.close();
                break;
                
                case sf::Event::KeyPressed:
                   
                    switch(event.key.code) {
                        
                        case sf::Keyboard::Right:
                            if(pasos.getElapsedTime().asSeconds() > 0.1f){
                                if(xs < 8) xs++;
                                if(xs > 7) xs = 4;
                                if(ys < 4) ys++;                                
                                if(ys > 3) ys = 0;
                                pasos.restart();
                            }
                            personaje->Girar(1,xs,ys);
                        break;

                        case sf::Keyboard::Left:
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xs < 8) xs++;
                                  if(ys < 4) ys++;
                                  if(xs > 7) xs = 4;
                                  if(ys > 3) ys = 0;
                                  pasos.restart();
                            }
                            personaje->Girar(2,xs,ys);
                        break;
                        
                        case sf::Keyboard::Up:
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xu < 4) xu++;
                                  if(yu < 8) yu++;
                                  if(xu > 3) xu = 0;
                                  if(yu > 7) yu = 4;
                                  pasos.restart();
                            }
                            personaje->Girar(3,xu,yu);
                        break;
                        
                        case sf::Keyboard::Down:
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xd < 4) xd++;
                                  if(yd < 4) yd++; 
                                  if(xd > 3) xd = 0;
                                  if(yd > 3) yd = 0;
                                  pasos.restart();
                            }
                            personaje->Girar(4,xd,yd);
                        break;
                        
                        case sf::Keyboard::Escape:
                            _datos->ventana.close();
                        break;
                       
                        default:
                            std::cout << event.key.code << std::endl;
                        break;
                              
                    }

                }
            }
        }
        void EstadoInGame::Update(float dt)
        {
            if(_clock.getElapsedTime().asSeconds() > 3.0){
                   std::cout << "pasando tiempo "<< std::endl;
                     
            }
        }
        void EstadoInGame::Render(float dt)
        {
            _datos->ventana.clear();
            _datos->ventana.draw(_background);
            personaje->Pintar(); 
            _datos->ventana.display();
        }
        
   
}