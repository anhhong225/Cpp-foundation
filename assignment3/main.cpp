//Author: Hong Trinh-438443
//Day: 11/03/2021
//The assignment make the calculation on rational number
#include <iostream>
#include "Rational.h"
#include "Rational_processor.h"
#include "Rational_Calc.h"

//The main asks user want to put data from file or by hand
//1. call the function process in Rational_processor class to read the file and calculation
//2. read the input from user and call function calculation in Rational_Calc class
int main() {
    //Display two options input
    int choice;
    std::cout << "1. Insert data from file" << '\n';
    std::cout << "2. Insert data by hand-entered" << '\n';
    std::cout << "3. Quit" << '\n';
    std::cout << "Your choice:";
    std::cin >> choice; //user type their choice
    std::cin.ignore(); //clear input cin
    switch (choice) {
        //Data from input file
        case 1:{
            std::string filename;
            std::cout << "Input file name:";
            std::cin >> filename; //asking the file input name
            Rational_processor::process(filename);//call the function process to read the data from file and run the calculation
            break;
        }
        //Data input by hand-entered
        case 2:{
            std::string in_exp;
            std::cout << "expression:";// asking user insert the expression
            std::getline(std::cin, in_exp);//get the expression
            Rational result;//create a rational number object
            result = Rational_Calc::calculate(in_exp);//calculate the result by calling function calculate with parameter is input string
            std::cout << result.to_str() << '\n';
            std::cin.ignore();
            break;
        }
        case 3:
            std::cout << "Bye!\n";
            break;
        default:
            break;
    }
}
