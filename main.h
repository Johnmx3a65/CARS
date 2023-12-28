#ifndef CARS_MAIN_H
#define CARS_MAIN_H
#define CARS_TXT "cars.txt"

#include "Car.h"
#include <vector>

std::vector<Car> loadCars();

void showCars();

void storeCar(const Car&);

void start() {
    bool run = true;
    char option;
    std::string name;
    float price;
    Car car;
    std::vector<Car> cars;

    while (run) {
        std::cout << "1. Show cars\n"
                  << "2. Add a car\n"
                  << "3. Stop the program\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch (option) {
            case '1':
                showCars();
                break;
            case '2':
                std::cout << "Enter the car's name: ";
                std::cin >> name;
                std::cout << "Enter the car's price: ";
                std::cin >> price;
                car.setName(name);
                car.setPrice(price);
                storeCar(car);
                break;
            case '3':
                run = false;
                break;
            default: std::cout << "Invalid choice.\n";
        }
    }
}

std::vector<Car> loadCars() {
    std::vector<Car> cars;

    std::ifstream fin(CARS_TXT);
    if (!fin) {
        fin.open(CARS_TXT, std::fstream::app);
    }

    Car car;
    while (!fin.eof()) {
        fin >> car;
        cars.push_back(car);
    }

    fin.close();
    return cars;
}

void storeCar(const Car &car) noexcept(false) {
    std::ofstream fout(CARS_TXT, std::fstream::app);
    if (!fout) {
        std::cout << "Cannot open file" << std::endl;
        throw std::exception();
    }

    fout << std::endl;
    fout << car;
    fout.close();
}

void showCars() {
    std::vector<Car> cars = loadCars();
    for (int i = 0; i < cars.size(); ++i) {
        std::cout << cars.at(i) << std::endl;
    }
}

#endif //CARS_MAIN_H
