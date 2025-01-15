#include <iostream>

class carspecs {

    int length, width;
    int weight;

public:

    int& ref_length () {

        return length;
    }

    int& ref_width () {

        return width;
    }

    int& ref_weight () {

        return weight;
    }
};


class car {

    std::string name;
    int price;

    void change_price (int i) {

        price = i;
    }

public:

    car () = default;

    car (int price, const std::string& name) : name(name), price(price) {

        std::cout << "constructor called\n";
    }

    void change_name (const std::string& Name) {

        name = Name;
    }

    int get_price () {

        return price;
    }

    int& chage_price_ref () {

        return price;
    }

    std::string get_name () {

        return name;
    }

    void change_specs (carspecs& brand, int x, int y, int z) {

        brand.ref_length() = x;
        brand.ref_weight() = y;
        brand.ref_width() = z;

    }

};



int main () {

    car car1;

    carspecs spec1;

//    car1.change_name("golf r");
//
//    std::cout << car1.get_name();
//
//    car1.change_name("gti");
//
//    car1.chage_price_ref() = 30;

    car1.change_specs(spec1,10,5,4);

    std::cout << car1.get_name();
}