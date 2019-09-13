/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/15
 Deliverable: MS2
 */

#ifndef Utilities_hpp
#define Utilities_hpp
#include <string>
#include <fstream>

class Utilities {
    size_t field_width;           // maximum field width needed
    static char delimiter;        // field delimiter character
    static std::ofstream logFile; // log file
public:
    Utilities();
    void setFieldWidth(size_t fw);
    size_t getFieldWidth() const;
    const std::string nextToken(const std::string&, size_t&, bool&);
    static void setDelimiter(const char);
    static void setLogFile(const char*);
    static std::ofstream& getLogFile();
};

#endif /* Utilities_hpp */
