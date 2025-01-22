#include <iostream>

class car {

    std::string name;
    std::string color;
    int weight;
    double price;

public:

    car () = default;

    car (std::string name,std::string color, int weight, double price) : name(name), color(color), weight(weight), price (price){

        std::cout << "direct initilizer called\n";
    }

    car (const std::string &Name, const std::string &Color, int Weight, double Price, bool direct) {

        name = Name;
        color = Color;
        weight = Weight;
        price = Price;

        std::cout << "constructor called\n";
    }

    std::string& ref_name() {return name;}

    std::string ref_name_const_return() const {return name;}

    std::string& ref_color() {return color;}

    int const_weigth() const {return weight;}

};

// whats differnt abt these 2 functions
void print_weight (car Car) {

    std::cout << "weight of the car is " << Car.const_weigth() << std::endl;
}

void Print_weight (const car &Car) {

    std::cout << "weight of the car is " << Car.const_weigth() << std::endl;
}


void ref_name (const car &Car) {

    std::cout << Car.ref_name_const_return() << std::endl;
}



int main () {

    car ford_pinto;

    // will these 2 use differnt constructros? 
    car ford ("explorer","cop car white and black",500000,40000,true);
    car kia_soul("kia_soul","idk_ugly_af",300,5000);

    ref_name(kia_soul);
    Print_weight(kia_soul);


    // although this will complile, do not do this
    ref_name(ford_pinto);
    Print_weight(ford_pinto);
}