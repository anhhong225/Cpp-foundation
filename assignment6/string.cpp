
#include <cstring>
#include <sstream>
#include "string.h"


string::string():m_size{0},m_data{new char(m_size+1)} {

}

string::string(const char *ch):m_size{strlen(ch)},m_data{new char(m_size+1)}{
    std::strcpy(m_data,ch);
}

string::string(const std::string& str):m_size{strlen(str.c_str())}, m_data{new char(m_size+1)}{
    std::strcpy(m_data, str.c_str());
}

string::string(const string &other):string(other.m_data) {
    std::copy(&other.m_data[0], &other.m_data[m_size], &m_data[0]);
}

string::~string() {
    delete m_data;
}

string &string::operator=(const string &other) {
    if(this == &other) return *this;
    if(m_size == other.m_size){
        std::copy(other.m_data, other.m_data + other.m_size +1, m_data);
    }else{
        auto data = new char[other.m_size + 1];
        delete m_data;
        m_data = data;
        std::copy(other.m_data,other.m_data + other.m_size +1, m_data);
        m_size = other.m_size;
    }
    return *this;
}

int string::length() {
    return m_size;
}

bool string::empty() {
    if(m_data[0] == '\0') return true;
    return false;
}

string::operator bool() {
    if(m_data[0] == '\0') return false;
    return true;
}

const char *string::c_str() {
    return m_data;
}

char &string::at(int index) {
    if(index >= m_size) throw std::invalid_argument("Error");
    return m_data[index];
}

const char &string::at(int index) const {
    if(index >= m_size) throw std::invalid_argument("Error");
    return m_data[index];
}

char &string::operator[](int index) {
    return m_data[index];
}

const char &string::operator[](int index) const {
    return m_data[index];
}

char &string::front() {
    return m_data[0];
}

char &string::back() {
    return m_data[m_size-1];
}

const char &string::front() const {
    return m_data[0];
}

const char &string::back() const {
    return m_data[m_size-1];
}

void string::append(string str) {
    for (int i = 0; i < strlen(str.c_str()); ++i)
    {
        m_data[m_size] = str.m_data[i];
        m_size++;
    }
}

void string::append(std::string str) {
    for (int i = 0; i < strlen(str.c_str()); ++i)
    {
        m_data[m_size] = this->m_data[i];
        m_size++;
    }
}

void string::append(const char *str) {
    size_t new_size = this->m_size + strlen(str) + 1;
    char* temp{new char[new_size]};
    for(auto i = 0; i < this->m_size;i++){
        temp[i] = this->m_data[i];
    }
    for(auto i = 0; i < new_size;i++){
        temp[i] = str[i - this->m_size - 1];
    }
    this->m_data = temp;
    this->m_size = new_size;
}

void string::append(char str) {
    std::stringstream strstr;
    strstr << m_data << str;
    m_size += strlen(strstr.str().c_str()+1);
    std::strcat(m_data, strstr.str().c_str());
}

string string::substr(int start, int length) {
    string substr{};
    char ch[2]{};
    for(int i = 0; i < length; i++){
        ch[0] = this->at(i + start);
        //std::cout << this->at(i + start);
        substr.append(ch);
    }
    return substr;
}

string string::substr(int start) {
    string substr{};
    for(int i = start; i < this->m_size; i++){
        substr.append(m_data[i]);
    }
    return substr;
}

bool string::starts_with(const string& prefix) {
    if (prefix.m_size <= this->m_size){
        string substr = this->substr(0, prefix.m_size);
        for(auto i = 0; i < prefix.m_size; i++){
            if(substr[i]==prefix[i]) return true;
            else return false;
        }
    }else return false;
}

bool string::ends_with(const string &suffix) {
    if (suffix.m_size <= this->m_size){
        string substr = this->substr(0, suffix.m_size);
        int m = this->m_size - suffix.m_size;
        for(int i = m; i < m+suffix.m_size;i++){
            if(substr[i]==suffix[i - suffix.m_size]) return true;
            else return false;
        }
    }else return false;
}

bool string::contains(const string &needle) {
    if (needle.m_size > this->m_size) return false;
    for(auto i = 0; i < this->m_size;){
        int j = 0;
        //check if first character match
        if(this->front() == needle.front()){
            int k = i;
            while (this[i] == needle[j] && j < needle.m_size){
                j++;
                i++;
            }
            if (j == needle.m_size)
                return true;
            else // Re-initialize i to its original value
                i = k;
        }
    }
    return false;
}

int string::find(const string &needle) {
    int m = 0, index = -1;
    for(auto i=0; i < this->m_size; i++){
        if(this[i] == needle[m]){
            if(m == 0)
                index = i;
            m++;
            if(m == needle.m_size){
                return index;
            }else m = 0;
        }
    }
    return -1;
}

int string::find(const string &needle, int start) {
    int m = 0, index = -1;
    for(auto i=start; i < this->m_size; i++){
        if(this[i] == needle[m]){
            if(m == 0)
                index = i;
            m++;
            if(m == needle.m_size){
                return index;
            }else m = 0;
        }
    }
    return -1;
}
