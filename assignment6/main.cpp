#include <iostream>
#include "string.h"


int main() {
//    string str{"Alice and Bob 546"};
//    std::cout << str.length() << '\n'; // 5
//    std::cout << str.empty() << ", " << (bool)str << '\n'; // 0, 1
//    std::cout << str.c_str(); // Alice

//    string str{"Bob"};
//    str[0] = 'R'; // str is not "Rob"
//    str.back() = 't'; // str is not "Rot"
//    str.at(1) = 'a'; //str is now "Rat";
//    char c = str.at(100); // an exception is thrown

    string str{"Alice"};
    str.append(" and Bob"); // str is now "Alice and Bob"
    for(int i = 0; i < str.length(); i++){
        std::cout << str[i];
    }
    std::string are{" are"};
    str.append(are); // str is now "Alice and Bob are"
    for(int i = 0; i < str.length(); i++){
        std::cout << str[i];
    }
//    string another{" friends."};
//    str.append(another);

    //string str{"Alice and Bob have mice"};
    //auto alice = str.substr(0, 5); // alice contains "Alice"
    //auto mice = str.substr(19); // mice contains "mice"
    //std::cout << str.starts_with("alice"); // 0
    //std::cout << str.ends_with("mice"); // 1
    //std::cout << str.contains("b h"); // `
    //std::cout << str.find("ic"); // 2
    //std::cout << str.find("ic", 3); // 20

//    for(int i = 0; i < alice.length(); i++){
//        std::cout << alice[i];
//    }
//
//    for(int i = 0; i < mice.length(); i++){
//        std::cout << mice[i];
//    }
}