#ifndef ASSIGNMENT5_FILEWRITER_H
#define ASSIGNMENT5_FILEWRITER_H

#include <fstream>

class FileWriter {
public:
    FileWriter(const char* file_name):m_lines{},m_size{}{
        outFilePtr = std::fopen(file_name, "w");
    }

    ~FileWriter(){
        if(is_open()){
            std::fflush(outFilePtr);
            std::fclose(outFilePtr);
        }
    }

    bool is_open() const;

    FileWriter& write(std::string& input);
    FileWriter& write(const char *input);
    FileWriter& write(char input);
    FileWriter& write(int input);
    FileWriter& write(double input);
    FileWriter& write(bool input);


    FileWriter& then(std::string& input);
    FileWriter& then(const char * input);
    FileWriter& then(char input);
    FileWriter& then(int input);
    FileWriter& then(double input);
    FileWriter& then(bool input);

    FileWriter& newline();
    unsigned int lines() const;
    std::size_t size() const;

private:
    unsigned int m_lines;
    size_t m_size;
    FILE *outFilePtr;
};


#endif //ASSIGNMENT5_FILEWRITER_H
