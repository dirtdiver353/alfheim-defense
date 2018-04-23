#pragma once

#include <sstream>

#include "InGame.h"
#include "Musica.hpp"
#include <iostream>

#include "MenuMuerte.h"
namespace Alfheim
{
    MenuMuerte::MenuMuerte(DatosJuegoRef datos) : _datos(datos) 
    {
        if(!textFont.loadFromFile("resources/fonts/clacon.ttf")
            || !textFontTitle.loadFromFile("resources/fonts/Morgan TwentyNine.ttf")){
            // Error en carga de fuente de texto
            exit(0);        
        }
    
    
    
        if (!_backgroundTexture.loadFromFile("resources/muerte.jpg"))
        {
           // std::cout << "Error cargando la imagen fondo.png";
            exit(0);
        }    
            
    _background.setTexture(_backgroundTexture);
    _background.setScale(0.5,0.6);
    
    
    titleShadow.setFont(textFontTitle);
    //title.setStyle(sf::Text::);
    titleShadow.setColor(sf::Color::Black);
    titleShadow.setString("Has muerto");
   // titleShadow.setScale(1.1, 1.1);
    titleShadow.setPosition(sf::Vector2f(640/2-118, 58));
    
    title.setFont(textFontTitle);
    //title.setStyle(sf::Text::);
    title.setColor(sf::Color::White);
    title.setString("Has muerto");
   // title.setScale(1.1, 1.1);
    title.setPosition(sf::Vector2f(640/2-120, 60));
    
            
    options[0].setFont(textFont);
    options[0].setColor(sf::Color::White);
    options[0].setString("Volver a jugar nivel");
   // options[0].setScale(1.50, 1.50);
    options[0].setPosition(sf::Vector2f(640/2-120, 480/2+70));
    
    options[1].setFont(textFont);
    options[1].setColor(sf::Color::Yellow);
    options[1].setString("Salir");
    options[1].setPosition(sf::Vector2f(640/2-30, 480/2 + 110));
    
    selectedItem = 0;
    
    std::string ruta("resources/Achilles_Strings.ogg");

    Musica *musica=new Musica(ruta);
    musica->setLoop(true);
    musica->Play();


    }

    void MenuMuerte::Init()
    {

    }
        
        void MenuMuerte::ManejarEventos()
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
                                            std::cout<< "vuelve a jugar nivel" << std::endl;
                                             _datos->state.AddEJ(JuegoStateRef(new InGame(_datos)),true);
       
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
        
    void MenuMuerte::Update(float dt)
    {

    }
    
    void MenuMuerte::Render(float dt)
    {

        _datos->ventana.clear();

        _datos->ventana.draw(_background);
        _datos->ventana.draw(titleShadow);
        _datos->ventana.draw(title);

        for(int i = 0; i < MAX_NUM_ITEMS; i++){
            _datos->ventana.draw(options[i]);
        }
        _datos->ventana.display();


    }
        

    void MenuMuerte::MoveUp(){

        if(selectedItem -1 >= 0){

            options[selectedItem].setColor(sf::Color::Yellow);
            selectedItem--;
            options[selectedItem].setColor(sf::Color::White);
        }
    }

    void MenuMuerte::MoveDown(){

        if(selectedItem +1 < MAX_NUM_ITEMS){

            options[selectedItem].setColor(sf::Color::Yellow);
            selectedItem++;
            options[selectedItem].setColor(sf::Color::White);
        }
    }

    int MenuMuerte::GetSelectedItem(){
        return selectedItem;
    }



}