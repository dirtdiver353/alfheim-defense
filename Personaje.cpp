#include "Personaje.h"
#include <iostream>
#include <sstream>

namespace Alfheim{
    

Personaje::Personaje(DatosJuegoRef datos) : _datos(datos) {
    
    if (!_personajeTexture.loadFromFile("resources/mago.png"))
            {
                       exit(0);
            }    
            
            _personaje.setTexture(_personajeTexture);
             //Le pongo el centroide donde corresponde
             _personaje.setOrigin(64/2,64/2);
             //Cojo el sprite que me interesa por defecto del sheet
             _personaje.setTextureRect(sf::IntRect(0*64, 0*64, 64, 64));
             //_personaje.setScale(0.75,0.75);
             // Lo dispongo en su posicion en la pantalla
             _personaje.setPosition(6*8, 50*8);
             
             
             // Inicializo contadores de vida, mana y puntos
             vida = 100;
             puntos = 0;
             mana = 100;
}

void Personaje::Pintar(float pt, float lastPersonajeX, float lastPersonajeY, float newPersonajeX, float newPersonajeY)
{
    float personajeX = lastPersonajeX*(1-pt) + newPersonajeX*pt;
    float personajeY = lastPersonajeY*(1-pt) + newPersonajeY*pt;
               
   _personaje.setPosition(personajeX,personajeY);
    _datos->ventana.draw(_personaje);
    
    
}

void Personaje::Girar(int dl, int x, int y)
{
    int kVel = 4;
        
        if(dl == 1) {_personaje.move(kVel,0); _personaje.setScale(-1,1);}
        if(dl == 2) {_personaje.move(-kVel,0); _personaje.setScale(1,1);}
        if(dl == 3) {_personaje.move(0,-kVel); }
        if(dl == 4) {_personaje.move(0,kVel); }
        
    _personaje.setTextureRect(sf::IntRect(x*64, y*64, 64, 64));

}

void Personaje::Update(float dt)
{
           
}

void Personaje::setVida(int i){
    vida = i;
};
void Personaje::setMana(int i){
    mana = i;
};
void Personaje::setPuntos(int i){
    puntos = i;
};

int Personaje::getVida(){
    return vida;
};
int Personaje::getMana(){
    return mana;
};
int Personaje::getPuntos(){
    return puntos;
};


bool Personaje::recibeDanyo(int cant){
    // si no está activado el truco de invecibilidad
    // recibe daño    
    if(!invencible){
        if(vida > cant){
            vida -= cant;
            if(vida <= 0)
            {
                muerto = true;
            }
        }
        return true;
    }
    
    return false;
}

void Personaje::setInvencible(bool i){
    
    invencible = i;
    
}

bool Personaje::getInvencible(){
    return invencible;
}


bool Personaje::compruebaMuerte(){
    if(vida <= 0)
        muerto = true;
    return muerto;
}

 sf::Vector2f Personaje::getPosicion(){
    // std::cout << "pj x y "<<  _personaje.getPosition().x << _personaje.getPosition().y<< std::endl;
    return _personaje.getPosition();
 
 }
 
 sf::FloatRect Personaje::getRect(){
     return _personaje.getGlobalBounds();
 }
 
 sf::Sprite Personaje::getPersonaje(){
     return _personaje;
 }

/*void Personaje::cogePocion(int tipo, int cant){
    
    if(tipo == 1){
        vida+=cant;
    }else if(tipo==2){
        mana+=cant;
    }
}*/

}