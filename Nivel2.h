/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel2.h
 * Author: joserra
 *
 * Created on 26 de abril de 2018, 20:00
 */
#include "Mapa.h"
class Nivel2 {
public:
    Nivel2();
    Nivel2(const Nivel2& orig);
    virtual ~Nivel2();
    void setMapa(const char * nombre);
    Mapa *getMapa();
private:
    Mapa *mapa; 
};
