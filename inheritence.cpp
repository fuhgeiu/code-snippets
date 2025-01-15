#include <string>
#include <cassert>


struct Cutie {
    virtual const std::string description() = 0;     // All cuties need to have a description of what makes them cute.
    virtual const int cuteness_rating() = 0; // All cuties get a cuteness rating out of ten.
};

struct puppy : public Cutie {

    const std::string description () {return "very  ";}

    const int cuteness_rating () {return 80;}
};

struct kitty : public Cutie {

    const std::string description () {return "comically soft fur, like a bird or bunny \n";}

    const int cuteness_rating () {return 700;}
};

struct penguin : public Cutie {

    const std::string description () {return "its a penguin what can i say \n";}

    const int cuteness_rating () {return 999999;}
};


int main () {

    puppy Puppy;
    kitty kitty;
    penguin Penguin;

    assert(Puppy.cuteness_rating() == 80);
    assert(kitty.cuteness_rating() == 700);
    assert(Penguin.cuteness_rating() == 999999);










}