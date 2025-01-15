// Online C++ compiler to run C++ program online
#include <iostream>

class my_class {

    int my_var;

public:

    my_class () = default;                                  // default constructor

    my_class (int var) : my_var(var) {std::cout << "constructor called\n" << std::endl;}      // direct initilizer

    ~my_class() {
        std::cout << "destructor called " << "obj with atribute" << my_var << std::endl;
    }

    int& change_my_var () {                                 // returns a refernce to my_var

        return my_var;
    }

    void acessor (int var) {    // to change atribute by passing in and function making a copy to asign

        this->my_var = var;
    }

    const int get_my_var () const {return my_var;}  // const method to return my_var

    const int& const_ref () const {     //returns a const refernce to my_var

        return my_var;
    }

};



void const_conversion (const my_class* obj) {    // non const function

// does not work, as we copied our passed in object into a const object, thus a non const method cannot be called
//     obj.change_my_var() = 6;


    // will work as const_ref is a const method, and since we made a copy of what we passed in the output is identical
    // to when we output in main with obj.const_ref()
    std::cout << obj->const_ref() << std::endl;

    delete obj;     // notice destructor does not get called without this line
}


int main() {


    auto *obj1 = new my_class();                         // non const object

    obj1->change_my_var() = 5;                            // change data with the use of non const ref

    std::cout << obj1->const_ref() << std::endl;                                  // print 5

    const_conversion (obj1);                                                // print 5

    obj1->acessor(7);                                // non const method to change atribute
    std::cout << obj1->get_my_var() << std::endl;                                 // print 7

    auto *obj2 = new const my_class(9);                        // const object
    std::cout << obj2->const_ref() << std::endl;                                               // print

    return 0;
}

/*      outout notes
 *
 *  -print 5 by streaming a refernce to the atribute but us telling the compiler it is a const refernce, thus it is immutible
 *
 *  -print 5, we pass in a non const obj into a non const function.
 *      - creates a copy of the obj and also labels it as a const object
 *      - bc the copy is a const obj, we can call a const method on it to print the atribute
 *
 *  -as we are using heap allocation, unless we delete the obj, the copy within the funciton is not deleted right away
 *
 *  *created a const object
 *
 *  -since we created a const object the constructor is called
 *
 *  -we can call a const method on the const object we just created
 *      -this method returns a const refernce to the atribute
 *      - prints the return
 */

