#include <iostream>

// const with classes


namespace my_class {

    class my_class {

        int my_var;

    public:

        my_class() = default;                                  // default constructor

        my_class(int var) : my_var(var) { std::cout << "constructor called\n" << std::endl; }      // direct initilizer

        ~my_class() {
            std::cout << "destructor called " << "obj with atribute" << my_var << std::endl;
        }

        int &change_my_var() {                                 // returns a refernce to my_var

            return my_var;
        }

        void acessor(int var) {    // to change atribute by passing in and function making a copy to asign

            this->my_var = var;
        }

        const int get_my_var() const { return my_var; }  // const method to return my_var

        const int &const_ref() const {     //returns a const refernce to my_var

            return my_var;
        }

    };

}

namespace data {

    class data {

        const my_class::my_class* class1 = nullptr;               // pointer to a const object
        my_class::my_class* class2 = nullptr;

    public:

        data () = default;

        data (const my_class::my_class* class1) : class1(class1) {std::cout << "constructor called_single_arg\n";}

        data (const my_class::my_class* class1, my_class::my_class* class2, bool is_const) : class1(class1) , class2(class2) {

            std::cout << "constructor called_dual_arg\n";
        }

        data (const my_class::my_class* class1, my_class::my_class* class2) : class1(class1), class2(class2) {

            std::cout << "constructor called dual arg non const\n";
        }

        // this does not work, as with a direct intializer, we arnt going to be making a copy, thus we have a mismathc
        // with class2() and class2
//        data (const my_class::my_class* class1, const my_class::my_class* class2) : class1(class1) , class2(class2) {
//            std::cout << "constructor called_dual_arg\n";
//        }

        ~data () {if (class1 != nullptr) delete class1; std::cout << "destructor called\n";}

        const my_class::my_class*& ref_class_class_1 (bool is_const) {

            if (class1 != nullptr) return class1;
        }

        // this dosnt work as, our return class1 is a const object, but the function returns a non const ref to it
//        my_class::my_class*& ref_class_class_1 () {
//
//            if (class1 != nullptr) return class1;
//        }

        // this does not work as we are trying to return class_2 which is non const, while the func requires a const
//        const my_class::my_class*& ref_class_class_2 (bool is_const) {
//
//            if (class2 != nullptr) return class2;
//        }

        my_class::my_class*& ref_class_class_2 () {

            if (class2 != nullptr) return class2;
        }
    };
}

int main () {

    auto *class1 = new const my_class::my_class(9);       // new class obj
    auto *class2 = new my_class::my_class(3);       // new class obj

    auto *class_2 = new data::data(class1,class2);      // instantiate class_2 with class1 and class2

    // this does not work, as we cannot assign, as the methods return const and we cannot change the object state
//    class_2->ref_class_class_1(true)->get_my_var() = 5;

    // this does not work, as we cannot assign
//    class_2->ref_class_class_1(true)->const_ref() = 2;

    std::cout << class_2->ref_class_class_2()->get_my_var()<<std::endl;    // print its atributes

    class_2->ref_class_class_2()->change_my_var() = 5;        // this does work, as we are returning non cosnt refernces

    std::cout << class_2->ref_class_class_2()->get_my_var();    // print class_2, notice the atribute value changed
}