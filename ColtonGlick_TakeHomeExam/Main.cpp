#include "Candy.h"
#include "HardCandy.h"
#include "ChocolateCandy.h"
#include "CaramelCandy.h"
#include "JellyCandy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

/**
 * trim whitespace at the beginning and end of the given string
 * returns the trimmed string
 */
string trimString(string in){
    if(in == ""){
        return in;
    }
    //trim the end
    int end = in.length();
    while(isspace(in[--end]));
    end++;
    string result = in.substr(0, end);

    //trim the front
    int start = 0;
    while(isspace(result[start++]));
    start--;
    result = result.substr(start, end-start);

    return result;
}

/**
 * main function to parse the input file
 * and output details
 */
int main(int argc, char *argv[]){
    if(argc != 2){
        cout << "Usage: candy <input file>" << endl;
        exit(EXIT_FAILURE);
    }

    //open the input file
    ifstream fileIn;
    fileIn.open(argv[1]);
    if (!fileIn.is_open()) {
      cout << "Could not open file " << argv[1] << endl;
      return 1;
   }

    vector<Candy> candyInventory;

    //parse the entire file
    while(!fileIn.eof()){
        string line;
        getline(fileIn, line);
        line = trimString(line);
        //skip lines above start
        if(line == "START"){
            //skip blank lines before candy definition
            do{
                getline(fileIn, line);
                line = trimString(line);
            }while(line == "");
            //continue until hit END
            while (line != "END"){
                string name;
                string type;
                string priceType;
                float price;
                int color;
                int amount;
                float calories;

                //get name 
                name = line;

                //get candy type
                getline(fileIn, line);
                line = trimString(line);
                type = line;

                //get price type
                getline(fileIn, line);
                line = trimString(line);
                priceType = line;

                //get price, convert to float
                getline(fileIn, line);
                line = trimString(line);
                price = stof(line);

                //only get the color line if type is hard or jelly
                if(type == "hard" || type == "jelly"){
                    getline(fileIn, line);
                    line = trimString(line);
                    color = stoi(line);
                }

                //get amount, convert to int
                getline(fileIn, line);
                line = trimString(line);
                amount = stoi(line);

                //get calories, convert to float
                getline(fileIn, line);
                line = trimString(line);
                calories = stof(line);

                //only create a new candy object if the type is valid
                //append to the back of the inventory vector
                if(type == "jelly"){
                    JellyCandy jelly = JellyCandy(name, priceType, price, amount, calories, color);
                    JellyCandy& candy = jelly;
                    candyInventory.push_back(candy);
                }else if(type == "caramel"){
                    CaramelCandy caramel = CaramelCandy(name, priceType, price, amount, calories);
                    CaramelCandy& candy = caramel;
                    candyInventory.push_back(candy);
                }else if(type == "chocolate"){
                    ChocolateCandy chocolate = ChocolateCandy(name, priceType, price, amount, calories);
                    ChocolateCandy& candy = chocolate;
                    candyInventory.push_back(candy);
                }else if(type == "hard"){
                    HardCandy hard = HardCandy(name, priceType, price, amount, calories, color);
                    HardCandy& candy = hard;
                    candyInventory.push_back(candy);
                }

                //skip blank lines after candy definition
                do{
                    getline(fileIn, line);
                    line = trimString(line);
                }while(line == "");
            }
        }
        
    }
    
    //sort the inventory in descending order based on the potential revenue
    sort(candyInventory.begin(), candyInventory.end());

    //print the details of all candy in the candy inventory
    cout << "Name | Quantity on hand | Potential revenue\n" << endl;

    for(int i=0; i<candyInventory.size(); i++){
        Candy candy = candyInventory.at(i);
        candy.printDetails();
    }
    cout << endl;

    //print total value of candy in the candy inventory
    float sum = 0;
    for(int i=0; i<candyInventory.size(); i++){
        Candy candy = candyInventory.at(i);
        if(candy.getPriceType() == "pound"){
            sum += (candy.getAmount() / 16.0) * candy.getPrice();
        }else{
            sum += candy.getAmount() * candy.getPrice();
        }
    }

    cout << "Total value in store: $" << sum << "\n" << endl;

    //print number of candy types for each type of candy in the candy inventory
    int numHard = 0;
    int numJelly = 0;
    int numCaramel = 0;
    int numChocolate = 0;

    for(int i=0; i<candyInventory.size(); i++){
        Candy candy = candyInventory.at(i);
        if(candy.getCandyType() == "hard"){
            numHard++;
        }else if(candy.getCandyType() == "jelly"){
            numJelly++;
        }else if(candy.getCandyType() == "caramel"){
            numCaramel++;
        }else if(candy.getCandyType() == "chocolate"){
           numChocolate++;
        } 
    }
    
    cout << "Types of hard candy: " << numHard << endl;
    cout << "Types of jelly candy: " << numJelly << endl;
    cout << "Types of caramel candy: " << numCaramel << endl;
    cout << "Types of chocolate candy: " << numChocolate << endl;

    return 0;
}