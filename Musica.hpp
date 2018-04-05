/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Musica.hpp
 * Author: vik
 *
 * Created on 26 de marzo de 2018, 18:54
 */

#ifndef MUSICA_HPP
#define MUSICA_HPP

#include<SFML/Audio.hpp>

class Musica {
public:
    Musica(std::string s);
    void Play();
    void setLoop(bool b);
    void Stop();
private:
    sf::Music musica;
};

#endif /* MUSICA_HPP */

