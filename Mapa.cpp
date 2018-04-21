#define TIXML_USE_STL

#include "Mapa.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

// CONSTRUCTORES
Mapa::Mapa() {  
}

Mapa::Mapa(const Mapa& orig) {
}

// BORRAR MAPA
Mapa::~Mapa() {
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            delete[] _tilemap[l][y];
        }
        delete[] _tilemap[l];
    }
    delete[] _tilemap;
}

// LEER MAPA
void Mapa::leerMapa(){
    
    // Cargo archivo de mapa
    TiXmlDocument doc;
    doc.LoadFile("TorreZostar.tmx");    
    
    // Guarda atributos de mapa tmx
    TiXmlElement* map = doc.FirstChildElement("map");
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
    string filename;
    imgTileset = map->FirstChildElement("tileset");
   
    while(imgTileset){
        filename=(string)imgTileset->FirstChildElement("image")->Attribute("source");
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
    string *name=new string[_numLayers];
    int j=0;
    int l=0;
    // Lee tiles de xml
    layer = map->FirstChildElement("layer");
    while(layer){
        data= layer->FirstChildElement("data")->FirstChildElement("tile");
        name[j]= (string)layer->Attribute("name");
        
        
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
                    cout<<gid<<endl;
                    cout<<rows<<endl;
                    cout<<columns<<endl;
                    cout<<"Error"<<endl;
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
    cout<<endl;
    cout<<"Datos del mapa:"<<endl;
    cout<<"Heigth= "<<_height<<endl;
    cout<<"Width= "<<_width<<endl;
    cout<<"TileWidth= "<<_tileWidth<<endl;
    cout<<"TileHeigth= "<<_tileHeigth<<endl;
    cout<<"Numero de capas= "<<_numLayers<<endl;
    cout<<"Numero de tilesets= "<<numTileset<<endl;
    cout<<"Nombre del tileset= "<<filename<<endl;
    cout<<endl;
}

// Dibuja fondo y mapa por capas
void Mapa::dibujarMapa(sf::RenderWindow& window){
    
    for(int t=0; t<_numLayers; t++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[t][y][x]!=NULL){
                    window.draw(*(_tilemapSprite[t][y][x]));
                }
            }
        }
    }
    
}