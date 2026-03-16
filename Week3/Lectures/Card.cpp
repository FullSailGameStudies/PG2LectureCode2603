#include "Card.h"
#include <iostream>

int Card::Value()
{
    int val = 0;
    if (face_ == "A") val = 1;
    else if (face_ == "K") val = 13;
    else if (face_ == "Q") val = 12;
    else if (face_ == "J") val = 11;
    else val = std::stoi(face_);
    return val;
}

void Card::Print()
{
    std::cout << face_ << " " << suit_ << "\n";
}
