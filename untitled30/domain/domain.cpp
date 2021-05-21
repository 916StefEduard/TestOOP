#include "sstream"
#include "domain.h"


string vegetable::to_string(){
    stringstream ss;
    ss<<family<<" | "<<name<<" | "<<parts;
    return ss.str();
}