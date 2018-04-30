
#include "Interfaz.h"

namespace Alfheim
{
    
Interfaz::Interfaz(DatosJuegoRef datos){
    
    // Establece texto y posicion de contadores
            _txtVida.setFont(txtFont);
            _txtVida.setColor(sf::Color::White);
            _txtVida.setString("Vida: "+std::to_string(personaje->getVida()));
            // title.setScale(1.1, 1.1);
            _txtVida.setPosition(sf::Vector2f(10, 10));
            
            _txtMana.setFont(txtFont);
            _txtMana.setColor(sf::Color::White);
            _txtMana.setString("Mana: "+std::to_string(personaje->getMana()));
            // title.setScale(1.1, 1.1);
            _txtMana.setPosition(sf::Vector2f(10, 25));
            
            _txtPuntos.setFont(txtFont);
            _txtPuntos.setColor(sf::Color::White);
            _txtPuntos.setString("Puntos: "+std::to_string(personaje->getPuntos()));
            // title.setScale(1.1, 1.1);
            _txtPuntos.setPosition(sf::Vector2f(10, 40));
           

}

void Interfaz::Pintar(){
    _datos->ventana.draw(_txtVida);
    _datos->ventana.draw(_txtMana);
    _datos->ventana.draw(_txtPuntos);

}
void Interfaz::Update(float dt){
    if(_clock.getElapsedTime().asSeconds() > 3.0){}
            

}

}