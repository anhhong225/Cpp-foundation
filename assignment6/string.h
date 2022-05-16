#ifndef ASSIGNMENT6_STRING_H
#define ASSIGNMENT6_STRING_H

#include <iostream>
#include <memory>

class string {
public:
    string();
    string(const char* ch);
    string(const std::string& str);
    string(const string& other);
    string& operator =(const string& other);
    ~string();
    //assessors
    int length();//return number of characters in the string
    bool empty();//true if string is empty
    operator bool();//return true is the string is not empty
    const char* c_str();//return a raw, containt pointer to the storage array
    char& at(int index);
    const char& at(int index) const;
    char& operator[](int index);
    const char& operator[](int index) const;
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
    //modifiers
    void append(string str);
    void append(std::string str);
    void append(const char* str);
    void append(char str);
    //searching and substrings
    string substr(int start, int length);
    string substr(int start);
    bool starts_with(const string& prefix);
    bool ends_with(const string& suffix);
    bool contains(const string& needle);
    int find(const string& needle);
    int find(const string& needle, int start);
private:
    size_t m_size;
    char* m_data;
};


#endif //ASSIGNMENT6_STRING_H
