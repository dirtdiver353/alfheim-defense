#include <iostream>
#include <SFML/Graphics.hpp>

#define kVel 4

int main()
{
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

    //Cargo la imagen donde reside la textura del sprite 
    sf::Texture tex;
    if (!tex.loadFromFile("resources/mago.png"))
    {
        std::cerr << "Error cargando la imagen mago.png";
        exit(0);
    }    
    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite sprite(tex);    
    //Le pongo el centroide donde corresponde
    sprite.setOrigin(64/2,64/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*64, 0*64, 64, 64));
    // Lo dispongo en su posicion en la pantalla
    sprite.setPosition(320, 240);
    
    int xd = 0, yd = 0, xu = 0, ys = 0;
    int yu = 4, xs = 4;
    
    sf::Clock clock;
    
    //Bucle del juego
    while (window.isOpen())
    {
        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            switch(event.type){
                
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                    
                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {
                        
                        //Mapeo del cursor
                        case sf::Keyboard::Right:
                            if(clock.getElapsedTime().asSeconds() > 0.07f){
                                if(xs < 8) xs++;
                                if(ys < 4) ys++;
                                if(xs > 7) xs = 4;
                                if(ys > 3) ys = 0;
                                clock.restart();
                            }
                            sprite.setTextureRect(sf::IntRect(xs*64, ys*64, 64, 64));
                            sprite.setScale(-1,1);
                            sprite.move(kVel,0);
                        break;

                        case sf::Keyboard::Left:
                            if(clock.getElapsedTime().asSeconds() > 0.07f){
                                if(xs < 8) xs++;
                                if(ys < 4) ys++;
                                if(xs > 7) xs = 4;
                                if(ys > 3) ys = 0;
                                clock.restart();
                            }
                            sprite.setTextureRect(sf::IntRect(xs*64, ys*64, 64, 64));
                            sprite.setScale(1,1);
                            sprite.move(-kVel,0); 
                        break;
                        
                        case sf::Keyboard::Up:
                            if(clock.getElapsedTime().asSeconds() > 0.07f){
                                if(xu < 4) xu++;
                                if(yu < 8) yu++;
                                if(xu > 3) xu = 0;
                                if(yu > 7) yu = 4;
                                clock.restart();
                            }
                            sprite.setTextureRect(sf::IntRect(xu*64, yu*64, 64, 64));
                            sprite.move(0,-kVel); 
                        break;
                        
                        case sf::Keyboard::Down:
                            if(clock.getElapsedTime().asSeconds() > 0.07f){
                                if(xd < 4) xd++;
                                if(yd < 4) yd++; 
                                if(xd > 3) xd = 0;
                                if(yd > 3) yd = 0;
                                clock.restart();
                            }
                            sprite.setTextureRect(sf::IntRect(xd*64, yd*64, 64, 64));
                            sprite.move(0,kVel); 
                        break;
                        
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;
                        
                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.key.code << std::endl;
                        break;
                              
                    }

            }
            
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}