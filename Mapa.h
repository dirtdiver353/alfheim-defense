/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.h
 * Author: Victoria Hodelín Taranova
 *
 * Created on 22 de marzo de 2017, 18:09
 */

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
    bool colision(int x, int y);
    
    bool colision2(int x, int y, int dir);
    
    sf::Vector2f *getPosPocionesVida();
    int getNumPocionesVida();
    
    sf::Vector2f *getPosPocionesMana();
    int getNumPocionesMana();
    
    
 
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
    
    sf::Vector2f *posPocionesVida;
    int numPocionesVida;
    
    sf::Vector2f *posPocionesMana;
    int numPocionesMana;
       
    
    
};

#endif	/* CARGAR_H */

