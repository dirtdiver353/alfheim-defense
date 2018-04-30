#pragma once

#include <sstream>
#include "Menu.h"
#include "InGame.h"
#include "Musica.hpp"
#include <iostream>
#include "MenuControles.h"
#include "MenuCreditos.h"

namespace Alfheim
{
   
       Menu::Menu(DatosJuegoRef datos) : _datos(datos)
       {
           
            if(!textFont.loadFromFile("resources/fonts/clacon.ttf")
            || !textFontTitle.loadFromFile("resources/fonts/Morgan TwentyNine.ttf")){
            // Error en carga de fuente de texto
            exit(0);
        
            }
    
    
    
            if (!_backgroundTexture.loadFromFile("resources/inicio2.jpg"))
            {
               // std::cout << "Error cargando la imagen fondo.png";
                exit(0);
            }    
            
            _background.setTexture(_backgroundTexture);
            _background.setScale(0.6,0.6);
    
    
            titleShadow.setFont(textFontTitle);
            //title.setStyle(sf::Text::);
            titleShadow.setColor(sf::Color::Black);
            titleShadow.setString("Alfheim Defense");
           // titleShadow.setScale(1.1, 1.1);
            titleShadow.setPosition(sf::Vector2f(640/2-168, 82));
    
            title.setFont(textFontTitle);
            //title.setStyle(sf::Text::);
            title.setColor(sf::Color::White);
            title.setString("Alfheim Defense");
           // title.setScale(1.1, 1.1);
            title.setPosition(sf::Vector2f(640/2-170, 80));


            options[0].setFont(textFont);
            options[0].setColor(sf::Color::White);
            options[0].setString("Jugar");
           // options[0].setScale(1.50, 1.50);
            options[0].setPosition(sf::Vector2f(640/2-35, 190));

            options[1].setFont(textFont);
            options[1].setColor(sf::Color::Yellow);
            options[1].setString("Ver controles");
            options[1].setPosition(sf::Vector2f(640/2-90, 210));

            options[2].setFont(textFont);
            options[2].setColor(sf::Color::Yellow);
            options[2].setString("Ver creditos");
            options[2].setPosition(sf::Vector2f(640/2-80, 230));
            
            options[3].setFont(textFont);
            options[3].setColor(sf::Color::Yellow);
            options[3].setString("Salir");
            options[3].setPosition(sf::Vector2f(640/2-40, 250));

            
            selectedItem = 0;

            std::string ruta("resources/Achilles_Strings.ogg");

            musica=new Musica(ruta);
            musica->setLoop(true);
            musica->Play();
       }
        
        void Menu::Init()
        {
            
        }
        
        void Menu::ManejarEventos()
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
                                            std::cout<< "play" << std::endl;
                                             _datos->state.AddEJ(JuegoStateRef(new InGame(_datos)),true);
       
                                            break; 
                                        case 1:
                                             _datos->state.AddEJ(JuegoStateRef(new MenuControles(_datos)),true);
       ;
                                            break;
                                        case 2:
                                             _datos->state.AddEJ(JuegoStateRef(new MenuCreditos(_datos)),true);
       ;
                                            break;  
                                        case 3:
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
        void Menu::Update(float dt)
        {
            
        }
        void Menu::Render(float dt)
        {
                       
            _datos->ventana.clear();
            
            _datos->ventana.draw(_background);
            _datos->ventana.draw(titleShadow);
            _datos->ventana.draw(title);

            for(int i = 0; i < MAX_NUM_ITEMS_INI; i++){
                _datos->ventana.draw(options[i]);
            }
            _datos->ventana.display();
    
            
        }
        

        void Menu::MoveUp(){

            if(selectedItem -1 >= 0){

                options[selectedItem].setColor(sf::Color::Yellow);
                selectedItem--;
                options[selectedItem].setColor(sf::Color::White);
            }
        }

        void Menu::MoveDown(){

            if(selectedItem +1 < MAX_NUM_ITEMS_INI){

                options[selectedItem].setColor(sf::Color::Yellow);
                selectedItem++;
                options[selectedItem].setColor(sf::Color::White);
            }
        }

        int Menu::GetSelectedItem(){
            return selectedItem;
        }

        
   
}