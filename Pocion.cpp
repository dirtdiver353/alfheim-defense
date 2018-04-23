

#include "Pocion.h"

namespace Alfheim
{

Pocion::Pocion(DatosJuegoRef datos, int x, int y, int t) : _datos(datos) {
    tipo = t;
    
    if(tipo == 1){ // pocion vida
        cantidad = 100;
         if (!pocionTexture.loadFromFile("resources/heart.png"))
           {
                      exit(0);
           }    

           pocionSprite.setTexture(pocionTexture);

    }else if (tipo == 2){ // pocion mana
        cantidad = 100;
         if (!pocionTexture.loadFromFile("resources/mago.png"))
           {
                      exit(0);
           }    

           pocionSprite.setTexture(pocionTexture);
    }

    //Le pongo el centroide donde corresponde
   // pocionSprite.setOrigin(170/2,150/2);
    //Cojo el sprite que me interesa por defecto del sheet
    pocionSprite.setTextureRect(sf::IntRect(0*170, 0*150, 170, 150));
    pocionSprite.setScale(0.25,0.25);
    // Lo dispongo en su posicion en la pantalla
    pocionSprite.setPosition(x, y);
}

void Pocion::Pintar(){
    _datos->ventana.draw(pocionSprite);
}
void Pocion::Update(float dt){}
void Pocion::Eliminar(){}

int Pocion::getCantidad(){
    return cantidad;
}
int Pocion::getTipo(){
    return tipo;
}



}