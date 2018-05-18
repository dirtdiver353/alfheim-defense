
#include "Hud.h"
#include <iostream>
#include <sstream>
namespace Alfheim
{
Hud::Hud(DatosJuegoRef datos) {
    
     personaje = new Personaje(_datos);
     
    if(!txtFont.loadFromFile("OpenSans-Regular.ttf")){
        std::cerr << "This output is ti to cout\n";
    }
    
   // txtVida = new sf::Text;
    txtVida.setFont(txtFont);
    txtVida.setColor(sf::Color::White);
    txtVida.setString("Vida: 0");
    txtVida.setPosition(100,0);
    
    txtMana.setFont(txtFont);
    txtMana.setColor(sf::Color::White);
    txtMana.setString("Mana: 0");
    txtMana.setPosition(280,0);
    
    txtPuntos.setFont(txtFont);
    txtPuntos.setColor(sf::Color::White);
    txtPuntos.setString("Puntos: 0");
    txtPuntos.setPosition(460,0);
    
    // std::cout << "incialiazo "<< std::endl;
}

void Hud::SetPuntos(int p){
    txtPuntos.setString("Puntos: "+std::to_string(p));   

}

void Hud::SetVida(int p){
    txtVida.setString("Vida: "+std::to_string(p));   

}

void Hud::SetMana(int p){
    txtMana.setString("Mana: "+std::to_string(p));   

}

sf::Text Hud::GetTxtVida(){
    return txtVida;
}

sf::Text Hud::GetTxtPuntos(){
    return txtPuntos;
}

sf::Text Hud::GetTxtMana(){
    return txtMana;
}

void Hud::Pintar(){
    // no va no se pq 
     std::cout << "pintando "<< std::endl;
    _datos->ventana.draw(txtVida);
}

Hud::Hud(const Hud& orig) {
}

Hud::~Hud() {
}

}