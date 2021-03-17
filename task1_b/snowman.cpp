
#include "snowman.hpp"
#include <array>
#include <string>

const auto TEN = 10;
const auto BIG = 44444444;
const auto SMALL = 11111111;
const int B = 7, T = 6, Y = 5, X = 4, R = 3, L = 2, N = 1, H = 0;
const int numsize = 8;
array<int , numsize> numbers{};


namespace ariel{
    string basis(int x) {
        if(x == N) {return " ( : )\n";}
        if(x == L) {return " (\" \")\n";}
        if(x == R) {return " (___)\n";}
        if(x == X) {return " (   )\n";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string torso(int x) {
        if(x == N) {return "( : )";} 
        if(x == L) {return "(] [)";}
        if(x == R) {return "(> <)";}
        if(x == X) {return "(   )";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string y_hand(int x) {
        if(x == N) {return ">";}
        if(x == L) {return "/";}
        if(x == R) {return "\\";}
        if(x == X){return " ";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string x_hand(int x) {
        if(x == N) {return "<";}
        if(x == L) {return "\\";}
        if(x == R) {return "/";}
        if(x == X){return " ";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string eye(int x) {
        if(x == N) {return ".";}
        if(x == L) {return "o";}
        if(x == R) {return "O";}
        if(x == X) {return "-";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string nose_mouth(int x) {
        if(x == N) {return ",";}
        if(x == L) {return ".";}
        if(x == R) {return "_";}
        if(x == X) {return " ";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
    string hat(int x) {
        if(x == N) {return  " _===_\n";}
        if(x == L) {return "  ___\n .....\n";}
        if(x == R) {return "   _\n  /_\\\n";}
        if(x == X) {return "  ___\n (_*_)\n";}
        throw std::out_of_range{"Invalid code '" + to_string(x) + "'"};
    }
string getnumber(int num){

numbers [B]= num % TEN;
        num /= TEN;
        numbers [T] = num % TEN;
        num /= TEN;
       numbers [Y] = num % TEN;
        num /= TEN;
        numbers [X] = num % TEN;
        num /= TEN;
       numbers [R] = num % TEN;
        num /= TEN;
        numbers [L] = num % TEN;
        num /= TEN;
        numbers [N] = num % TEN;
        num /= TEN;
        numbers [H] = num % TEN; 

        string t1;
        if(numbers [Y] == L && numbers [X] == L) {
            t1 = x_hand(numbers [X]) + "(" + eye(numbers [L]) + nose_mouth(numbers [N]) + eye(numbers [R]) + ")" + y_hand(numbers [Y]) + "\n " + torso(numbers [T]) + " \n";
        }
        else if(numbers [X] == L) {
            t1 = x_hand(numbers [X]) + "(" + eye(numbers [L]) + nose_mouth(numbers [N]) + eye(numbers [R]) + ")" + " \n " + torso(numbers [T]) + y_hand(numbers [Y]) + "\n";
        }
        else if(numbers [Y] == L) {
            t1 =  " (" + eye(numbers [L]) + nose_mouth(numbers [N]) + eye(numbers [R]) + ")" + y_hand(numbers [Y]) + "\n" + x_hand(numbers [X]) + torso(numbers [T]) + " \n";
        }
        else {
            t1 =  " (" + eye(numbers [L]) + nose_mouth(numbers [N]) + eye(numbers [R]) + ")" + " \n" + x_hand(numbers [X]) + torso(numbers [T]) + y_hand(numbers [Y]) + "\n";
        }
        return hat(numbers [H]) + t1 + basis(numbers [B]); 

}
    string snowman(int num){
        if(num > BIG || num < SMALL) {
            throw std::out_of_range{"Invalid code '" + to_string(num) + "'"};
        }
        return getnumber(num);  
    }
}

