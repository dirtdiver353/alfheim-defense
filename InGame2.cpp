#pragma once

#include <sstream>
#include "InGame2.h"
#include "MenuMuerte.h"
#include "MenuFinal.h"
#include "Menu.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#define UPDATE_TICK_TIME 1000/15

namespace Alfheim
{
   
       InGame2::InGame2(DatosJuegoRef datos) : _datos(datos)
       {
           level1 = true;
           level2 = false;
           nivel2 = new Nivel2(_datos);
           const char * torre = "CiudadRuinas.tmx";
           nivel2->setMapa(torre);
           nivel2->setBloques(); 
           
           if(level1){
           posPocionesVida = nivel2->getMapa()->getPosPocionesVida();
           numPocionesVida = nivel2->getMapa()->getNumPocionesVida();
           posPocionesMana = nivel2->getMapa()->getPosPocionesMana();
           numPocionesMana = nivel2->getMapa()->getNumPocionesMana();
           }
            
       }
        
        void InGame2::Init()
        {
           
            personaje = new Personaje(_datos);
            posPJ = personaje->getPosicion();
            recPJ = personaje->getRect();
            
            arma = new Arma(_datos);
            
           /*INTERFAZ*/
            hud = new Hud(_datos);
            hud->SetPuntos(personaje->getPuntos()); 
            hud->SetMana(personaje->getMana());
            hud->SetVida(personaje->getVida());
            
            /*POCIONES*/
            pVida = new Pocion[numPocionesVida];
            for(int i = 0; i < numPocionesVida && pVida!=NULL; i++){
                
                pVida[i].setPocion(posPocionesVida[i],1);
               // std::cout << "set poti"<<posPocionesVida[i].x << posPocionesVida[i].y<< std::endl;
            
            }
            
            pMana = new Pocion[numPocionesMana];
            for(int i = 0; i < numPocionesMana; i++){
                
                pMana[i].setPocion(posPocionesMana[i],2);
               // std::cout << "set poti"<<posPocionesVida[i].x << posPocionesVida[i].y<< std::endl;
            
            }
            
            /*ENEMIGOS*/
            sf::Vector2f posEnemy;
            posEnemy.x = 200;
            posEnemy.y = 120;
            enemy = new Enemigo(_datos,1,posEnemy);
            
            //enemy->setEnemigo(1,posEnemy);
           
        }
        
        void InGame2::ManejarEventos()
        {
            if(level1){
                     
            sf::Event event;
            while(_datos->ventana.pollEvent(event))
            {
                
            switch(event.type){
                
                case sf::Event::Closed:
                    _datos->ventana.close();
                break;
                
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::P){
                        // prueba puntos para ver si actualiza
                        personaje->setPuntos(100);
                    
                    }
                    if(event.key.code == sf::Keyboard::M){
                        // prueba pantalla de muerte
                        personaje->setVida(0);
                    
                    }
                    if(event.key.code == sf::Keyboard::F){
                        // prueba pantalla de fin de partida
                        _datos->state.AddEJ(JuegoStateRef(new MenuFinal(_datos)),true);
           
                    
                    }
                    if(event.key.code == sf::Keyboard::I){
                        // prueba truco invencible
                        bool esInvencible = personaje->getInvencible();
                        
                        if(!esInvencible){
                            std::cout << "soy invencible "<< std::endl;
                            personaje->setInvencible(true);
                        }
                        else
                        {
                            std::cout << "ya no soy invencible "<< std::endl;
                            personaje->setInvencible(false);
                        }
                    
                    }
                    
                   
                    if(event.key.code == sf::Keyboard::Right){
                       // std::cout << "peta ants right "<< std::endl;
                            
                       // posPJ = personaje->getPosicion();
                       // std::cout << "peta dsps right "<< std::endl;
                        int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                        
                        //recPJ = personaje->getRect();
                        //int x = (int)floor(recPJ.left);
                        //int y = (int)floor(recPJ.top);
                        if(level1 && nivel2->getMapa()->colision2(x,y,4))
                            std::cout << "choca "<< std::endl;
                        else{
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                if(xs < 8) xs++;
                                if(xs > 7) xs = 4;
                                if(ys < 4) ys++;                                
                                if(ys > 3) ys = 0;
                                pasos.restart();
                            }
                            
                                personaje->Girar(1,xs,ys);
                                dire = 'r';
                               nivel2->MoverBloques(1,personaje->getPersonaje());
                        }
                            
                            
                    }
                    
                     if(event.key.code == sf::Keyboard::Left){
                       //  posPJ = personaje->getPosicion();
                         int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                         //recPJ = personaje->getRect();
                        //int x = (int)floor(recPJ.left);
                       // int y = (int)floor(recPJ.top);
                        if(level1 && nivel2->getMapa()->colision2(x,y,3))
                            std::cout << "choca "<< std::endl;
                        else{
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xs < 8) xs++;
                                  if(ys < 4) ys++;
                                  if(xs > 7) xs = 4;
                                  if(ys > 3) ys = 0;
                                  pasos.restart();
                            }
                           // if(!nivel2->getMapa()->colision(posPJ.x,posPJ.y))
                                personaje->Girar(2,xs,ys);
                                dire = 'l';
                                 nivel2->MoverBloques(2,personaje->getPersonaje());
                        }
                     }
                        
                     if(event.key.code ==  sf::Keyboard::Up){
                        // posPJ = personaje->getPosicion();
                        int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                        // recPJ = personaje->getRect();
                        //int x = (int)floor(recPJ.left);
                        //int y = (int)floor(recPJ.top);
                        if(level1 && nivel2->getMapa()->colision2(x,y,1))
                            std::cout << "choca "<< std::endl;
                        else{
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xu < 4) xu++;
                                  if(yu < 8) yu++;
                                  if(xu > 3) xu = 0;
                                  if(yu > 7) yu = 4;
                                  pasos.restart();
                            }
                           // if(!nivel2->getMapa()->colision(posPJ.x,posPJ.y))
                                personaje->Girar(3,xu,yu);
                                dire = 'u';
                              nivel2->MoverBloques(3,personaje->getPersonaje());
                        }
                     }
                        
                       if(event.key.code ==  sf::Keyboard::Down){
                         //  posPJ = personaje->getPosicion();
                          int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                        //   recPJ = personaje->getRect();
                        //int x = (int)floor(recPJ.left);
                       // int y = (int)floor(recPJ.top);
                        if(level1 && nivel2->getMapa()->colision2(x,y,2))
                            std::cout << "choca "<< std::endl;
                        else{
                            if(pasos.getElapsedTime().asSeconds() > 0.07f){
                                  if(xd < 4) xd++;
                                  if(yd < 4) yd++; 
                                  if(xd > 3) xd = 0;
                                  if(yd > 3) yd = 0;
                                  pasos.restart();
                            }
                           // if(!nivel2->getMapa()->colision(posPJ.x,posPJ.y))
                                personaje->Girar(4,xd,yd);
                                dire = 'd';
                                nivel2->MoverBloques(4,personaje->getPersonaje());
                        }
                            
                       }
                    
                    if(event.key.code == sf::Keyboard::Space){
                        arma->setFiring(true);
                        arma->Spawn(dire,personaje->getPersonaje().getPosition().x, personaje->getPersonaje().getPosition().y);
                    
                    } 
                       if(event.key.code == sf::Keyboard::Escape)
                            _datos->ventana.close();
                    
                    
                    
                    break;
                    
                    case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::Space){
                        arma->setFiring(false);
                    }
                    break;
            }        
            }}
        }
        void InGame2::Update(float dt)
        {
            
            
            if(_clock.getElapsedTime().asSeconds() > 1.0){
                arma->Update(dt); 
                
            }
            
            if(level1 && _clock.getElapsedTime().asSeconds() > 0.05f){
                  // std::cout << "updatin "<< std::endl;
            hud->SetPuntos(personaje->getPuntos()); 
            hud->SetMana(personaje->getMana());
            hud->SetVida(personaje->getVida());
             //std::cout << "peya update "<< std::endl;
          //  posPJ = personaje->getPosicion();
            posPJ = personaje->getPosicion();
            /*  CAMBIO ESTADOS DE MENU */
            if( personaje->compruebaMuerte()){
                _datos->state.AddEJ(JuegoStateRef(new MenuMuerte(_datos)),true);
            }
                   
            }
            
            if(personaje->getPersonaje().getPosition().y <= 0 && level1){
                level1 = false;
                level2 = true;
                  //delete mapa;
                  _datos->state.AddEJ(JuegoStateRef(new InGame2(_datos)),true);
       
            }
        }
        
        void InGame2::Render(float dt)
        {
            _datos->ventana.clear();
             if(level1){
            /*Interpolacion de objetos, de momento personaje*/
               float pt = std::min(1.f, this->_updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME 
                ? (float)this->_updateClock.getElapsedTime().asMilliseconds(): UPDATE_TICK_TIME );
            
               float lastPersonajeX;
               float lastPersonajeY;
               float newPersonajeX = personaje->getPersonaje().getPosition().x;
               float newPersonajeY = personaje->getPersonaje().getPosition().y;
               
               if(_updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){
                   lastPersonajeX = newPersonajeX;
                   lastPersonajeY = newPersonajeY;
                   _updateClock.restart();
               }
             
            /*Interpolacion de objetos, de momento personaje*/
            
            nivel2->getMapa()->dibujarMapa(_datos->ventana);
                                   
            for(int i = 0; i < numPocionesVida && level1; i++){
                _datos->ventana.draw( pVida[i].getSprite());
               // pVida[i].Pintar();
            }
            
            for(int i = 0; i < numPocionesMana && level1; i++){
                _datos->ventana.draw( pMana[i].getSprite());
               // pVida[i].Pintar();
            }
            
           
            enemy->Pintar();
            //pocPrueba->Pintar();
            _datos->ventana.draw(hud->GetTxtVida());
            _datos->ventana.draw(hud->GetTxtMana());
            _datos->ventana.draw(hud->GetTxtPuntos());
            
            arma->Pintar();
            nivel2->PintarBloques();
            
            personaje->Pintar(pt, lastPersonajeX,lastPersonajeY,newPersonajeX,newPersonajeY); 
            }
            
            _datos->ventana.display();
        }
        
   
}