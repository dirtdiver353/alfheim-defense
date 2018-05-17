#include "Bloque.h"
#include <iostream>
#include <sstream>

#define UPDATE_TICK_TIME 1000/15

Bloque::Bloque() {
    
    
            
}

void Bloque::Init( int x, int y){
    if (!_bloqueTexture.loadFromFile("resources/bloque.png"))
            {
                       exit(0);
            }    
            
            _bloque.setTexture(_bloqueTexture);
             //Le pongo el centroide donde corresponde
             _bloque.setOrigin(214/2,214/2);
             //Cojo el sprite que me interesa por defecto del sheet
             _bloque.setTextureRect(sf::IntRect(0*214, 0*214, 214, 214));
             //_bloque.setScale(0.75,0.75);
             // Lo dispongo en su posicion en la pantalla
             _bloque.setPosition(x*8, y*8);
             _bloque.scale(1/6.6875,1/6.6875);
             
}

void Bloque::Pintar(sf::RenderWindow& window, float pt)
{
    /* INTERPOLACION DE OBJETO */
    float lastBloqueX;
    float lastBloqueY;
    float newBloqueX = this->getBloque().getPosition().x;
    float newBloqueY = this->getBloque().getPosition().y;

    if(_updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){
        lastBloqueX = newBloqueX;
        lastBloqueY = newBloqueY;
        _updateClock.restart();
    }
    
    float bloqueX = lastBloqueX*(1-pt) + newBloqueX*pt;
    float bloqueY = lastBloqueY*(1-pt) + newBloqueY*pt;
                      
   _bloque.setPosition(bloqueX,bloqueY);
   /* INTERPOLACION DE OBJETO */
   
    window.draw(_bloque);
    
    
}

void Bloque::Girar(int dl, sf::Sprite bloque)
{
    int kVel = 4;
        
      if(dl == 1 && _bloque.getGlobalBounds().contains(bloque.getPosition().x, bloque.getPosition().y+24)){
                
             _bloque.move(kVel,0);}
    
        if(dl == 2 && _bloque.getGlobalBounds().contains(bloque.getPosition().x, bloque.getPosition().y+24 )){
                
            _bloque.move(-kVel,0);}
    
        if(dl == 3 && _bloque.getGlobalBounds().contains(bloque.getPosition().x, bloque.getPosition().y+24 )){
                
            _bloque.move(0,-kVel);}
    
        if(dl == 4 && _bloque.getGlobalBounds().contains(bloque.getPosition().x, bloque.getPosition().y+24 )){
                             
            _bloque.move(0,kVel);}
     
}

void Bloque::Update(float dt)
{
           
}

sf::Sprite Bloque::getBloque(){
     return _bloque;
 }

