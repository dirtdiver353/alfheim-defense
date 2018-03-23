//Esta seria la 'maquina de estados' para añadir, cambiar estado...
#include "EstadoJuego.h"

namespace Alfheim
{
    void EstadoJuego::AddEJ(EstadoJuegoRef nuevoEJ, bool reemplaza)
    {
        this->_agrega = true;
        this->_reemplaza = reemplaza;
                
        this-> _nuevoEJ = std::move(nuevoEJ); 
        
    }
    
    void EstadoJuego::RemoveEJ()
    {
        this->_borra = true;
    }
    
    void EstadoJuego::ProcesarCambiosEJ()
    {
    
     
        if (this->_borra && !this->_estadosEJ.empty())
        {
            this->_estadosEJ.pop();
            
            if(!this->_estadosEJ.empty())
            {
                this->_estadosEJ.top()->Resume(); 
            } 
            
            this->_borra = false;
            
        }
        if(this->_agrega)
        {
            if(!this->_estadosEJ.empty())
            {
                if(this->_reemplaza)
                {
                    this->_estadosEJ.pop();
                }
                else
                {
                    this->_estadosEJ.top()->Pause();
                }
            }
            this->_estadosEJ.push(std::move(this->_nuevoEJ));
            this->_estadosEJ.top()->Init();
            this->_agrega = false;
        
        }
    }
    
    EstadoJuegoRef &EstadoJuego::GetActivoEJ()
    {
        return this->_estadosEJ.top();
    }
}