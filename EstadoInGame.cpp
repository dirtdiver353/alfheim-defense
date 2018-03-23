#pragma once

#include <sstream>
#include "EstadoInGame.h"
#include <iostream>

namespace Galaga
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
            int xd = 0, yd = 0, xu = 0, ys = 0;
            int yu = 4, xs = 4;
            sf::Clock clock;
                     
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
                            if(clock.getElapsedTime().asSeconds() > 0.1f){
                                if(xs < 8) xs++;
                                if(xs > 7) xs = 4;
                                if(ys < 4) ys++;                                
                                if(ys > 3) ys = 0;
                                clock.restart();
                            }
                            personaje->Girar(1,xs,ys);
                        break;

                        case sf::Keyboard::Left:
                            personaje->Girar(2,4,0);
                        break;
                        
                        case sf::Keyboard::Up:
                            personaje->Girar(3,0,4);
                        break;
                        
                        case sf::Keyboard::Down:
                            personaje->Girar(4,0,0);
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