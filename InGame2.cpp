#pragma once


#include "InGame2.h"
#include "MenuMuerte.h"
#include "MenuFinal.h"
#include "Menu.h"
#include <iostream>


namespace Alfheim
{
   
       InGame2::InGame2(DatosJuegoRef datos) : _datos(datos)
       {
           level1 = false;
           level2 = true;
           nivel2 = new Nivel2(_datos);
           const char * torre = "CiudadRuinas.tmx";
           nivel2->setMapa(torre);
           nivel2->setBloques(); 
           
           
            
       }
        
        void InGame2::Init()
        {
           
            personaje = new Personaje(_datos);
                      
            arma = new Arma(_datos);
            proyectil = new Proyectil(_datos);
            
            personaje->setMana(personaje->getMana()+20);
            personaje->setVida(personaje->getVida()+50);
       
            /*INTERFAZ*/
            hud = new Hud(_datos);
            hud->SetPuntos(personaje->getPuntos()); 
            hud->SetMana(personaje->getMana());
            hud->SetVida(personaje->getVida());
            
            if(level2){
            /*ENEMIGOS*/
            sf::Vector2f posEnemy;
            posEnemy.x = 400;
            posEnemy.y = 430;
            enemy = new Enemigo(_datos,1,posEnemy,nivel2->getMapa(),2);
            
            /*POCIONES*/
                posPV = new sf::Vector2f[5];
                posPV[0].x = 20;
                posPV[0].y = 260;
                pV1 = new Pocion(_datos,1,posPV[0]);
                
                posPV[1].x = 600;
                posPV[1].y = 320;
                pV2 = new Pocion(_datos,1,posPV[1]);
                
                posPM =  new sf::Vector2f[5];
                posPM[0].x = 320;
                posPM[0].y = 245;
                pM1 = new Pocion(_datos,2,posPM[0]);
                
                posPM[1].x = 70;
                posPM[1].y = 100;
                pM2 = new Pocion(_datos,2,posPM[1]);
                
                posPM[2].x = 600;
                posPM[2].y = 230;
                pM3 = new Pocion(_datos,2,posPM[2]);
            }
            
           
        }
        
        void InGame2::ManejarEventos()
        {
            if(level2){
                     
            sf::Event event;
            while(_datos->ventana.pollEvent(event))
            {
                
            switch(event.type){
                
                case sf::Event::Closed:
                    _datos->ventana.close();
                break;
                
                case sf::Event::KeyPressed:
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
                        int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                        lastDir='r';
                        recPJ = personaje->getRect();
                       
                        if(level2 && nivel2->getMapa()->colision2(recPJ,x,y,dire) )
                        {    
                            std::cout << "choca "<< std::endl;
                            if(lastDir != dire){
                                personaje->Girar(1,xs,ys);
                                dire = 'r';
                            }
                        }
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
                               nivel2->MoverBloques(nivel2->ColisionBloque(1),1,personaje->getPersonaje());
                        }
                            
                            
                    }
                    
                     if(event.key.code == sf::Keyboard::Left){
                       
                         int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                         recPJ = personaje->getRect();
                         lastDir='l';
                        
                        if(level2 && nivel2->getMapa()->colision2(recPJ,x,y,dire))
                        {    
                            std::cout << "choca "<< std::endl;
                            if(lastDir != dire){
                                personaje->Girar(2,xs,ys);
                                dire = 'l';
                            }
                        }
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
                                 nivel2->MoverBloques(nivel2->ColisionBloque(2),2,personaje->getPersonaje());
                        }
                     }
                        
                     if(event.key.code ==  sf::Keyboard::Up){
                         int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                         recPJ = personaje->getRect();
                         lastDir='u';
                        
                       if(level2 && nivel2->getMapa()->colision2(recPJ,x,y,dire))
                        {    
                            std::cout << "choca "<< std::endl;
                            if(lastDir != dire){
                                personaje->Girar(3,xu,yu);
                                dire = 'u';
                            }
                        }
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
                              nivel2->MoverBloques(nivel2->ColisionBloque(3),3,personaje->getPersonaje());
                        }
                     }
                        
                       if(event.key.code ==  sf::Keyboard::Down){
                           int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                        recPJ = personaje->getRect();
                        lastDir='d';
                      
                       if(level2 && nivel2->getMapa()->colision2(recPJ,x,y,dire))
                        {    
                            std::cout << "choca "<< std::endl;
                            if(lastDir != dire){
                                personaje->Girar(4,xd,yd);
                                dire = 'd';
                            }
                        }
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
                                nivel2->MoverBloques(nivel2->ColisionBloque(4),4,personaje->getPersonaje());
                        }
                            
                       }
                    
                    if(event.key.code == sf::Keyboard::Space){
                        if(personaje->getMana() >=10){
                            arma->setFiring(true);
                            arma->Spawn(dire,personaje->getPersonaje().getPosition().x, personaje->getPersonaje().getPosition().y);

                            personaje->lanzaHechizo();
                        }
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
            std::vector<sf::Sprite> proyectilSprites = proyectil->GetSprites();
                       
            for(int i = 0; i < proyectilSprites.size();i++)
            {
                
                if(!proyectil->IsFirstime(i) && personaje->getPersonaje().getGlobalBounds().contains(proyectilSprites.at(i).getPosition())){
                    
                      std::cout << "redu;cir salud de personaje" << std::endl;
                      proyectil->SetFirstime(i,true);
                }
                
            }
            
            
            if(proyectil->GetFuego().getElapsedTime().asSeconds() > proyectil->GetRandom()){
                
                proyectil->setFiring(true);
                proyectil->Spawn(personaje->getPersonaje(),enemy->getEnemigo().getPosition().x, enemy->getEnemigo().getPosition().y);
                proyectil->setFiring(false); 
                proyectil->SetFuego();
                proyectil->SetRandom(((float)(rand()%900+401))/100);
            }
            if(_clock.getElapsedTime().asSeconds() > 1.0){
                arma->Update(dt); 
                proyectil->Update(dt); 
            }
            
            if(level2 && _clock.getElapsedTime().asSeconds() > 0.05f){
                  // std::cout << "updatin "<< std::endl;
            hud->SetPuntos(personaje->getPuntos()); 
            hud->SetMana(personaje->getMana());
            hud->SetVida(personaje->getVida());
             //std::cout << "peya update "<< std::endl;
          //  posPJ = personaje->getPosicion();
            posPJ = personaje->getPosicion();
            
           
            
            /*  CAMBIO ESTADOS DE MENU */
            if( personaje->compruebaMuerte()){
                _datos->state.AddEJ(JuegoStateRef(new MenuMuerte(_datos,2)),true);
            }
            
            
            
                   
            }
            
            //IA enemigo
            enemy->caminar();
            
            
            if(personaje->getPersonaje().getPosition().y <= 0 && level2){
                
                  _datos->state.AddEJ(JuegoStateRef(new MenuFinal(_datos)),true);
            }
            
             /*Eliminando sprites de pociones al cogerlas*/
            if(pV1->getSprite().getGlobalBounds().intersects(personaje->getRect()))
            {       personaje->cogePocion(1);
                    pV1->elimina();

            }
            if(pV2->getSprite().getGlobalBounds().intersects(personaje->getRect()))
            {       personaje->cogePocion(1);
                    pV2->elimina();

            }
            if(pM1->getSprite().getGlobalBounds().intersects(personaje->getRect()))
            {       personaje->cogePocion(2);
                    pM1->elimina();

            }
            if(pM2->getSprite().getGlobalBounds().intersects(personaje->getRect()))
            {       personaje->cogePocion(2);
                    pM2->elimina();

            }
            if(pM3->getSprite().getGlobalBounds().intersects(personaje->getRect()))
            {       personaje->cogePocion(2);
                    pM3->elimina();

            }
            
            /*TRAMPAS PISADAS*/
            if(level2 && nivel2->pisaTrampa(posPJ.x, posPJ.y)){
                
                 _datos->state.AddEJ(JuegoStateRef(new MenuMuerte(_datos,2)),true);
            }
            

        }
        
        void InGame2::Render(float pt)
        {
            _datos->ventana.clear();
            
              
            
            nivel2->getMapa()->dibujarMapa(_datos->ventana);
            
            pV1->Pintar();
             pV2->Pintar();
             
             pM1->Pintar();
             pM2->Pintar();
            pM3->Pintar();
            
            
            
          
            _datos->ventana.draw(hud->GetTxtVida());
            _datos->ventana.draw(hud->GetTxtMana());
            _datos->ventana.draw(hud->GetTxtPuntos());
            
            nivel2->PintarBloques(_datos->ventana, pt);
            arma->Pintar(pt);
            proyectil->Pintar(pt);
           
            
            personaje->Pintar(pt); 
            enemy->Pintar(pt);
            
            
            _datos->ventana.display();
        }
        
   
}