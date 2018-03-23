
#include "Juego.h"
#include "EstadoInGame.h"

namespace Alfheim
{
    

    Juego::Juego(int ancho, int alto, std::string titulo) 
    {
        _datos->ventana.create(sf::VideoMode(ancho, alto), titulo);
        _datos->estado.AddEJ(EstadoJuegoRef(new EstadoInGame(this->_datos)));
        this->Iniciar();
    }

        
    void Juego::Iniciar()
    {
        float newTime, frameTime, interpolacion;
        
        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float acumulador = 0.0f;
        
        while (this->_datos->ventana.isOpen())
        {
            this->_datos->estado.ProcesarCambiosEJ();
            newTime = this ->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            
            if(frameTime > 0.25f)
            {
                frameTime = 0.25f;
            }
            
            currentTime = newTime;
            acumulador += frameTime;
            
            while (acumulador >= dt)
            {
                this->_datos->estado.GetActivoEJ()->ManejarEventos();
                this->_datos->estado.GetActivoEJ()->Update(dt);
                
                acumulador -= dt;
        }

            interpolacion = acumulador / dt;
            this->_datos->estado.GetActivoEJ()->Render(interpolacion);
        }
    }
}