#include "Nivel1.h"
#include <iostream>
#include <math.h>
namespace Alfheim{
    

Nivel1::Nivel1(DatosJuegoRef datos) : _datos(datos) {
    
  
             
}


void Nivel1::setMapa(const char* nombre){
    
    mapa = new Mapa(nombre);
    mapa->leerMapa();
}

Mapa *Nivel1::getMapa(){
    return this->mapa;
}

void Nivel1::setBloques(){
    this->setBloque(0,61,47);           
    this->setBloque(1,65,47);           
    this->setBloque(2,70,36);
    this->setBloque(3,23,29);
    this->setBloque(4,27,29);
    this->setBloque(5,54,13);
}

void Nivel1::setBloque(int i, int x, int y){
    bloques[i] = new Bloque();
    bloques[i]->Init(x,y);
}

Bloque *Nivel1::getBloque(int i){
    return this->bloques[i];
}

int Nivel1::ColisionBloque(int dire){
  
  int x = (int)floor(this->getBloque(0)->getBloque().getPosition().x);
  int y = (int)floor(this->getBloque(0)->getBloque().getPosition().y);
  
  if( this->getMapa()->colision1(this->getBloque(0)->getBloque().getGlobalBounds(),x,y,dire)){
  return 0; }
   x = (int)floor(this->getBloque(1)->getBloque().getPosition().x);
   y = (int)floor(this->getBloque(1)->getBloque().getPosition().y);
  
  if( this->getMapa()->colision1(this->getBloque(1)->getBloque().getGlobalBounds(),x,y,dire)){
  return 1; } 
   x = (int)floor(this->getBloque(2)->getBloque().getPosition().x);
   y = (int)floor(this->getBloque(2)->getBloque().getPosition().y);
  
  if( this->getMapa()->colision1(this->getBloque(2)->getBloque().getGlobalBounds(),x,y,dire)){
  return 2; }
   x = (int)floor(this->getBloque(3)->getBloque().getPosition().x);
   y = (int)floor(this->getBloque(3)->getBloque().getPosition().y);
  
  if( this->getMapa()->colision1(this->getBloque(3)->getBloque().getGlobalBounds(),x,y,dire)){
  return 3; }
   x = (int)floor(this->getBloque(4)->getBloque().getPosition().x);
   y = (int)floor(this->getBloque(4)->getBloque().getPosition().y);
  
  if( this->getMapa()->colision1(this->getBloque(4)->getBloque().getGlobalBounds(),x,y,dire)){
  return 4; }
   x = (int)floor(this->getBloque(5)->getBloque().getPosition().x);
   y = (int)floor(this->getBloque(5)->getBloque().getPosition().y);
  
  if( this->getMapa()->colision1(this->getBloque(5)->getBloque().getGlobalBounds(),x,y,dire)){
  return 5; }
  
  return -1;
}

void Nivel1::MoverBloques(int x, int i, sf::Sprite personaje){
     if(x!=0)this->getBloque(0)->Girar(i,personaje);
     if(x!=1)this->getBloque(1)->Girar(i,personaje);
     if(x!=2)this->getBloque(2)->Girar(i,personaje);
     if(x!=3)this->getBloque(3)->Girar(i,personaje);
     if(x!=4)this->getBloque(4)->Girar(i,personaje);
     if(x!=5)this->getBloque(5)->Girar(i,personaje);
                                
}
void Nivel1::PintarBloques(sf::RenderWindow& window, float pt){    
            this->getBloque(0)->Pintar(window, pt);
            this->getBloque(1)->Pintar(window, pt);
            this->getBloque(2)->Pintar(window, pt);
            this->getBloque(3)->Pintar(window, pt);
            this->getBloque(4)->Pintar(window, pt);
            this->getBloque(5)->Pintar(window, pt);
}

}