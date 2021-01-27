#ifndef CANDY
    #define CANDY
    #include <string>
    #include <iostream>

    using namespace std;
    /**
     * The Candy class holds information about each candy object.
     * The name, the candy type, the price type, the price,
     * the quantity (amount), and the calories
     */
    class Candy{
        protected:
            //the name of the candy
            string name;

            /**
             * the type of candy, valid values are
             * "jelly", "caramel", "chocolate", or "hard"
             */
            string candyType;

            /**
             * the unit type that the candy is sold in, 
             * valid values are "piece" or "pound"
             */
            string priceType;

            /**
             * the dollars per unit for this candy
             */
            float price;

            /**
             * The number of units in the store.
             * Depends on the pricetype,
             * in ounces for pound type, or in pieces for piece type
             */
            int amount;

            /**
             * the number of calories for 1 unit of this candy
             */
            float calories;

            /**
             * Construct a candy object with the given values.
             * name, candy type, price type, price, amount, calories
             */
            Candy(string nameIn, string candyTypeIn, string priceTypeIn, 
            float priceIn, int amountIn, float caloriesIn){
                name = nameIn;
                candyType = candyTypeIn;
                priceType = priceTypeIn;
                price = priceIn;
                amount = amountIn;
                calories = caloriesIn;
            }
        public:
            /**
             * copy constructor, 
             * makes a deep copy of the passed in Candy object
             */
            Candy(const Candy& rhs){
                name = rhs.name;
                candyType = rhs.candyType;
                priceType = rhs.priceType;
                price = rhs.price;
                amount = rhs.amount;
                calories = rhs.calories;
            }

            /**
             * deconstructor
             */
            ~Candy(){
                //TODO double check
                //all member variables are 
                //local variables stored on the stack
                //delete is not needed                
            }

            /**
             * assignment operator overloading
             */
            const Candy& operator = (const Candy& rhs){
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

            /**
             * Used to be able to sort candy items
             */
            friend bool operator < (const Candy& lhs, const Candy& rhs);

            /**
             * print details about this candy to standard out
             * prints name, amount in store, and total price on hand
             */
            void printDetails();

            //getters
            const string inline getName() {return name;}
            const string inline getCandyType() {return candyType;}
            const string inline getPriceType() {return priceType;}
            const float inline getPrice() {return price;}
            const int inline getAmount() {return amount;}
            const float inline getCalories() {return calories;}

            //setters
            void inline setName(string nameIn) {name = nameIn;}
            void inline setCandyType(string candyTypeIn) {candyType = candyTypeIn;}
            void inline setPriceType(string priceTypeIn) {priceType = priceTypeIn;}
            void inline setPrice(float priceIn) {price = priceIn;}
            void inline setAmount(int amountIn) {amount = amountIn;}
            void inline setCalories(float caloriesIn) {calories = caloriesIn;}
    };

#endif