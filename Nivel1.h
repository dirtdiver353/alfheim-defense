/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel1.h
 * Author: joserra
 *
 * Created on 26 de abril de 2018, 20:00
 */
#include "Mapa.h"
class Nivel1 {
public:
    Nivel1();
    Nivel1(const Nivel1& orig);
    virtual ~Nivel1();
    void setMapa(const char * nombre);
    Mapa *getMapa();
private:
    Mapa *mapa; 
};
