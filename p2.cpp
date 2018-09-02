#include "p2.h"

//ASSUMPTIONS:
//white spaces will be ignored
//characters will be ascii values
//numbers will be in base 10
//the bounds on int are –2147483648 to 2147483647
//if any characters are not spaces, negative signs or numbers, then the string is invaid
//zero is returned if the input string is not a valid number

//helper function for atoi(), returns true of the char is equivalent to 0 through 9
bool isNumerical(char c) {
    if(c >= '0' && c<= '9') {
        return true;
    } else {
        return false;
    }
}

int atoi(string str) {
    int ret = 0;
    bool hasNumStarted = false;
    bool isPositive = true;
    
    for(int i = 0; i < str.length(); i++) {
        //if str[i] is a blank space, goto the next char in the input string
        if(str[i] == ' ') {
            continue;
        }
        
        //if number start point has not been found yet, check for '-' sign
        if(!hasNumStarted && str[i] == '-') {
            hasNumStarted = true;
            isPositive = false;
            continue;
        }
        
        //if the current character is betwen 0 and 9, add this character to the return value
        if ( isNumerical(str[i]) ) {
            //add a zero to the return value so a new digit can be added in the ones place
            ret *= 10;
            
            //add a new digit to the ones place by converting str[i] to an int assuming ascii values
            ret += (int)str[i] - (int)'0';
            
            hasNumStarted = true;
        } else {
            //if the number has started and str[i] is not a number, the input is invalid
            return 0;
        }
    }//for()
    
    //if a negative sign '-' was found, turn the return value negative
    if(!isPositive) {
        ret *= -1;
    }
    
    return ret;
}//atoi

//ASSUMPTIONS:
//base of integer is given by the base parameter
//returns a null terminated string
//the bounds on the input int are –2147483647 to 2147483647
//the input char* has enough space allocated to fit the result

//This function will convert integer 'i', in base 'base', to a char* string
char* itoa(int i, char *str, int base) {
    //This covers the base case when i = 0
    if(i == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    
    //the current index to write to in the str
    int curCharIdx = 0;
    
    //numberStack will hold all digits in the converted base, to be popped into correct order
    vector<char> numberStack;
    
    //add a negative sign to our resulting string if i < 0
    if(i < 0) {
        str[curCharIdx++] = '-';
        i *= -1;
    }
    
    while(i != 0) {
        //onesPlaceNum will hold the value of lease significant digit from i in base 'base'
        int onesPlaceNum = i % base;
        
        char asciiVal;
        
        //get the ascii value of the onesPlaceNum, using a-z for bases higher than 10
        if (onesPlaceNum >= 10) {
            asciiVal = 'a' + onesPlaceNum - 10;
        } else {
            asciiVal = '0' + onesPlaceNum;
        }
        
        //push back onto the stack the ascii value
        numberStack.push_back(asciiVal);
        
        //subtract the lease significant digit from i
        i -= i % base;
        
        //divide by base and loop to top of while loop to operate on the next least significant digit
        i = i / base;
    }
    
    //pop from the numbersStack and write to the str to reverse the order of the stack
    while(!numberStack.empty()) {
        str[curCharIdx++] = numberStack.back();
        numberStack.pop_back();
    }
    
    //add the null terminating char
    str[curCharIdx] = '\0';
    
    return str;
}//itoa()

// int main(int argc, char const *argv[]) {
// 
//     cout << (int)'7' << endl;
//     cout << "Testing atoi()" << endl;
//     cout << atoi(string("700a")) * 2 << endl;
//     cout << atoi(string("70-09")) * 2 << endl;
//     cout << atoi(string("700")) * 2 << endl;
// 
//     cout << endl << "Testing itoa()" << endl;
//     char str[13];
//     cout << itoa(-2147483647, str, 10) << endl;
//     cout << itoa(-234, str, 10) << endl;
//     cout << itoa(270, str, 16) << endl;
//     cout << itoa(1750, str, 16) << endl;
// 
//     return 0;
// }