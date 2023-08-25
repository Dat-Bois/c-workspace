#include "problem4.hpp"


// Inits dynamic pair constructor with some default values of int 0 and double 3
DynamicPair::DynamicPair() : integerValue{new int{0}}, doubleValue{new double{3}}{}

// Inits dynamic pair with the two input values (int, double)
DynamicPair::DynamicPair(const int& value1, const double& value2) : integerValue{new int{value1}}, doubleValue{new double{value2}} {}

// Copy constructor
DynamicPair::DynamicPair(const DynamicPair& a) : integerValue{new int{a.getInt()}}, doubleValue{new double{a.getDouble()}} {}

// Deconstructor
DynamicPair::~DynamicPair() {
    delete integerValue;
    delete doubleValue;
}

// Operator assignment
DynamicPair& DynamicPair::operator=(const DynamicPair& a) {

    if(this != &a) {
        *integerValue = a.getInt();
        *doubleValue = a.getDouble();
    }
    return *this;
}

//set the int value
void DynamicPair::setInt(int value) {*integerValue=value;}

//set the double value
void DynamicPair::setDouble(double value) {*doubleValue=value;}

//return the int value
int DynamicPair::getInt() const {return *integerValue;}

//return the double value
double DynamicPair::getDouble() const {return *doubleValue;}