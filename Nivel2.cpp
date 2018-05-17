#include "Nivel2.h"
#include <iostream>

namespace Alfheim{
    

Nivel2::Nivel2(DatosJuegoRef datos) : _datos(datos) {
    
  
             
}


void Nivel2::setMapa(const char* nombre){
    
    mapa = new Mapa(nombre);
    mapa->leerMapa();
    posTrampas = mapa->getTrampas();
    numTrampas = mapa->getNumTrampas();
}

Mapa *Nivel2::getMapa(){
    return this->mapa;
}

void Nivel2::setBloques(){
    this->setBloque(0,62,47);           
    this->setBloque(1,66,47);           
    this->setBloque(2,37,45);
    this->setBloque(3,18,29);
    this->setBloque(4,33,18);
    this->setBloque(5,29,18);
}

void Nivel2::setBloque(int i, int x, int y){
    bloques[i] = new Bloque();
    bloques[i]->Init(x,y);
}

Bloque *Nivel2::getBloque(int i){
    return this->bloques[i];
}

void Nivel2::MoverBloques(int i, sf::Sprite personaje){
     this->getBloque(0)->Girar(i,personaje);
     this->getBloque(1)->Girar(i,personaje);
     this->getBloque(2)->Girar(i,personaje);
     this->getBloque(3)->Girar(i,personaje);
     this->getBloque(4)->Girar(i,personaje);
     this->getBloque(5)->Girar(i,personaje);
                                
}
void Nivel2::PintarBloques(sf::RenderWindow& window, float pt){    
            this->getBloque(0)->Pintar(window, pt);
            this->getBloque(1)->Pintar(window, pt);
            this->getBloque(2)->Pintar(window, pt);
            this->getBloque(3)->Pintar(window, pt);
            this->getBloque(4)->Pintar(window, pt);
            this->getBloque(5)->Pintar(window, pt);
}

bool Nivel2::pisaTrampa(int x, int y){

    
    
    
    
    x = (int)floor(x);
    y = (int)floor(y);
    
    for(int i = 0;  i < numTrampas; i++){
        int aux1 = (int)floor(posTrampas[i].x*8);
        int aux2 =  (int)floor(posTrampas[i].y*8);
        if(y == aux1 && x == aux2)
            return true;
        
    }
    
    return false;
}

}