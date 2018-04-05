//Esta seria la 'maquina de states' para añadir, cambiar state...
#include "JuegoState.h"
#include <iostream>

namespace Alfheim
{
    void JuegoState::AddEJ(JuegoStateRef nuevoEJ, bool reemplaza)
    {
        this->_agrega = true;
        this->_reemplaza = reemplaza;
                 std::cout<< "eeeeeja" << std::endl;
        this-> _nuevoEJ = std::move(nuevoEJ); 
        
    }
    
    void JuegoState::RemoveEJ()
    {
        this->_borra = true;
    }
    
    void JuegoState::ProcesarCambiosEJ()
    {
    
     
        if (this->_borra && !this->_statesEJ.empty())
        {
            this->_statesEJ.pop();
            
            if(!this->_statesEJ.empty())
            {
                this->_statesEJ.top()->Resume(); 
            } 
            
            this->_borra = false;
            
        }
        if(this->_agrega)
        {
            if(!this->_statesEJ.empty())
            {
                if(this->_reemplaza)
                {
                    this->_statesEJ.pop();
                }
                else
                {
                    this->_statesEJ.top()->Pause();
                }
            }
            this->_statesEJ.push(std::move(this->_nuevoEJ));
            this->_statesEJ.top()->Init();
            this->_agrega = false;
        
        }
    }
    
    JuegoStateRef &JuegoState::GetActivoEJ()
    {
        return this->_statesEJ.top();
    }
}