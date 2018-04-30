

#include "Pocion.h"
#include "Mapa.h"

namespace Alfheim
{
Pocion::Pocion()
{}

/*Pocion::Pocion(DatosJuegoRef datos, int t) : _datos(datos) {
    tipo = t;
    
    if(tipo == 1){ // pocion vida
        cantidad = 100;
         if (!pocionTexture.loadFromFile("resources/vida.png"))
           {
                      exit(0);
           }    

           pocionSprite.setTexture(pocionTexture);

    }else if (tipo == 2){ // pocion mana
        cantidad = 100;
         if (!pocionTexture.loadFromFile("resources/mana.png"))
           {
                      exit(0);
           }    

           pocionSprite.setTexture(pocionTexture);
    }

    //Le pongo el centroide donde corresponde
   // pocionSprite.setOrigin(170/2,150/2);
    //Cojo el sprite que me interesa por defecto del sheet
    pocionSprite.setTextureRect(sf::IntRect(0*170, 0*150, 170, 150));
    pocionSprite.setScale(0.75,0.75);
    // Lo dispongo en su posicion en la pantalla
   // pocionSprite.setPosition(x, y);
}*/

void Pocion::setPocion(sf::Vector2f pos, int t){
   tipo = t;
    
    if(tipo == 1){ // pocion vida
        cantidad = 100;
         if (!pocionTexture.loadFromFile("resources/vida.png"))
           {
                      exit(0);
           }    

           pocionSprite.setTexture(pocionTexture);

    }else if (tipo == 2){ // pocion mana
        cantidad = 100;
         if (!pocionTexture.loadFromFile("resources/mana.png"))
           {
                      exit(0);
           }    

           pocionSprite.setTexture(pocionTexture);
    }
    //pocionSprite.setTextureRect(sf::IntRect(0*170, 0*150, 170, 150));
    pocionSprite.setScale(0.50,0.50);
    pocionSprite.setPosition(pos.x, pos.y);

}

/*void Pocion::Pintar(){
   _datos->ventana.draw(pocionSprite);
}
*/

sf::Sprite Pocion::getSprite(){
    return pocionSprite;
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