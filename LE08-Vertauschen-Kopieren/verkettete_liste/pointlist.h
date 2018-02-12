#pragma once
#include <memory>
//#include "pointlistnode.h"
#include "/home/beer/workspace/progII/task06/klassen/point.h"


//Vorwärtsdeklaration der Hilfsklasse
    //zur integration in PointList.cc um für User zu verstecken
class PointListNode;


//RoT = Rule of Three

class PointList
{
    size_t sizeOf = 0;
    std::unique_ptr<PointListNode> root;                    //<- lösung
public:
    PointList();                                  //wegen vorwärtsdeklaration
    ~PointList();                                 //wegen vorwärtsdeklaration
    PointList(PointList&& other);                //RoT -  von delete zu swap() R-Value
    PointList& operator=(PointList&& other);     //RoT -  von delete zu swap() "
    PointList& operator+=(const Point& point);              //-> RoT mit unique ist der ganze umständliche mist der rule of Three nicht mehr nötig
    //Zusätzliche Funktionen:
    size_t size() const;
    const Point& first()const;
    void deleteFirst();

    //tauschen - elementfunktion
    void swap(PointList& b);
};

//Freie Funktionen

  //tauschen -frei
void swap(PointList& a, PointList& b);



