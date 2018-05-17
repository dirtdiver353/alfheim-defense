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
#define UPDATE_TICK_TIME 1000/15
namespace Alfheim{
    
Enemigo::Enemigo(DatosJuegoRef datos, int tipo, sf::Vector2f pos, Mapa* map, int lvl) : _datos(datos) {
    
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
             
             mapa = map;
             nivel = lvl;
             // Inicializo contadores de vida, mana y puntos
             vida = 5;
             danyo = 1;
             ataca = false;
             direccion = rand () % 4;
    
    }else if (tipo == 2){
    
    
    }
             
}

bool Enemigo::caminar(){
    bool camina = false;
    sf::FloatRect fr = _enemigo.getGlobalBounds();
        int x = (int)floor(_enemigo.getPosition().x);
        int y = (int)floor(_enemigo.getPosition().y);
       
        char dir;
        if(direccion == 0 ){
            dir='r';
            x+=5;
        }
        else if (direccion == 1){
            dir = 'l';
            x-=5;
        }
        else if(direccion == 2){
            dir = 'u';
            y+=5;
        }
        else if(direccion == 3){
            dir = 'd';
            y-=5;
        }
        
        
        if(nivel == 1 && !ataca){
            if(mapa->colision1(fr,x,y,dir)){
            //choca
            //elige otra dirección
             std::cout << "enemigo choca "<< std::endl;
            direccion = rand () % 4;
        
            }else{

                 //enemy->Pintar(dt);
                camina = true;

            }
        } else if (nivel == 2 && !ataca){
            if(mapa->colision2(fr,x,y,dir)){
            //choca
            //elige otra dirección
             std::cout << "enemigo choca "<< std::endl;
            direccion = rand () % 4;
        
            }else{

                 //enemy->Pintar(dt);
                camina = true;

            }
        }
        
        
        return camina;


}
void Enemigo::Update(float dt){
    
    

}



void Enemigo::setEnemigo(int tipo, sf::Vector2f pos){

    

}

sf::Sprite Enemigo::getEnemigo() const {
            return _enemigo;
        }

void Enemigo::Pintar(float pt)
{
     /* INTERPOLACION DE OBJETO */  
   
    //_personaje.setScale(0.75,0.75);
    sf::Vector2f pos = _enemigo.getPosition();
    float lastPosX;
    float lastPosY;
    float enemyX;  
    float enemyY;
    
     if(_updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){
        lastPosX = pos.x;
        lastPosY = pos.y;
        _updateClock.restart();
    }
    
    if(!ataca){
    if(direccion == 0 ){
            //dir='r';
           // x+=80;
            enemyX = (lastPosX)*(1-pt) + (pos.x+5)*pt;
            enemyY = (lastPosY)*(1-pt) + (pos.y)*pt;
        }
        else if (direccion == 1){
           // dir = 'l';
           // x-=80;
            enemyX = (lastPosX)*(1-pt) + (pos.x-5)*pt;
            enemyY = (lastPosY)*(1-pt) + (pos.y)*pt;
        }
        else if(direccion == 2){
           // dir = 'u';
            //y+=80;
            enemyX = (lastPosX)*(1-pt) + (pos.x)*pt;
            enemyY = (lastPosY)*(1-pt) + (pos.y+5)*pt;
        }
        else if(direccion == 3){
           // dir = 'd';
           // y-=80;
            enemyX = (lastPosX)*(1-pt) + (pos.x)*pt;
            enemyY = (lastPosY)*(1-pt) + (pos.y-5)*pt;
        }
    
               
   _enemigo.setPosition(enemyX,enemyY);
    }
    
     /* INTERPOLACION DE OBJETO */
    
    _datos->ventana.draw(_enemigo);   
    
}

int Enemigo::getVida(){
    return vida;
}

void Enemigo::elimina(){
_enemigo.setTextureRect(sf::IntRect(0, 0, 0, 0));
}

void Enemigo::recibeDanyo(std::vector<sf::Sprite> sp,int cant){
    
    if(sp.size()!=0){
    sf::FloatRect fr = sp.at(sp.size()-1).getGlobalBounds();
    if(_enemigo.getGlobalBounds().intersects(fr)){
            std::cout << "danyo recibido" << std::endl;
        
            vida -=cant;
        if(vida <= 0){
            std::cout << "muerto" << std::endl;
            muerto = true;
        }
    
    }
    }
    
   /* for(unsigned short int i = 0; i < sp.size(); i++){
        sf::FloatRect fr = sp.at(i).getGlobalBounds();
        
        if(_enemigo.getGlobalBounds().intersects(fr)){
            std::cout << "danyo recibido" << std::endl;
        
            vida -=cant;
        if(vida <= 0){
            std::cout << "muerto" << std::endl;
            muerto = true;
        }
    }
    } */
    
    
    
    
    
    
}

bool Enemigo::detectaPersonaje(int xpj, int ypj){
    bool detecta = false;
    
    int xdif;
    int ydif;
    
    xdif = _enemigo.getPosition().x - xpj;
    ydif = _enemigo.getPosition().y - ypj;
    
    if(xdif < 0)
        xdif = xdif*(-1);
    
    if (ydif < 0)
        ydif = ydif*(-1);
    
    if (xdif > ydif && ydif <= 5)
    {
        detecta = true;
        ataca = true;
    
    } else if (xdif < ydif && xdif <=5)
    {
        detecta = true;
        ataca = true;
    
    } else{
        ataca = false;
    
    }
    /*if (xdif <= 5 || ydif <= 5){
        detecta = true;
        ataca = true;
        std::cout << "detecta" << std::endl;
    } else{
        ataca = false;
    }*/
    
    return detecta;
}

bool Enemigo::detectaPersonaje2(sf::FloatRect fr){
    bool detecta = false;
    sf::FloatRect fre = _enemigo.getGlobalBounds();
    
    if (fre.intersects(fr)){
        detecta = true;
        ataca = true;
    }else{
        ataca = false;
    }
    
    return detecta;
}





}

