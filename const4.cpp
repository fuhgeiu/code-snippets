#include <iostream>
#include "exceptions.hpp"

class my_class {

    int my_int;
    char m_data[9] = {'1','2','3','4','5','6','7','8','9'};

public:

    my_class () = default;

    my_class (int v) : my_int(v) {}

    const int& return_ref() const {return my_int;}

    void swap (size_t spot1, size_t spot2) {

        char temp = m_data[spot1];
        m_data[spot1] = m_data[spot2];
        m_data[spot2] = temp;
    }

    void print () const {

        for (size_t i = 0; i < 8; i++) std::cout << m_data[i];
    }

    int return_nonref () {return my_int;}
};


class data1 {

    const my_class* class0 = nullptr;
    const my_class* class1 = nullptr;

    const my_class* current = nullptr;

public:

    data1 () = default;

    data1 (const my_class* class1) : class0(class1) {}

    data1 (const my_class* Class, const my_class* class1) : class1(Class), class0(class1) {}

    data1 (const my_class* Classs, const my_class* Class, const my_class* class1)

        : class0(Class), class1(class1), current(Classs) {

        if (current == nullptr) std::cout << "nullptr";

    }

    void print () const {

        current->print();
    }

    void switch_player () {

        try {
            if (class0 == nullptr) {throw c_exception::runtime::acess_nullptr("class0 is nullptr");}
        }
        catch (const c_exception::runtime::acess_nullptr& e) {std::cout << "error :" << e.what() << std::endl;}

        try {
            if (class1 == nullptr) { throw c_exception::runtime::acess_nullptr("class1 is nullptr"); }
        }
        catch (const c_exception::runtime::acess_nullptr& e) {std::cout << "error :" << e.what() << std::endl;}

        try {
            if (current == nullptr) { throw c_exception::runtime::acess_nullptr("class0 is nullptr "); }
        }
        catch (const c_exception::runtime::acess_nullptr& e) {std::cout << "error :" << e.what() << std::endl;}

        if (current == class0) current = class1;

        if (current == class1) current = class0;
    }

    const int& retrun_ref_data () {return current->return_ref();}
};


int main () {

    auto *class1 = new const my_class(4);

    auto*class2 = new const my_class(9);

    auto *data = new data1(class1,class1,class2);

    auto *data2 = new data1();

    auto *data5 = new data1();

    data5->switch_player();                     // catches exceptions

    data->switch_player();



//    data2->switch_player();
//
//    std::cout << data->retrun_ref_data();
//
//    data->switch_player();
//
//    data->print();
//
//    std::cout << data->retrun_ref_data();
//
//    my_class class5;
//
//    class5.print();
//
//    std::cout << std::endl;
//
//    class5.swap(2,6);
//
//    class5.print();


}