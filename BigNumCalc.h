#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include"Node.h"
#include<list>
class BigNumCalc{
    private:
    public:
        BigNumCalc();
        list<int> buildBigNum(std::string numString);
        list<int> add(std::list<int> num1, std::list<int> num2);
        list<int> sub(std::list<int> num1, std::list<int> num2);
        list<int> mul(std::list<int> num1, std::list<int> num2);
        bool firstGreater(list<int> num1, list<int> num2);
        void clean(list<int>& num1);
        ~BigNumCalc();
};

#endif