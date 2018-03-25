#include "Map.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace Galaga{
    

Map::Map(DatosJuegoRef datos) : _datos(datos) {
    
   
}

Map::Map(const Map& orig) {
}

// BORRAR MAPA
Map::~Map() {
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            delete[] _tilemap[l][y];
        }
        delete[] _tilemap[l];
    }
    delete[] _tilemap;
}



// LEER MAPA
void Map::leerMapa(){
    
    // Cargo archivo de mapa
    TiXmlDocument *doc = new TiXmlDocument();   
    doc->LoadFile("TorreZostar.tmx");      
    
    // Guarda atributos de mapa tmx
    TiXmlElement* map = doc->FirstChildElement("map");
    map->QueryIntAttribute("width",&_width);
    map->QueryIntAttribute("height",&_height);
    map->QueryIntAttribute("tilewidth",&_tileWidth);
    map->QueryIntAttribute("tileheight",&_tileHeigth);
    
    // Leemos los tilesets, obtiene numero de tilesets
    TiXmlElement *imgTileset = map->FirstChildElement("tileset");
    int numTileset = 0;
    while(imgTileset){
        numTileset++;
        imgTileset=imgTileset->NextSiblingElement("tileset");
    }
    
    // Almacenamos tilesets como spritesheets
    std::string filename; 
    imgTileset = map->FirstChildElement("tileset");
   
    while(imgTileset){
        filename=(std::string)imgTileset->FirstChildElement("image")->Attribute("source");
        imgTileset=imgTileset->NextSiblingElement("tileset");
    }    
    
    _tilesetTexture.loadFromFile(filename);  
    _numLayers=0;
    //leemos las diferentes capas
    TiXmlElement *layer = map->FirstChildElement("layer");
    while(layer){
        _numLayers++;
        layer= layer->NextSiblingElement("layer");
    }  
    
    //Reserva de memoria para capas 
    _tilemap=new int**[_numLayers];
    for(int i=0; i<_numLayers; i++){
        _tilemap[i]=new int*[_height];
    }
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            _tilemap[l][y]=new int[_width];
        }
    }

    TiXmlElement *data;    
    std::string *name=new std::string[_numLayers];  
    int j=0;
    int l=0;
    // Lee tiles de xml
    layer = map->FirstChildElement("layer");
    while(layer){
        data= layer->FirstChildElement("data")->FirstChildElement("tile");
        name[j]= (std::string)layer->Attribute("name");
        
        
            while(data){
                for(int y=0; y<_height; y++){
                    for(int x=0; x<_width;x++){
                        data->QueryIntAttribute("gid",&_tilemap[l][y][x]);
                        data=data->NextSiblingElement("tile");
                    }
                }
            }
        l++;
        layer= layer->NextSiblingElement("layer");
        j++;
    }
      
    //Reserva de memoria para los sprites
    _tilemapSprite=new sf::Sprite***[_numLayers];
      
    for(int l=0; l<_numLayers; l++){
        _tilemapSprite[l]=new sf::Sprite**[_height];
    }
      
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            _tilemapSprite[l][y]= new sf::Sprite*[_width];
            for(int x=0; x<_width; x++){
                _tilemapSprite[l][y][x]=new sf::Sprite();
            }
        }
    } 
    
    int columns = _tilesetTexture.getSize().x / _tileWidth;
    int rows = _tilesetTexture.getSize().y / _tileHeigth;
    
    _tilesetSprite =new sf::Sprite[columns*rows];     
    int t=0;
    for(int y=0; y<rows; y++){
        for(int x=0; x<columns;x++){
              _tilesetSprite[t].setTexture(_tilesetTexture);
              //_tilesetSprite[t].setTextureRect(sf::IntRect(left,top,width,height));//ojo si hay dos imagenes
              _tilesetSprite[t].setTextureRect(sf::IntRect(x*_tileWidth,y*_tileHeigth,_tileWidth,_tileHeigth));
              t++;
        }
    }
   
    
    // Asigna sprites por capas a tilemapSprite   
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width;x++){
                int gid=_tilemap[l][y][x]-1;
                if(gid>=rows*columns){
                    std::cout<<gid<<std::endl; 
                    std::cout<<rows<<std::endl;
                    std::cout<<columns<<std::endl;
                    std::cout<<"Error"<<std::endl;
                }
                else if(gid>=0){   
                    // PENDIENTE
                    _tilemapSprite[l][y][x]=new sf::Sprite(_tilesetTexture,_tilesetSprite[gid].getTextureRect());
                    _tilemapSprite[l][y][x]->setPosition(x*_tileWidth,y*_tileHeigth);
                }
                else{
                    _tilemapSprite[l][y][x]=NULL;
                }
            }
        }
    }
      

    // INFO 
    std::cout<<std::endl;
    std::cout<<"Datos del mapa:"<<std::endl;
    std::cout<<"Heigth= "<<_height<<std::endl;
    std::cout<<"Width= "<<_width<<std::endl;
   std::cout<<"TileWidth= "<<_tileWidth<<std::endl;
   std::cout<<"TileHeigth= "<<_tileHeigth<<std::endl;
    std::cout<<"Numero de capas= "<<_numLayers<<std::endl;
    std::cout<<"Numero de tilesets= "<<numTileset<<std::endl;
    std::cout<<"Nombre del tileset= "<<filename<<std::endl;
    std::cout<<std::endl;
}

// Dibuja fondo y mapa por capas
void Map::Pintar(){
    
    for(int t=0; t<_numLayers; t++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[t][y][x]!=NULL){
                    _datos->ventana.draw(*(_tilemapSprite[t][y][x]));
                }
            }
        }
    }
    
}
}