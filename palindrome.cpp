#include <utility>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

bool isPalindrome(string str, int start, int end) {
    while(start < end) {
        if(str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int convert_to_key(int start, int end) {
    return start * 10000 + end;
}

pair<int, int> find_longest_palindrome(string str, int start, int end, unordered_map< int , pair<int, int> > &table) {
    //if start end pair is in table already, return answer
    // pair<int, int> key(start, end);
    int key = convert_to_key(start, end);
    
    if(table.find(key) != table.end()) {
        return table[key];
    }
    
    pair<int, int> returnVal;
    
    if(start == end) {
        returnVal = make_pair(start, end);
        return returnVal;
    }
    
    if(isPalindrome(str, start, end)) {
        returnVal = make_pair(start, end);
        return returnVal;
    }
    
    pair<int, int> option1 = find_longest_palindrome(str, start+1, end, table);
    
    pair<int, int> option2 = find_longest_palindrome(str, start, end-1, table);
    
    if(option1.second - option1.first > option2.second - option2.first) {

        table[key] = option1;
        return option1;
    } else {
        table[key] = option2;
        return option2;
    }
    
}


string find_longest_palindrome(string str) {
    //key = start and end values in the whole string
    //value = start and end of the longest palindrome in the key
    unordered_map< int , pair<int, int> > table;
    pair<int, int> answer;
    
    answer = find_longest_palindrome(str, 0, str.size() - 1, table);
    
    str = str.substr(answer.first, answer.second);
    return str;
}


int main(int argc, char const *argv[]) {
    
    //cdc
    string str = "acdcdcefgabcdefgfedcba";
    
    str = find_longest_palindrome(str);
    
    cout << str << endl;
    
    return 0;
}

// a, c, d, c, e, f, g