#pragma once

#include <string>
#include <iosfwd>

class Punkt
{

    friend std::ostream& operator<<(std::ostream& outputStream, const Punkt& p);

    int mx,my;
    std::string color;
    const int serienNr;
    static int zaehler;

public:
    //Punkt();
    Punkt(int x = 0, int y = 0, std::string color = "black");
    Punkt(const Punkt& other);
    int getX() const;
    int getY() const;
    int getSerie() const;

    Punkt& setX(const int& x);
    Punkt& operator=(const Punkt& p);
};


std::ostream& operator<<(std::ostream& outputStream, const Punkt& p);

