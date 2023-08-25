
#ifndef PROBLEM4_HPP
#define PROBLEM4_HPP

class DynamicPair {

    public:
        //default constructor
        DynamicPair();

        //construct with the two variables
        DynamicPair(const int& value1, const double& value2);

        //copy constructor
        DynamicPair(const DynamicPair& a);

        //deconstructor
        ~DynamicPair();

        //operator assignment
        DynamicPair& operator=(const DynamicPair& a);

        //set the int value
        void setInt(int value);

        //set the double value
        void setDouble(double value);

        //return the int value
        int getInt() const;

        //return the double value
        double getDouble() const;


    private:
        int* integerValue;
        double* doubleValue;
};

#endif