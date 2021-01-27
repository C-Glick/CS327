#ifndef JELLY_CANDY
    #define JELLY_CANDY
    #include "Candy.h"

    class JellyCandy : public Candy{
        protected:
            int color;
        public:
            /**
             * Jelly candy constructor, the same as the normal Candy constructor
             * but doesn't require a candy type and adds a color parameter
             * 
             * requires: string name, string price type, float price, int amount, float calories, int color (0-9)
             */
            JellyCandy(string nameIn, string priceTypeIn, 
            float priceIn, int amountIn, float caloriesIn, int colorIn) : 
            Candy(nameIn, "jelly", priceTypeIn, priceIn, amountIn, caloriesIn){
                color = colorIn;
            }

            /**
             * copy constructor, 
             * makes a deep copy of the passed in JellyCandy object
             */
            JellyCandy(const JellyCandy& rhs) : 
            Candy(rhs.name, "jelly", rhs.priceType, rhs.price, rhs.amount,
            rhs.calories){
                color = rhs.color;
            }

            /**
             * deconstructor
             */
            ~JellyCandy(){
                //TODO double check
                //all member variables are 
                //local variables stored on the stack
                //delete is not needed                
            }


            /**
             * assignment operator overloading
             */
            const JellyCandy& operator = (const JellyCandy& rhs){
                if(this != &rhs){
                    name = rhs.name;
                    candyType = rhs.candyType;
                    priceType = rhs.priceType;
                    price = rhs.price;
                    amount = rhs.amount;
                    calories = rhs.calories;
                    color = rhs.color;
                }
                return *this;
            }

            //getters
            const int inline getColor() {return color;}

            //setters
            void inline setColor(int colorIn) {color = colorIn;}

    };
#endif