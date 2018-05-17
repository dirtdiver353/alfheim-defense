

#pragma once

#include <sstream>

#include "InGame.h"
#include "Musica.hpp"
#include <iostream>

#include "MenuCreditos.h"
#include "Menu.h"
#include "Personaje.h"

namespace Alfheim
{
    MenuCreditos::MenuCreditos(DatosJuegoRef datos) : _datos(datos) 
    {
        if(!textFont.loadFromFile("resources/fonts/clacon.ttf")
            || !textFontTitle.loadFromFile("resources/fonts/Morgan TwentyNine.ttf")){
        // Error en carga de fuente de texto
        exit(0);
        
    }
    
    
    
    if (!_backgroundTexture.loadFromFile("resources/creditos.jpg"))
    {
       // std::cout << "Error cargando la imagen fondo.png";
        exit(0);
    } 
        
    
            
    _background.setTexture(_backgroundTexture);
    _background.setScale(0.6,0.6);
    
    
    titleShadow.setFont(textFontTitle);
    //title.setStyle(sf::Text::);
    titleShadow.setColor(sf::Color::Black);
    titleShadow.setString("Creditos");
   // titleShadow.setScale(1.1, 1.1);
    titleShadow.setPosition(sf::Vector2f(640/2-98, 108));
    
    title.setFont(textFontTitle);
    //title.setStyle(sf::Text::);
    title.setColor(sf::Color::White);
    title.setString("Creditos");
   // title.setScale(1.1, 1.1);
    title.setPosition(sf::Vector2f(640/2-100, 110));
    
    
    
    c1.setFont(textFont);
    c2.setFont(textFont);
    c3.setFont(textFont);
    
    c1.setColor(sf::Color::White);
    c2.setColor(sf::Color::White);
    c3.setColor(sf::Color::White);
    
    c1.setString("Realizado por");
    c2.setString("Jose Ramon Barea Cecilia");
    c3.setString("Victoria Maria Hodelin Taranova");
    
    c1.setPosition(sf::Vector2f(640/2-80, 190));
    c2.setPosition(sf::Vector2f(640/2-140, 210));
    c3.setPosition(sf::Vector2f(640/2-190, 230));
    
    
            
    options[0].setFont(textFont);
    options[0].setColor(sf::Color::White);
    options[0].setString("Volver a menu principal");
   // options[0].setScale(1.50, 1.50);
    options[0].setPosition(sf::Vector2f(640/2-140, 480/2+110));
    
    options[1].setFont(textFont);
    options[1].setColor(sf::Color::Yellow);
    options[1].setString("Salir");
    options[1].setPosition(sf::Vector2f(640/2-30, 480/2 + 140));
    
    selectedItem = 0;
    
    
    
    std::string ruta("resources/Achilles_Strings.ogg");

    Musica *musica=new Musica(ruta);
    musica->setLoop(true);
    musica->Play();


    }

    void MenuCreditos::Init()
    {

    }
        
        void MenuCreditos::ManejarEventos()
        {
           

            sf::Event event;
            while(_datos->ventana.pollEvent(event))
            {
                
            switch(event.type){
                
                case sf::Event::Closed:
                    _datos->ventana.close();
                break;

                        case sf::Event::KeyReleased:

                            switch(event.key.code){

                                case sf::Keyboard::Escape:
                                    _datos->ventana.close();
                                    break;

                                case sf::Keyboard::Up:
                                   this->MoveUp();
                                    break;

                                case sf::Keyboard::Down:
                                    this->MoveDown();
                                    break;

                                case sf::Keyboard::Return:
                                    switch(this->GetSelectedItem()){
                                        case 0:
                                            std::cout<< "vuelve menu principal" << std::endl;
                                             _datos->state.AddEJ(JuegoStateRef(new Menu(_datos)),true);
       
                                            break; 
                                        case 1:
                                            _datos->ventana.close();
                                            std::cout<< "exit" << std::endl;
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
            }     
        }
        
    void MenuCreditos::Update(float dt)
    {

    }
    
    void MenuCreditos::Render(float pt)
    {

        _datos->ventana.clear();

        _datos->ventana.draw(_background);
        _datos->ventana.draw(titleShadow);
        _datos->ventana.draw(title);
        _datos->ventana.draw(c1);
        _datos->ventana.draw(c2);
        _datos->ventana.draw(c3);
        

        for(int i = 0; i < MAX_NUM_ITEMS; i++){
            _datos->ventana.draw(options[i]);
        }
        _datos->ventana.display();


    }
        

    void MenuCreditos::MoveUp(){

        if(selectedItem -1 >= 0){

            options[selectedItem].setColor(sf::Color::Yellow);
            selectedItem--;
            options[selectedItem].setColor(sf::Color::White);
        }
    }

    void MenuCreditos::MoveDown(){

        if(selectedItem +1 < MAX_NUM_ITEMS){

            options[selectedItem].setColor(sf::Color::Yellow);
            selectedItem++;
            options[selectedItem].setColor(sf::Color::White);
        }
    }

    int MenuCreditos::GetSelectedItem(){
        return selectedItem;
    }



}
