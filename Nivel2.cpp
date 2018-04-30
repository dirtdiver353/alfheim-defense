/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel2.cpp
 * Author: joserra
 * 
 * Created on 26 de abril de 2018, 20:01
 */

#pragma once //singleton

#include "Nivel2.h"

Nivel2::Nivel2() {
}

Nivel2::Nivel2(const Nivel2& orig) {
}

Nivel2::~Nivel2() {
}

void Nivel2::setMapa(const char* nombre){
    
    mapa = new Mapa(nombre);
    mapa->leerMapa();
}

Mapa *Nivel2::getMapa(){
    return this->mapa;
}