#include "Bloque.h"
#include <iostream>
#include <sstream>

namespace Alfheim{
    

Bloque::Bloque(DatosJuegoRef datos) : _datos(datos) {
    
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
             _bloque.setPosition(320, 240);
             _bloque.scale(1/6.6875,1/6.6875);
             
            
}

void Bloque::Pintar()
{
   
    _datos->ventana.draw(_bloque);
    
    
}

void Bloque::Girar(int dl)
{
    int kVel = 4;
        
        if(dl == 1) {_bloque.move(kVel,0);}
        if(dl == 2) {_bloque.move(-kVel,0);}
        if(dl == 3) {_bloque.move(0,-kVel);}
        if(dl == 4) {_bloque.move(0,kVel);}
     
}

void Bloque::Update(float dt)
{
           
}

sf::Sprite Bloque::getBloque(){
     return _bloque;
 }

}