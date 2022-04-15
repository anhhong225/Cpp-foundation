#include "FileWriter.h"

bool FileWriter::is_open() const {
    return outFilePtr != nullptr;
}

FileWriter &FileWriter::write(std::string &input) {
    return write(input.c_str());
}

FileWriter &FileWriter::write(const char *input) {
    for(auto i = 0u; input[i] != '\0'; ++i){
        std::fputc(input[i], outFilePtr);
        ++m_size;
        if(input[i] == '\n'){
    ++m_lines;
}
    }
    return *this;
}

FileWriter &FileWriter::write(char input) {
    std::fputc(input, outFilePtr);
    ++m_size;
    if(input == '\n')
        ++m_lines;
    return *this;
}

FileWriter &FileWriter::write(int input) {
    std::fprintf(outFilePtr, "%d", input);
    ++m_size;
    return *this;
}

FileWriter &FileWriter::write(double input) {
    std::fputc((char)input, outFilePtr);
    ++m_size;
    if((char)input == '\n')
        ++m_lines;
    return *this;
}

FileWriter &FileWriter::write(bool input) {
    return input?write("true"):write("false");
}

FileWriter &FileWriter::then(std::string &input) {
    return write(input);
}

FileWriter &FileWriter::then(const char *input) {
    return write(input);
}

FileWriter &FileWriter::then(char input) {
    return write(input);
}

FileWriter &FileWriter::then(int input) {
    return write(input);
}

FileWriter &FileWriter::then(double input) {
    return write(input);
}

FileWriter &FileWriter::then(bool input) {
    return write(input);
}

FileWriter &FileWriter::newline() {
    return write('\n');
}

unsigned int FileWriter::lines() const {
    return m_lines;
}

std::size_t FileWriter::size() const {
    return m_size;
}

