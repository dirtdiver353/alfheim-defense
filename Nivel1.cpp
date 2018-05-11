#include "Nivel1.h"
#include <iostream>

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
    bloques[i] = new Bloque(_datos);
    bloques[i]->Init(x,y);
}

Bloque *Nivel1::getBloque(int i){
    return this->bloques[i];
}

void Nivel1::MoverBloques(int i, sf::Sprite personaje){
     this->getBloque(0)->Girar(i,personaje);
     this->getBloque(1)->Girar(i,personaje);
     this->getBloque(2)->Girar(i,personaje);
     this->getBloque(3)->Girar(i,personaje);
     this->getBloque(4)->Girar(i,personaje);
     this->getBloque(5)->Girar(i,personaje);
                                
}
void Nivel1::PintarBloques(){    
            this->getBloque(0)->Pintar();
            this->getBloque(1)->Pintar();
            this->getBloque(2)->Pintar();
            this->getBloque(3)->Pintar();
            this->getBloque(4)->Pintar();
            this->getBloque(5)->Pintar();
}

}