

#include "Pocion.h"
#include "Mapa.h"

namespace Alfheim
{
Pocion::Pocion()
{}

 Pocion::Pocion(DatosJuegoRef datos, int tipo, sf::Vector2f pos) : _datos(datos) {
this->tipo = tipo;


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
    
    cantidad = 10;
    
    }

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
void Pocion::Pintar(){
   _datos->ventana.draw(pocionSprite);
}

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

void Pocion::elimina(){
pocionSprite.setTextureRect(sf::IntRect(0*170, 0*150, 0, 0));
}

}