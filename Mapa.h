#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>

class Mapa {
public:
    
    Mapa();
    Mapa(const Mapa& orig);
    virtual ~Mapa();    
    void leerMapa();
    void dibujarMapa(sf::RenderWindow &window); 
    
 
private:
    
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

#endif	/* CARGAR_H */
