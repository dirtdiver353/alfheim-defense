#include "Proyectil.h"
#include <iostream>
#include <math.h>
#define UPDATE_TICK_TIME 1000/15
#define PI 3.14159265
namespace Alfheim{
    

Proyectil::Proyectil(DatosJuegoRef datos) : _datos(datos) {
    
   if (!proyectilTexture.loadFromFile("resources/fireSmall.png"))
            {
                       exit(0);
            }
   animate =0;
             
}


void Proyectil::Pintar(float pt)
{
    for(unsigned short int i = 0; i < proyectilSprites.size(); i++){
    
    /* INTERPOLACION DE OBJETO */
    float lastProyectilX;
    float lastProyectilY;
    float newProyectilX = proyectilSprites.at(i).getPosition().x;
    float newProyectilY = proyectilSprites.at(i).getPosition().y;

    if(_updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){
        lastProyectilX = newProyectilX;
        lastProyectilY = newProyectilY;
        _updateClock.restart();
    }
    
    float proyectilX = lastProyectilX*(1-pt) + newProyectilX*pt;
    float proyectilY = lastProyectilY*(1-pt) + newProyectilY*pt;
                      
   proyectilSprites.at(i).setPosition(proyectilX,proyectilY);
   /* INTERPOLACION DE OBJETO */  
        
        
    _datos->ventana.draw(proyectilSprites.at(i));

    }
}

sf::Clock Proyectil::GetFuego() const {
            return fuego;
        }

        void Proyectil::SetFuego() {
            this->fuego.restart();
        }

void Proyectil::Spawn(sf::Sprite personaje, float x, float y)
{
   
    dire = 'l';
    float angulo = -((std::atan2(x-personaje.getPosition().x,y-personaje.getPosition().y) * 180 / PI)+90);
    sf::Sprite proyectil;
      float angulo2 = angulo*PI/180; 
            
             proyectil.setTexture(proyectilTexture);
             //Le pongo el centroide donde corresponde
             proyectil.setOrigin(333/2,333/2);
             //Cojo el sprite que me interesa por defecto del sheet
             proyectil.setTextureRect(sf::IntRect(0*333, 0*333, 333, 333));
             // Lo dispongo en su posicion en la pantalla
             proyectil.setPosition(x, y);
           //  std::cout << dire << std::endl;
             proyectil.setScale(0.2,0.2);
             float arr[] = {0,0};
           
                 arr[0]= std::cos(angulo2); arr[1]= std::sin(angulo2);
                 proyectil.rotate(angulo);
             
             
             speedFire1.push_back(arr[0]);
             speedFire2.push_back(arr[1]);
             proyectilSprites.push_back(proyectil);
             
}
 
void Proyectil::Update(float dt)
{
    
    
    for(unsigned short int i = 0; i < proyectilSprites.size(); i++){
        //sf::Vector2f posicion = proyectilSprites.at(i).getPosition();
        if(firing && (proyectilSprites.at(i).getPosition().y > 480 ||
            proyectilSprites.at(i).getPosition().y < 0 ||
            proyectilSprites.at(i).getPosition().x > 640 ||
            proyectilSprites.at(i).getPosition().x < 0))
        {
          
            proyectilSprites.erase(proyectilSprites.begin()+i);
             speedFire1.erase(speedFire1.begin()+i);             
             speedFire2.erase(speedFire2.begin()+i);
        }
        
        proyectilSprites.at(i).move(speedFire1.at(i),speedFire2.at(i));
        
        proyectilSprites.at(i).setTextureRect(sf::IntRect(animate*333, 0*333, 333, 333));
    } 
   
              if(clock.getElapsedTime().asSeconds() > 0.05){
               // std::cout<<animate<<std::endl;
                animate++;
                if(animate > 5) {animate = 0;}
                clock.restart();
              }
   //std::cout << proyectilSprites.size() << std::endl;
}

void Proyectil::setFiring(bool estado){
    firing = estado;
}
void Proyectil::Borrar(int x)
{
    for(unsigned short int i = 0; i < proyectilSprites.size(); i++){
       if(i == x)
        {
           proyectilSprites.erase(proyectilSprites.begin()+i);
       }
        
        
    } 
    
}


const std::vector<sf::Sprite> &Proyectil::GetSprites() const
{
    return proyectilSprites;
}



}