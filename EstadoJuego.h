//Esta seria la 'maquina de estados' para añadir, cambiar estado...
#pragma once

#include <memory>
#include <stack>

#include "Estado.h"

namespace Alfheim
{
    typedef std::unique_ptr <Estado> EstadoJuegoRef;
    
    class EstadoJuego
    {
    public:
        EstadoJuego(){}
        ~EstadoJuego(){}
        
        void AddEJ(EstadoJuegoRef nuevoEJ, bool reemplaza = true);
        void RemoveEJ();
        
        void ProcesarCambiosEJ();
        EstadoJuegoRef &GetActivoEJ();
        
    private:
        std::stack<EstadoJuegoRef> _estadosEJ;
        EstadoJuegoRef _nuevoEJ;
        
        bool _borra;
        bool _agrega;
        bool _reemplaza;
    };
}