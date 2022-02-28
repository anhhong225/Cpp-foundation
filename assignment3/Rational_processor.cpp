//Hong Trinh_438443
//Date: 15/03/2021
//

#include <fstream>
#include <iostream>
#include <vector>
#include "Rational_processor.h"
#include "Rational.h"
#include "Rational_Calc.h"

// Function to read the input file and call the calculation function for calculating
// create an output file and put the result into output file
bool Rational_processor::process(const std::string& filename) {
    std::ifstream in_file(filename);
    if(in_file){
        std::string line;
        size_t pos = filename.rfind('.');
        std::string o_file;
        o_file = filename.substr(0,pos);
        std::ofstream out_file(o_file + ".out");
        while(std::getline(in_file,line)){
            if(!line.empty()){
                //std::cout << line << '\n';
                Rational result;
                result = Rational_Calc::calculate(line);
                std::cout << result.to_str() << '\n';
                // put the result into output file still have problem
                if(out_file){
                    out_file << line << "->" << result.to_str() << '\n';
                }
            }
        }
        out_file.clear();
        out_file.close();
        in_file.close();
        return true;
    }else
    {
        std::cout<<"Cannot open file\n";
        return false;
    }
}

