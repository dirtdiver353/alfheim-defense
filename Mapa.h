#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>

class Mapa {
public:
    
    Mapa(const char * str1);
    Mapa(const Mapa& orig);
    virtual ~Mapa();    
    void leerMapa();
    void dibujarMapa(sf::RenderWindow &window); 
     
    bool colision1(sf::FloatRect fr, int x, int y,char d);
    bool colision2(sf::FloatRect fr, int x, int y,char d);
    
    sf::Vector2f * getTrampas();
    int getNumTrampas();
    
    
    
    
 
private:
    
    int ***_tilemap;
    int _numLayers;
    int _height;
    int _tileHeigth;
    int _width;
    int _tileWidth;
    const char *_filename;
    
    sf::Sprite ****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    sf::Sprite fondoSprite;
    
    sf::Texture _tilesetTexture;
    sf::Texture fondoTexture;
    
    int numTrampas;
    sf::Vector2f * posTrampas;
    
    
       
    
    
};

#endif	/* CARGAR_H */