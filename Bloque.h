#ifndef BLOQUE_H
#define BLOQUE_H
#include <SFML/Graphics.hpp>



    class Bloque
    {
    public:
        Bloque();
        
        void Init(int x, int y);
        void Pintar(sf::RenderWindow &window, float pt);

        void Update(float dt);
        void Girar(int dl, sf::Sprite personaje);
        
        
        sf::Sprite getBloque();

    private:
        
        sf::Texture _bloqueTexture;
        sf::Sprite _bloque;
        sf::Clock clock;
        sf::Clock _updateClock;
      
        
    };
#endif	/* CARGAR_H */