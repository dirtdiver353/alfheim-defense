#pragma once

#include <SFML/Graphics.hpp>
#include "Juego.h"

namespace Galaga
{

    class Map
    {
    public:
        
    Map( DatosJuegoRef datos);
    Map(const Map& orig);
    virtual ~Map();    
    void leerMapa();
    void Pintar(); 
        
    private:
        DatosJuegoRef _datos;
         
    int ***_tilemap;
    int _numLayers;
    int _height;
    int _tileHeigth;
    int _width;
    int _tileWidth;    
    
    sf::Sprite ****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    sf::Sprite fondoSprite;
    
    sf::Texture _tilesetTexture;
    sf::Texture fondoTexture;
    };
}