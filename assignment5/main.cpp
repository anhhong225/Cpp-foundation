#include <iostream>
#include <ctime>
#include "Tracker.h"
#include "DynamicArray.h"
#include "FileWriter.h"
#include "Logger.h"

void print_usage(){
    std::cout << "Instances: " << Simple::tracker().instances() << " ";
    std::cout << "memory: " << Simple::tracker().memory() << "\n";
}
void count(){
    Simple s_func1{0};
    Simple s_func2{1};
    print_usage(); // 3, 24
    {
// open a new scope
        Simple s_internal{3};
        print_usage(); // 4, 32
    }
    print_usage(); // 3, 24
}

int main() {
//    Simple s_main{42};
//    print_usage(); // 1, 8
//    count();
//    print_usage(); // 1, 8

//    DynamicArray da1{1024*768};
//    std::cout << "Instances: " << da1.tracker().instances()
//              << " memory: " << da1.tracker().memory() << "\n";
//    DynamicArray da2{1024 * 255};
//    std::cout << "Instances: " << da2.tracker().instances()
//              << " memory: " << da2.tracker().memory() << "\n";
//    {
//// new scope
//        DynamicArray da3{128};
//        std::cout << "Instances: " << da3.tracker().instances()
//                  << " memory: " << da3.tracker().memory() << "\n";
//    }
//    std::cout << "Instances: " << DynamicArray::tracker().instances()
//              << " memory: " << DynamicArray::tracker().memory() << "\n";


//    FileWriter fw{"test.txt"};
//    fw.write("Alice has ").then(3).then(" rats.").newline();
//    std::cout << "Written " << fw.size() << " chars and "
//              << fw.lines() << " lines.\n";
//    fw.write("True of false: does Alice like rats?\n")
//                     .then("Answer: ")
//                     .then(true)
//                     .then("\n");
//    std::cout << "Written " << fw.size() << " chars and "
//              << fw.lines() << " lines.\n";

    Logger::get().log("Test1");
    Logger::get().log("Test2");
    Logger::get().log("Test3");
    Logger::get().log("Test4");
}
