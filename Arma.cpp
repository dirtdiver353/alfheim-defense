#include "Arma.h"
#include <iostream>
#define UPDATE_TICK_TIME 1000/15
namespace Alfheim{
    

Arma::Arma(DatosJuegoRef datos) : _datos(datos) {
    
   if (!armaTexture.loadFromFile("resources/flameSmall.png"))
            {
                       exit(0);
            }
   animate =0;
             
}


void Arma::Pintar(float pt)
{
    for(unsigned short int i = 0; i < armaSprites.size(); i++){
    
    /* INTERPOLACION DE OBJETO */
    float lastArmaX;
    float lastArmaY;
    float newArmaX = armaSprites.at(i).getPosition().x;
    float newArmaY = armaSprites.at(i).getPosition().y;

    if(_updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME){
        lastArmaX = newArmaX;
        lastArmaY = newArmaY;
        _updateClock.restart();
    }
    
    float armaX = lastArmaX*(1-pt) + newArmaX*pt;
    float armaY = lastArmaY*(1-pt) + newArmaY*pt;
                      
   armaSprites.at(i).setPosition(armaX,armaY);
   /* INTERPOLACION DE OBJETO */  
        
        
    _datos->ventana.draw(armaSprites.at(i));

    }
}

void Arma::Spawn(char dir, float x, float y)
{
    dire = dir;
    
    sf::Sprite arma;
      
            
             arma.setTexture(armaTexture);
             //Le pongo el centroide donde corresponde
             arma.setOrigin(333/2,333/2);
             //Cojo el sprite que me interesa por defecto del sheet
             arma.setTextureRect(sf::IntRect(0*333, 0*333, 333, 333));
             // Lo dispongo en su posicion en la pantalla
             arma.setPosition(x, y);
           //  std::cout << dire << std::endl;
             arma.setScale(0.2,0.2);
             int arr[] = {0,0};
             if(dire == 'u'){
                 arr[0]=0; arr[1]=-2;
                arma.rotate(-90);
             }
             else if(dire == 'd'){
                 arr[0]=0; arr[1]=2;
                arma.rotate(90);
             }
             else if(dire == 'l'){
                 arr[0]=-2; arr[1]=0;
                 arma.rotate(180);
             }
             else if(dire == 'r'){
                  arr[0]=2; arr[1]=0;
             }
              else{
                  arr[0]=0; arr[1]=2;
                arma.rotate(90);
              }
             
             speedFire1.push_back(arr[0]);
             speedFire2.push_back(arr[1]);
             armaSprites.push_back(arma);
             
}
 
void Arma::Update(float dt)
{
    
    
    for(unsigned short int i = 0; i < armaSprites.size(); i++){
        //sf::Vector2f posicion = armaSprites.at(i).getPosition();
        if(firing && (armaSprites.at(i).getPosition().y > 480 ||
            armaSprites.at(i).getPosition().y < 0 ||
            armaSprites.at(i).getPosition().x > 640 ||
            armaSprites.at(i).getPosition().x < 0))
        {
          
            armaSprites.erase(armaSprites.begin()+i);
             speedFire1.erase(speedFire1.begin()+i);             
             speedFire2.erase(speedFire2.begin()+i);
        }
        
        armaSprites.at(i).move(speedFire1.at(i),speedFire2.at(i));
        
        armaSprites.at(i).setTextureRect(sf::IntRect(animate*333, 0*333, 333, 333));
    } 
   
              if(clock.getElapsedTime().asSeconds() > 0.05){
               // std::cout<<animate<<std::endl;
                animate++;
                if(animate > 5) {animate = 0;}
                clock.restart();
              }
   //std::cout << armaSprites.size() << std::endl;
}

void Arma::setFiring(bool estado){
    firing = estado;
}
void Arma::Borrar(int x)
{
    for(unsigned short int i = 0; i < armaSprites.size(); i++){
       if(i == x)
        {
           armaSprites.erase(armaSprites.begin()+i);
       }
        
        
    } 
    
}


const std::vector<sf::Sprite> &Arma::GetSprites() const
{
    return armaSprites;
}



}