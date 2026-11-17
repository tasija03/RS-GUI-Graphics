#ifndef SANSA
#define SANSA

#include "Polje.hpp"

class Sansa : public Polje{

private:
    

public:
    Sansa(int indeks, const std::string& kategorija, const std::string& naziv, const std::string& putanjaSlike);
};

#endif