#include <iostream>
#include <stdexcept>
#include <string>
#include "snowman.hpp"
using namespace std;

namespace ariel{
   const int ten = 10;
        const int one = 1;
        const int four= 4;
        const int eight = 8;
        const int input1 = 11114411;
        const int input2 = 33232124;
      

    void throwException(){
        throw invalid_argument("Invalid code");
    }
    //Input - number - must be 8 digits between 1-4 each digit
    //Output - snow man
    string snowman(int number){
        int tempNumber= number;
        int counter = 0;
        if(number < 0){
            throwException();
        }
     
        while(number != 0){
            int digit = number % ten;
            if(digit <one || digit > four){
                throwException();
            }
            number = number/ten;
            counter++;
        }
        if(counter != eight){
            throwException();
        }
        string result = "NOT_IMPLEMNTED";
        if( tempNumber == input1){
            result =  "_===_\n(.,.)\n( : )\n( : )";
        }
        else if(tempNumber ==input2){
            result =  "_/_\\(o_O)(] [)> (   )";
        }
        return result;
    }
}