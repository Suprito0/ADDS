#include "BigNumCalc.h"

BigNumCalc::BigNumCalc() {}
list<int> BigNumCalc::buildBigNum(std::string numString)
{
    list<int> list;
    for (char c : numString)
    {
        list.push_back(c - '0');
    }
    return list;
}
list<int> BigNumCalc::add(list<int> num1, list<int> num2)
{
    list<int> sum;
    int carry = 0;

    while (!num1.empty() || !num2.empty() || carry != 0)
    {
        int digit1 = 0, digit2 = 0;

        if (!num1.empty())
        {
            digit1 = num1.back();
            num1.pop_back();
        }
        if (!num2.empty())
        {
            digit2 = num2.back();
            num2.pop_back();
        }

        int tempSum = digit1 + digit2 + carry;
        carry = tempSum / 10;
        sum.push_front(tempSum % 10);
    }

    return sum;
}

list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2)
{
    list<int> sub;
    bool borrow = false;
    int tempSub = 0, maxBack, minBack;
    list<int> max, min;
    bool firstGreat = firstGreater(num1, num2);
    if (firstGreat)
    {
        max = num1;
        min = num2;
    }
    else
    {
        max = num2;
        min = num1;
    }
    while (!max.empty() || !min.empty())
    {
        maxBack = max.back();
        if (borrow)
        {
            maxBack--;
            borrow = false;
        }
        if (min.empty())
        {
            sub.push_front(maxBack);
            max.pop_back();
            continue;
        }
        minBack = min.back();

        if (minBack > maxBack)
        {
            borrow = true;
            maxBack = maxBack + 10;
        }
        tempSub = maxBack - minBack;

        sub.push_front(tempSub);

        max.pop_back();
        min.pop_back();
    }
    clean(sub);
    if (firstGreat)
    {
        return sub;
    }
    int temp = sub.front() * -1;
    sub.pop_front();
    sub.push_front(temp);

    return sub;
}

list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2)
{
    list<int> product;
    int carry = 0;
    int tempProduct = 0;
    while (!num1.empty())
    {
        tempProduct = num1.back() * num2.back() + carry;
        carry = tempProduct / 10;
        tempProduct = tempProduct % 10;
        product.push_front(tempProduct);
        num1.pop_back();
    }
    if (carry >= 1)
    {
        product.push_front(carry);
    }
    return product;
}

void BigNumCalc::clean(list<int>& num1){
    int size = num1.size();
    for(int i=0; i<size-1; i++){
        if(num1.front() != 0) return;

        num1.pop_front();
    }
}

bool BigNumCalc::firstGreater(list<int> num1, list<int> num2)
{
    int num1Size = num1.size();
    int num2Size = num2.size();
    if (num1Size > num2Size)
    {
        return true;
    }
    else if (num2Size > num1Size)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < num1Size; i++)
        {
            if (num1.front() > num2.front())
            {
                return true;
            }
            else if (num1.front() < num2.front())
            {
                return false;
            }
            num1.pop_front();
            num2.pop_front();
        }
    }
    return true;
}
BigNumCalc::~BigNumCalc() {}