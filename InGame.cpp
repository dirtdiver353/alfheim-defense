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
            
            /* POCION DE PRUEBA */
          pocPrueba = new Pocion(_datos, 32, 32, 1);
            
            
            
            
            // Establece texto y posicion de contadores
            _txtVida.setFont(txtFont);
            _txtVida.setColor(sf::Color::White);
            _txtVida.setString("Vida: "+std::to_string(personaje->getVida()));
            // title.setScale(1.1, 1.1);
            _txtVida.setPosition(sf::Vector2f(10, 10));
            
            _txtMana.setFont(txtFont);
            _txtMana.setColor(sf::Color::White);
            _txtMana.setString("Mana: "+std::to_string(personaje->getMana()));
            // title.setScale(1.1, 1.1);
            _txtMana.setPosition(sf::Vector2f(10, 25));
            
            _txtPuntos.setFont(txtFont);
            _txtPuntos.setColor(sf::Color::White);
            _txtPuntos.setString("Puntos: "+std::to_string(personaje->getPuntos()));
            // title.setScale(1.1, 1.1);
            _txtPuntos.setPosition(sf::Vector2f(10, 40));
           
            
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
                            
                            
                            /* PUNTOS DE PERSONAJE PRUEBA*/
                            // ganar puntos y actualizar en pantalla
                            personaje->setPuntos(personaje->getPuntos()+1);
                             _txtPuntos.setString("Puntos: "+std::to_string(personaje->getPuntos()));
           
                            std::cout << personaje->getPuntos()<< std::endl;
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
                   std::cout << "updatin "<< std::endl;
                   
                   
                   
            }
        }
        void InGame::Render(float dt)
        {
            _datos->ventana.clear();
             mapa->dibujarMapa(_datos->ventana);
             
            _datos->ventana.draw(_txtVida);
            _datos->ventana.draw(_txtMana);
            _datos->ventana.draw(_txtPuntos);
            
            
           
            personaje->Pintar(); 
            
            pocPrueba->Pintar();
            
            _datos->ventana.display();
            
            std::cout << "rendering "<< std::endl;
        }
        
   
}