#ifndef CARAMEL_CANDY
    #define CARAMEL_CANDY
    #include "Candy.h"

    class CaramelCandy : public Candy{
        protected:
            //no additional member variables needed
        public:
            /**
             * Caramel candy constructor, the same as the normal Candy constructor
             * but doesn't require a candy type
             * 
             * requires: string name, string price type, float price, int amount, float calories
             */
            CaramelCandy(string nameIn, string priceTypeIn, 
            float priceIn, int amountIn, float caloriesIn) : 
            Candy(nameIn, "caramel", priceTypeIn, priceIn, amountIn, caloriesIn){}

            /**
             * copy constructor, 
             * makes a deep copy of the passed in CaramelCandy object
             */
            CaramelCandy(const CaramelCandy& rhs) : 
            Candy(rhs.name, "caramel", rhs.priceType, rhs.price, rhs.amount,
            rhs.calories){}

            /**
             * deconstructor
             */
            ~CaramelCandy(){
                //TODO double check
                //all member variables are 
                //local variables stored on the stack
                //delete is not needed                
            }


            /**
             * assignment operator overloading
             */
            const CaramelCandy& operator = (const CaramelCandy& rhs){
                if(this != &rhs){
                    name = rhs.name;
                    candyType = rhs.candyType;
                    priceType = rhs.priceType;
                    price = rhs.price;
                    amount = rhs.amount;
                    calories = rhs.calories;
                }
                return *this;
            }
    };
#endif