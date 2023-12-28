#include "Car.h"

Car::Car() {
    this->name = "";
    this->price = 0;
}

Car::Car(const char* name, const float price) {
    this->name = name;
    this->price = price;
}

void Car::setName(const std::string &name) { this->name = name; }

void Car::setPrice(const float price) { this->price = price; }

std::ostream& operator << (std::ostream &os, const Car &car) {
    os << "Car { name: " << car.name << "; price: " << car.price << "; }";
    return os;
}

std::ofstream& operator << (std::ofstream &os, const Car &car) {
    os << car.name << " " << car.price;
    return os;
}

std::istream& operator >> (std::istream &is, Car &car) {
    is >> car.name >> car.price;
    return is;
}
