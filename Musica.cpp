/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Musica.cpp
 * Author: vik
 * 
 * Created on 26 de marzo de 2018, 18:54
 */
#include <iostream>
#include "Musica.hpp"

Musica::Musica(std::string s) {
    if(!musica.openFromFile(s)){
        std::cerr << "Error al abrir la musica" << std::endl;
        exit(-1);
    }
}

void Musica::Play(){
    musica.play();
}

void Musica::setLoop(bool b){
    musica.setLoop(b);
}

void Musica::Stop(){
    musica.stop();
}
