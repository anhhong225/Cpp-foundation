//Student name: Hong Trinh_438443
//Assignment 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

auto inp_file(){
    std::string str_line{};         //declare string to read the input file
    std::string lowstr_line{};      //declare string to store the lower words
    std::string filename{};         //store the name of input file

    std::vector<std::pair<int, char>> char_freq; //create a vector to store the character and frequency

    do {
        int frq[26] = {0};//declare the array frequency of character
        //make all element of array are zero
        for(auto & i : frq){
        i= 0;
        }
        //asking for the input file and open it
        std::cout << "Please enter a file name. Empty file name quits the program.\n";
        std::cout << "File name:";
        getline(std::cin,filename);
        std::ifstream in_file{filename + ".txt"};
        //argument if the file open
        if (in_file) {
            std::cout << "Opening \"" << filename << ".txt\"\n";
            std::ofstream out_file{filename + ".out"};
            std::locale loc;

        //read each line in file and take the character in a string
            while (std::getline(in_file, str_line)) {
                std::istringstream is_str{str_line};
                char ch;
                while (is_str >> ch) {
                    if (std::isalpha(ch) != 0) {
                        lowstr_line.push_back((std::tolower(ch, loc)));
                    }
                }
            }
        //count the frequency of each character
            for (auto i : lowstr_line) {
                if (std::isalpha(i) != 0) {
                    frq[i - 'a']++;
                }
            }

            for (auto & i : lowstr_line) {
                if (frq[i - 'a'] != 0) {
                    char_freq.emplace_back(frq[i - 'a'], i);
                    frq[i - 'a'] = 0;
                }
            }
        //sort the vector descend base on integer
            std::sort(char_freq.rbegin(), char_freq.rend());

            if (out_file) {
                for (auto el:char_freq) {
                    std::cout << el.second << " : " << el.first << "\n";
                    out_file << el.second << " : " << el.first << "\n";
                }
                std::cout << "Results saved to file \"" << filename << ".out\"\n";
            }
        }else {
            std::cout << "The file \"" << filename << ".txt\" doesn't exit.\n";
        }
    } while (!filename.empty());
    std::cout << "Bye!";

//    std::cin.clear();
//    std::cin.ignore();
//    char_freq.clear();
//    lowstr_line.clear();
};

int main() {
    inp_file();
}
