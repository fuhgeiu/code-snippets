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

    // constructor which instantiates a empty object first, this-> (similar to the .name, but t"his" refers to object within function)
    car (const std::string &name, const std::string &color, int weight, double price,bool direct) {

        // why is this not good?
//        name = name;
//        color = color;

        // what does this prove? and why can we do this, why might this be a good idea
        this->name = name;
        this->color = color;
        this->weight = weight;
        this->price = price;

        std::cout << "constructor called\n";
    }

    std::string& ref_name() {return name;}

    //std::string& ref_name_const() const {return name;}                why does this not work
    const std::string& ref_name_const() const {return name;}
    std::string ref_name_const_return() const {return name;}

    std::string& ref_color() {return color;}

    const int const_weigth() const {return weight;}

};

// this will create copy
void print_weight (car Car) {

    std::cout << "weight of the car is " << Car.const_weigth() << std::endl;
}

// this will use a refernce
void Print_weight (const car &Car) {

    std::cout << "weight of the car is " << Car.const_weigth() << std::endl;
}

// why does this not work
//void ref_name (const car &Car) {
//
//    std::cout << "name of car is " << Car.ref_name(Car);
//}

// or this
//void ref_name (const car Car) {
//
//    std::cout << "name of car is" <<  Car.ref_name(Car);
//}

// but this works?
void ref_name (const car &Car) {

    std::cout << Car.ref_name_const_return() << std::endl;
}



int main () {

    car ford_pinto;

    car kia_soul("kia_soul","idk_ugly_af",300,5000);

    car chrysler("pt cruiser","diarea_brown",400000,1);

    ref_name(kia_soul);
    Print_weight(kia_soul);

    ref_name(chrysler);
    Print_weight(chrysler);

    ref_name(ford_pinto);
    Print_weight(ford_pinto);

    // const version, i can do this why?, what if i dont use an direct intilizer
    const car vw_golf("gti","white",3000,31000);




}