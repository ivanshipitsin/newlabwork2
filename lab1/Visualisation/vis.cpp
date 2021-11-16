#include <iostream>
#include "../ArraySequence.hpp"
#include "vissort.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <ctime>

int main(){
    srand(time(nullptr));

    DefaultComp<int> cmp;
    VInsertSort<int> isortg;
    VQuickSort<int> qsortg;
    int count = 20;
    int d = count;
    int p = 8;
    int w = (600 - (count - 1) * p)/count;
    int h = 600 / d;
    ArraySequence<int> mass(count);
    std::vector<sf::RectangleShape> visarr;
    for(int i = 0 ;i < count; i++){
        mass.Set(i, rand() % d);
        visarr.push_back(sf::RectangleShape (sf::Vector2f( w , h * (mass.Get(i)) + 2) )  );
        visarr[i].setPosition(sf::Vector2f(100 + (w + p)*i, 700 - h * (mass.Get(i)) ) );
        visarr[i].setFillColor(sf::Color(255 - 50 * (i % 4), 255 - 60*(i % 8), 255 - 40 * (i % 3) ) );
    }
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    window.setActive(false);

    qsortg.sort(mass,0,count - 1, cmp, 700, visarr, window);
    
    //sf::Thread thread(std::bind(& VInsertSort<int>::sort, mass, 0, count - 1, cmp, 600, visarr, window));
    //thread.launch();

    /*while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255,200,200));
        window.display();
    }*/
    for(int i = 0; i < count; i++){
        std::cout << mass.Get(i) << "\t";
    }
    return 0;
}