//Esta seria la 'maquina de states' para añadir, cambiar state...
#pragma once

#include <memory>
#include <stack>

#include "State.h"

namespace Alfheim
{
    typedef std::unique_ptr <State> JuegoStateRef;
    
    class JuegoState
    {
    public:
        JuegoState(){}
        ~JuegoState(){}
        
        void AddEJ(JuegoStateRef nuevoEJ, bool reemplaza = true);
        void RemoveEJ();
        
        void ProcesarCambiosEJ();
        JuegoStateRef &GetActivoEJ();
        
    private:
        std::stack<JuegoStateRef> _statesEJ;
        JuegoStateRef _nuevoEJ;
        
        bool _borra;
        bool _agrega;
        bool _reemplaza;
    };
}