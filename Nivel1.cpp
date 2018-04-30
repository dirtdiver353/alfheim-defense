/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel1.cpp
 * Author: joserra
 * 
 * Created on 26 de abril de 2018, 20:01
 */

#pragma once //singleton

#include "Nivel1.h"

Nivel1::Nivel1() {
}

Nivel1::Nivel1(const Nivel1& orig) {
}

Nivel1::~Nivel1() {
}

void Nivel1::setMapa(const char* nombre){
    
    mapa = new Mapa(nombre);
    mapa->leerMapa();
}

Mapa *Nivel1::getMapa(){
    return this->mapa;
}