#ifndef CARS_CAR_H
#define CARS_CAR_H

#include <iostream>
#include <fstream>
#include <vector>

class Car {
private:
    std::string name;
    float price;
public:
    Car();

    Car(const char*, float);

    void setName(const std::string&);

    void setPrice(float);

    friend std::ostream& operator << (std::ostream&, const Car&);

    friend std::ofstream& operator << (std::ofstream&, const Car&);

    friend std::istream& operator >> (std::istream&, Car&);
};


#endif //CARS_CAR_H
