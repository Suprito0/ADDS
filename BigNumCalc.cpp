#include"BigNumCalc.h"

list<int> BigNumCalc::buildBigNum(std::string numString){
    list<int> list;
    for(char c : numString){
        list.push_back(c - '0');
    }
    return list;
}
list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    list<int> sum;
    int carry = 0;
    int tempSum = 0;
while (!num1.empty() || !num2.empty() || carry != 0){
        if (num1.empty()) {
            tempSum = 0 + num2.back() + carry;
            num2.pop_back();
        } else if (num2.empty()){
            tempSum = num1.back() + 0 + carry;
            num1.pop_back();
        } else {
            tempSum = num1.back() + num2.back() + carry;
            num1.pop_back();
            num2.pop_back();
        }
        carry = 0;
        if (tempSum > 9){
            tempSum = tempSum - 10;
            carry = 1;
        }
        sum.push_front(tempSum);
    }
    if(carry == 1){
        sum.push_front(carry);
    }
    return sum;
}
list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    // list<int> sub;
    // int carry = 0;
    // int tempSub = 0;
    return num1;
}
list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
    list<int> product;
    int carry = 0;
    int tempProduct = 0;
    while (!num1.empty()){
        tempProduct=num1.back()*num2.back() + carry;
        carry = tempProduct/10;
        tempProduct = tempProduct%10;
        product.push_front(tempProduct);
        num1.pop_back();
    }
    if(carry >= 1){
        product.push_front(carry);
    }
    return product;
}
BigNumCalc::~BigNumCalc(){}