#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include "../sequence.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <chrono>

template<typename T>
class iComp{
public:
    virtual bool cmp(const T &, const T&) = 0;
};


template<typename T>
class DefaultComp : public iComp<T>{
public:
    bool cmp(const T & a, const T& b){
        return a > b;
    }
};


template<typename T>
class iVSort{
public:
    virtual void sort(Sequence<T> &, int, int, iComp<T> &, int delay, std::vector<sf::RectangleShape> & visarr, sf::RenderWindow & currw) = 0;
};



template<typename T>
class VInsertSort : public iVSort<T>{
public:
    void sort(Sequence<T> & data, int start, int end, iComp<T> & comp, int delay, std::vector<sf::RectangleShape> & visarr, sf::RenderWindow & currw){
        sf::Event event;
        while (currw.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                currw.close();
        }
        currw.clear(sf::Color(255,200,200));
        for(int i = 0; i < visarr.size(); i++){
            currw.draw(visarr[i]);
        }
        currw.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        double wp = visarr[1].getPosition().x - visarr[0].getPosition().x;

        for(int i = start + 1; i < end + 1; i++){
            T key = data.Get(i);
            sf::RectangleShape viskey;
            //viskey = visarr[i];
            viskey.setSize(visarr[i].getSize());
            viskey.setPosition(visarr[i].getPosition());
            viskey.setFillColor(visarr[i].getFillColor());

            sf::Color passcolor = visarr[i].getFillColor();
            viskey.setFillColor(sf::Color::Black);
            int j = i - 1;
            for(; j >= start && comp.cmp(data.Get(j), key); j--){
                    //mass[j+1] = mass[j];
                    
                    data.Set(j + 1 ,data.Get(j));
                    //visarr[j + 1] = visarr[j];
                    visarr[j + 1].setSize(visarr[j].getSize());
                    visarr[j + 1].setPosition(visarr[j + 1].getPosition().x, visarr[j].getPosition().y);
                    visarr[j + 1].setFillColor(visarr[j].getFillColor());
                    
                    sf::Event event;
                    while (currw.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            currw.close();
                    }

                    currw.clear(sf::Color(255,200,200));
                    for(int i = 0; i < visarr.size(); i++){
                        currw.draw(visarr[i]);
                    }
                    currw.draw(viskey);
                    currw.display();
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            }
            viskey.setFillColor(passcolor);
            if(j < start){
                data.Set(start, key);
                //visarr[start] = viskey;
                visarr[start].setSize(viskey.getSize());
                visarr[start].setPosition(visarr[start].getPosition().x, viskey.getPosition().y);
                visarr[start].setFillColor(viskey.getFillColor());
            }
            //mass[j] = key;
            if(j == i - 1)
                continue;

            data.Set(j + 1, key);
            //visarr[j + 1] = viskey;
            visarr[j + 1].setSize(viskey.getSize());
            visarr[j + 1].setPosition(visarr[j + 1].getPosition().x, viskey.getPosition().y);
            visarr[j + 1].setFillColor(viskey.getFillColor());

            currw.clear(sf::Color(255,200,200));
            for(int i = 0; i < visarr.size(); i++){
                currw.draw(visarr[i]);
            }
            currw.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }
};

/*

template<typename T>
class VCocktailSort : public iVSort<T>{
public:
    void sort(Sequence<T> & data,int start, int end ,iComp<T> & comp, int delay, std::vector<sf::RectangleShape> & visarr, sf::RenderWindow & currw){
        int right = end;
        int left = start;
        int contr = end;
        do{
            for(int i = right; i > left; i--){
                if(comp.cmp(data.Get(i - 1), data.Get(i))){
                    T tmp = data.Get(i);
                    data.Set(i, data.Get(i - 1));
                    data.Set(i - 1, tmp);
                    contr = i;
                }
            }
            left = contr;
            for(int j = left; j < right; j++){
                if(comp.cmp(data.Get(j), data.Get(j + 1))){
                    T tmp = data.Get(j);
                    data.Set(j, data.Get(j + 1));
                    data.Set(j + 1, tmp);
                    contr = j;
                }
            }
            right = contr;
        }while(left < right);
    }
};

*/
/*

template<typename T>
class VMergeSort : public iVSort<T>{
public:
    void sort(Sequence<T> & data,int start, int end ,iComp<T> & comp, int delay, std::vector<sf::RectangleShape> & visarr, sf::RenderWindow & currw){
        T * temp = new T[data.GetLenght()];
        mergesortGeneral(data, start, end , comp, temp);
        delete[] temp;
    }
private:
    void mergesortGeneral(Sequence<T> & data,int start, int end ,iComp<T> & comp, T * tmp){
        if(end - start == 0){
            return;
        }
        int middle = (end + start)/ 2 ;
        mergesortGeneral(data, start, middle, comp, tmp);
        mergesortGeneral(data, middle + 1, end, comp, tmp);
        int i = start;
        int j = middle + 1;
        int k = 0;
        for(k = 0; i<= middle || j <= end; k++){
            if(j <= end && i<= middle && comp.cmp(data.Get(i), data.Get(j)) || i > middle){
                tmp[k] = data.Get(j);
                j++;
            }
            else if(i <= middle && j <= end && !comp.cmp(data.Get(i), data.Get(j)) || j > end){
                tmp[k] = data.Get(i);
                i++;
            } 
        }

        for(k--; k >=0; k--){
            data.Set(start + k, tmp[k]);
        }
    }
};
*/

/*

template<typename T>
class VBubbleSort : public iVSort<T>{
public:
    void sort(Sequence<T> & data,int start, int end ,iComp<T> & comp, int delay, std::vector<sf::RectangleShape> & visarr, sf::RenderWindow & currw){
        for(int i = start; i < end + 1; i++){
        for(int j = end; j > i; j--){
            if(comp.cmp(data.Get(j), data.Get(j - 1) ) ){
                T tmp = data.Get(j);
                data.Set(j, data.Get(j - 1) );
                data.Set(j - 1, tmp);
            }
        }
    }
    }
};

*/



template<typename T>
class VQuickSort : public iVSort<T>{
public:
    void sort(Sequence<T> & data, int start, int end, iComp<T> & comp, int delay, std::vector<sf::RectangleShape> & visarr, sf::RenderWindow & currw){
        QuickSortGeneral(data, start, end, comp, delay, visarr, currw);
    }
private:
    void QuickSortGeneral(Sequence<T> & data, int start, int end, iComp<T> & comp, int delay,  std::vector<sf::RectangleShape> & visarr, sf::RenderWindow & currw){
        if((end - start) == 1){
            if(comp.cmp(data.Get(start), data.Get(end)) ){
                
                T tmp = data.Get(start);
                data.Set(start, data.Get(end));
                data.Set(end, tmp);

                sf::RectangleShape temp;
                
                temp.setSize(visarr[start].getSize());
                temp.setPosition(visarr[start].getPosition());
                temp.setFillColor(visarr[start].getFillColor());

                visarr[start].setSize(visarr[end].getSize());
                visarr[start].setFillColor(visarr[end].getFillColor());
                visarr[start].setPosition(visarr[start].getPosition().x, visarr[end].getPosition().y);

                visarr[end].setSize(temp.getSize());
                visarr[end].setFillColor(temp.getFillColor());
                visarr[end].setPosition(visarr[end].getPosition().x,temp.getPosition().y);

                currw.clear(sf::Color(255,200,200));
                for(int i = 0; i < visarr.size(); i++){
                    currw.draw(visarr[i]);
                }
                currw.display();
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            }
            return;
        }

        int right = end;
        int left = start;
        T key = data.Get((start + end) / 2);

        sf::RectangleShape viskey;
        viskey.setSize(visarr[(start + end)/2].getSize());
        viskey.setPosition(visarr[(start + end)/2].getPosition());
        viskey.setFillColor(sf::Color::Black);

        double wp = visarr[1].getPosition().x - visarr[0].getPosition().x;

        sf::VertexArray lines(sf::Lines,6);
        lines[0].position = sf::Vector2f(visarr[start].getPosition().x, 700);
        lines[1].position = sf::Vector2f(visarr[start].getPosition().x, 100);
        lines[2].position = sf::Vector2f(visarr[end].getPosition().x + wp, 700);
        lines[3].position = sf::Vector2f(visarr[end].getPosition().x + wp, 100);
        lines[4].position = sf::Vector2f(visarr[start].getPosition().x, viskey.getPosition().y);
        lines[5].position = sf::Vector2f(visarr[end].getPosition().x + wp, viskey.getPosition().y);

        while(right > left){
            while(comp.cmp(data.Get(right), key) ) {
                right--;
            }
            while(comp.cmp(key, data.Get(left)) ) {
                left++;
            }
            if(right >= left){
                T tmp = data.Get(left);
                data.Set(left, data.Get(right));
                data.Set(right, tmp);

                sf::RectangleShape temp;
                
                temp.setSize(visarr[left].getSize());
                temp.setPosition(visarr[left].getPosition());
                temp.setFillColor(visarr[left].getFillColor());

                visarr[left].setSize(visarr[right].getSize());
                visarr[left].setFillColor(visarr[right].getFillColor());
                visarr[left].setPosition(visarr[left].getPosition().x,visarr[right].getPosition().y);

                visarr[right].setSize(temp.getSize());
                visarr[right].setFillColor(temp.getFillColor());
                visarr[right].setPosition(visarr[right].getPosition().x,temp.getPosition().y);

                sf::Event event;
                while (currw.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        currw.close();
                }

                currw.clear(sf::Color(255,200,200));
                for(int i = 0; i < visarr.size(); i++){
                    currw.draw(visarr[i]);
                }
                currw.draw(viskey);
                currw.draw(lines);
                currw.display();
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));

                right--;
                left++;
            }
        }

        if(left < end){
            QuickSortGeneral(data, left, end, comp, delay,   visarr,  currw);
        }
        if(start < right){
            QuickSortGeneral(data, start, right, comp,  delay, visarr, currw);
        }
    }

};



#endif