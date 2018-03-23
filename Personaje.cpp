#include "Personaje.h"

namespace Galaga{
    

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
             // Lo dispongo en su posicion en la pantalla
             _personaje.setPosition(320, 240);
}

void Personaje::Pintar()
{
    _datos->ventana.draw(_personaje);
}

void Personaje::Girar(int dl, int x, int y)
{
    
    int kVel = 4;
   // if(clock.getElapsedTime().asSeconds() > 0.1f){ 
        
    if(dl != 3){
        
        if(dl == 4) _personaje.move(0,kVel); 
        if(dl == 1) _personaje.move(kVel,0); _personaje.setScale(-1,1);
        if(dl == 2) _personaje.move(-kVel,0);
    }if(dl == 3){
        
        _personaje.move(0,-kVel); 
    }
    
    _personaje.setTextureRect(sf::IntRect(x*64, y*64, 64, 64));
    //clock.restart();}     
}

void Personaje::Update(float dt)
{
           
}

}