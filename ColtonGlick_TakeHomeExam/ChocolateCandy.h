#ifndef CHOCOLATE_CANDY
    #define CHOCOLATE_CANDY
    #include "Candy.h"

    class ChocolateCandy : public Candy{
        protected:
            //no additional member variables needed
        public:
            /**
             * Chocolate candy constructor, the same as the normal Candy constructor
             * but doesn't require a candy type
             * 
             * requires: string name, string price type, float price, int amount, float calories
             */
            ChocolateCandy(string nameIn, string priceTypeIn, 
            float priceIn, int amountIn, float caloriesIn) : 
            Candy(nameIn, "chocolate", priceTypeIn, priceIn, amountIn, caloriesIn){}

            /**
             * copy constructor, 
             * makes a deep copy of the passed in ChocolateCandy object
             */
            ChocolateCandy(const ChocolateCandy& rhs) : 
            Candy(rhs.name, "chocolate", rhs.priceType, rhs.price, rhs.amount,
            rhs.calories){}

            /**
             * deconstructor
             */
            ~ChocolateCandy(){
                //TODO double check
                //all member variables are 
                //local variables stored on the stack
                //delete is not needed                
            }


            /**
             * assignment operator overloading
             */
            const ChocolateCandy& operator = (const ChocolateCandy& rhs){
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