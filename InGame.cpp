#pragma once

#include <sstream>
#include "InGame.h"
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
   
       InGame::InGame(DatosJuegoRef datos) : _datos(datos)
       {
           level1 = true;
           level2 = false;
           nivel1 = new Nivel1(_datos);
           const char * torre = "TorreZostar.tmx";
           nivel1->setMapa(torre);
           nivel1->setBloques(); 
           
           
            
       }
        
        void InGame::Init()
        {
           
            personaje = new Personaje(_datos);
            posPJ = personaje->getPosicion();
            recPJ = personaje->getRect();
            proyectil = new Proyectil(_datos);
            proyectil1 = new Proyectil(_datos);
            proyectil2 = new Proyectil(_datos);
            arma = new Arma(_datos);
            
           /*INTERFAZ*/
            hud = new Hud(_datos);
            hud->SetPuntos(personaje->getPuntos()); 
            hud->SetMana(personaje->getMana());
            hud->SetVida(personaje->getVida());
            
            if(level1){
            /*ENEMIGOS*/
            sf::Vector2f posEnemy;
            posEnemy.x = 200;
            posEnemy.y = 430;
            enemy = new Enemigo(_datos,1,posEnemy,nivel1->getMapa(),1);
            
            posEnemy.x = 100;
            posEnemy.y = 80;
            enemy1 = new Enemigo(_datos,1,posEnemy,nivel1->getMapa(),1);
            
            posEnemy.x = 340;
            posEnemy.y = 260;
            enemy2 = new Enemigo(_datos,1,posEnemy,nivel1->getMapa(),1);
            
            /*POCIONES*/
                posPV = new sf::Vector2f[5];
                posPV[0].x = 120;
                posPV[0].y = 200;
                pV1 = new Pocion(_datos,1,posPV[0]);
                
                posPV[1].x = 600;
                posPV[1].y = 450;
                pV2 = new Pocion(_datos,1,posPV[1]);
                
                posPV[2].x = 580;
                posPV[2].y = 150;
                pV3 = new Pocion(_datos,1,posPV[2]);


                posPM =  new sf::Vector2f[5];
                posPM[0].x = 120;
                posPM[0].y = 300;
                pM1 = new Pocion(_datos,2,posPM[0]);
                
                posPM[1].x = 600;
                posPM[1].y = 230;
                pM2 = new Pocion(_datos,2,posPM[1]);
            }
           
        }
        
        void InGame::ManejarEventos()
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
                    if(event.key.code == sf::Keyboard::L){
                        // prueba pantalla de fin de partida
                        
                        if(level1){
                            level1 = true;
                            level2 = false;
                  
                        _datos->state.AddEJ(JuegoStateRef(new InGame2(_datos)),true);
                        
                        }
           
                    
                    }
                    
                   
                    if(event.key.code == sf::Keyboard::Right){
                       // std::cout << "peta ants right "<< std::endl;
                            
                       // posPJ = personaje->getPosicion();
                       // std::cout << "peta dsps right "<< std::endl;
                        int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                        lastDir='r';
                        recPJ = personaje->getRect();
                        //int x = (int)floor(recPJ.left);
                        //int y = (int)floor(recPJ.top);
                        if(level1 && nivel1->getMapa()->colision1(recPJ,x,y,dire) )
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
                               nivel1->MoverBloques(nivel1->ColisionBloque(1),1,personaje->getPersonaje());
                        }
                            
                            
                    }
                    
                     if(event.key.code == sf::Keyboard::Left){
                       //  posPJ = personaje->getPosicion();
                         int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                         recPJ = personaje->getRect();
                         lastDir='l';
                        //int x = (int)floor(recPJ.left);
                       // int y = (int)floor(recPJ.top);
                        if(level1 && nivel1->getMapa()->colision1(recPJ,x,y,dire))
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
                           // if(!nivel1->getMapa()->colision(posPJ.x,posPJ.y))
                                personaje->Girar(2,xs,ys);
                                dire = 'l';
                                 nivel1->MoverBloques(nivel1->ColisionBloque(2),2,personaje->getPersonaje());
                        }
                     }
                        
                     if(event.key.code ==  sf::Keyboard::Up){
                        // posPJ = personaje->getPosicion();
                        int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                         recPJ = personaje->getRect();
                         lastDir='u';
                        //int x = (int)floor(recPJ.left);
                        //int y = (int)floor(recPJ.top);
                        if(level1 && nivel1->getMapa()->colision1(recPJ,x,y,dire))
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
                           // if(!nivel1->getMapa()->colision(posPJ.x,posPJ.y))
                                personaje->Girar(3,xu,yu);
                                dire = 'u';
                              nivel1->MoverBloques(nivel1->ColisionBloque(3),3,personaje->getPersonaje());
                        }
                     }
                        
                       if(event.key.code ==  sf::Keyboard::Down){
                         //  posPJ = personaje->getPosicion();
                          int x = (int)floor(posPJ.x);
                        int y = (int)floor(posPJ.y);
                        recPJ = personaje->getRect();
                        lastDir='d';
                        //int x = (int)floor(recPJ.left);
                       // int y = (int)floor(recPJ.top);
                        if(level1 && nivel1->getMapa()->colision1(recPJ,x,y,dire))
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
                           // if(!nivel1->getMapa()->colision(posPJ.x,posPJ.y))
                                personaje->Girar(4,xd,yd);
                                dire = 'd';
                                nivel1->MoverBloques(nivel1->ColisionBloque(4),4,personaje->getPersonaje());
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
        void InGame::Update(float dt)
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
            
              std::vector<sf::Sprite> proyectil1Sprites = proyectil1->GetSprites();
                       
            for(int i = 0; i < proyectil1Sprites.size();i++)
            {
                
                if(!proyectil1->IsFirstime(i) && personaje->getPersonaje().getGlobalBounds().contains(proyectil1Sprites.at(i).getPosition())){
                    
                      std::cout << "redu;cir salud de personaje" << std::endl;
                      proyectil1->SetFirstime(i,true);
                }
                
            }
            
            
            if(proyectil1->GetFuego().getElapsedTime().asSeconds() > proyectil1->GetRandom()){
                
                proyectil1->setFiring(true);
                proyectil1->Spawn(personaje->getPersonaje(),enemy1->getEnemigo().getPosition().x, enemy1->getEnemigo().getPosition().y);
                proyectil1->setFiring(false); 
                proyectil1->SetFuego();
                proyectil1->SetRandom(((float)(rand()%900+401))/100);
            }
            
               std::vector<sf::Sprite> proyectil2Sprites = proyectil2->GetSprites();
                       
            for(int i = 0; i < proyectil2Sprites.size();i++)
            {
                
                if(!proyectil2->IsFirstime(i) && personaje->getPersonaje().getGlobalBounds().contains(proyectil2Sprites.at(i).getPosition())){
                    
                      std::cout << "redu;cir salud de personaje" << std::endl;
                      proyectil2->SetFirstime(i,true);
                }
                
            }
            
            
            if(proyectil2->GetFuego().getElapsedTime().asSeconds() > proyectil2->GetRandom()){
                
                proyectil2->setFiring(true);
                proyectil2->Spawn(personaje->getPersonaje(),enemy2->getEnemigo().getPosition().x, enemy2->getEnemigo().getPosition().y);
                proyectil2->setFiring(false); 
                proyectil2->SetFuego();
                proyectil2->SetRandom(((float)(rand()%900+401))/100);
            }
            
            
            if(_clock.getElapsedTime().asSeconds() > 1.0){
                arma->Update(dt); 
                 proyectil->Update(dt); 
                 proyectil1->Update(dt); 
                 proyectil2->Update(dt); 
            }
            
            if(level1 && _clock.getElapsedTime().asSeconds() > 0.05f){
                  // std::cout << "updatin "<< std::endl;
            hud->SetPuntos(personaje->getPuntos()); 
            hud->SetMana(personaje->getMana());
            hud->SetVida(personaje->getVida());
             //std::cout << "peya update "<< std::endl;
          //  posPJ = personaje->getPosicion();
            posPJ = personaje->getPosicion();
            
            //IA enemigo
            if(enemy != NULL){
                enemy->caminar();
                enemy->detectaPersonaje2(recPJ);
                enemy->recibeDanyo(arma->GetSprites(), 1);
                
                if(enemy->compruebaMuerte()){
                    personaje->setPuntos(personaje->getPuntos()+10);
                    enemy = NULL;
                }
            }
            
            if(enemy1!=NULL){
                enemy1->caminar();
                enemy1->detectaPersonaje2(recPJ);
                enemy1->recibeDanyo(arma->GetSprites(), 1);
                
                if(enemy1->compruebaMuerte()){
                    personaje->setPuntos(personaje->getPuntos()+10);
                    enemy1 = NULL;
                }
            }
            
            if(enemy2!=NULL){
                enemy2->caminar();
                enemy2->detectaPersonaje2(recPJ);
                enemy2->recibeDanyo(arma->GetSprites(), 1);
                
                if(enemy2->compruebaMuerte()){
                    personaje->setPuntos(personaje->getPuntos()+10);
                    enemy2 = NULL;
                }
            
            }
            
            /*  CAMBIO ESTADOS DE MENU */
            if( personaje->compruebaMuerte()){
                _datos->state.AddEJ(JuegoStateRef(new MenuMuerte(_datos,1)),true);
            }
            
            
            
                   
            }
            
            if(personaje->getPersonaje().getPosition().y <= 0 && level1){
                level1 = false;
                level2 = true;
                  //delete mapa;
                  _datos->state.AddEJ(JuegoStateRef(new InGame2(_datos)),true);
       
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
            if(pV3->getSprite().getGlobalBounds().intersects(personaje->getRect()))
            {       personaje->cogePocion(1);
                    pV3->elimina();

            }
            if(pM1->getSprite().getGlobalBounds().intersects(personaje->getRect()))
            {       personaje->cogePocion(2);
                    pM1->elimina();

            }
            if(pM2->getSprite().getGlobalBounds().intersects(personaje->getRect()))
            {       personaje->cogePocion(2);
                    pM2->elimina();

            }
            
            
        }
        
        
        void InGame::Render(float pt)
        {
            _datos->ventana.clear();
            
            
            nivel1->getMapa()->dibujarMapa(_datos->ventana);
            /*                     
            pV->Pintar();
            pM->Pintar();
            
           */
            pV1->Pintar();
             pV2->Pintar();
             pV3->Pintar();
             pM1->Pintar();
             pM2->Pintar();
             
             
            
            //pocPrueba->Pintar();
            _datos->ventana.draw(hud->GetTxtVida());
            _datos->ventana.draw(hud->GetTxtMana());
            _datos->ventana.draw(hud->GetTxtPuntos());
            
            arma->Pintar(pt);
            nivel1->PintarBloques(_datos->ventana, pt);
            proyectil->Pintar(pt);
            proyectil1->Pintar(pt);
            proyectil2->Pintar(pt);
            personaje->Pintar(pt); 
            if(enemy!= NULL){
                enemy->Pintar(pt);
            }
            
            if(enemy1!= NULL){
                enemy1->Pintar(pt);
            }
            
            if(enemy2!= NULL){
                enemy2->Pintar(pt);
            }
                       
            
            
            _datos->ventana.display();
        }
        
   
}