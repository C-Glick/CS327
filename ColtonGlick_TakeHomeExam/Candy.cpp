#include "Candy.h"

void Candy::printDetails(){
    string unit = priceType;
    float amountUnits = amount;
    if(priceType == "pound"){
        //set units to ounces
        unit = "ounce";
        //calculate price based on pounds
        amountUnits = amount / 16.0;
    }
    cout << name << ", " <<  amount << " " << unit << "(s), $" << price * amountUnits << endl;
}

bool operator < (const Candy& lhs, const Candy& rhs){
    float lhsValue;
    float rhsValue;

    if(lhs.priceType == "pound"){
        lhsValue = (lhs.amount / 16.0) * lhs.price;
    }else{
        lhsValue = lhs.amount * lhs.price;
    }

    if(rhs.priceType == "pound"){
        rhsValue = (rhs.amount / 16.0) * rhs.price;
    }else{
        rhsValue = rhs.amount * rhs.price;
    }

    //using greater than instead of less than to change order of sort
    return lhsValue > rhsValue;
}