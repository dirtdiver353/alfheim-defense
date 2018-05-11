
#include <SFML/Graphics.hpp>
#include "Juego.h"

namespace Alfheim
{

    class Bloque
    {
    public:
        Bloque( DatosJuegoRef datos);
        
        void Init(int x, int y);
        void Pintar();

        void Update(float dt);
        void Girar(int dl, sf::Sprite personaje);
        
        
        sf::Sprite getBloque();

    private:
        DatosJuegoRef _datos;
        sf::Texture _bloqueTexture;
        sf::Sprite _bloque;
        sf::Clock clock;
        
      
        
    };
}