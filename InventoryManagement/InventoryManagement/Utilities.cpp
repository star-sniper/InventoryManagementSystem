/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/15
 Deliverable: MS2
 */
#include "Utilities.h"

char Utilities::delimiter = '|';
std::ofstream Utilities::logFile;
Utilities::Utilities()
{
    field_width = 1;
}

void Utilities::setFieldWidth(size_t fw)
{
    field_width = fw;
}

size_t Utilities::getFieldWidth() const
{
    return field_width;
}


const std::string Utilities::nextToken(const std::string& s, size_t& pos, bool& more)
{
    std::string temp = s.substr(pos);
    
    size_t delimiter_pos = temp.find(delimiter);
    temp = delimiter_pos == std::string::npos ?
   
    temp.substr(0, temp.find_first_of("\r\n")) : // until end of line
    
    temp.substr(0, delimiter_pos);                // until next delimiter
    
    if(field_width < temp.size())
        field_width = temp.size();
    
    pos += temp.size() + 1;
    more = (pos < s.size() - 1); // ignore possible empty token at the end
    
    
    //remove trailing spaces
    size_t temp_pos;
    while((temp_pos = temp.size()-1) != std::string::npos)
    {
        if(isspace(temp.at(temp_pos))==true)
            temp.erase(temp_pos);
        else
            break;
    }
    // remove leading spaces
    while(temp.size() > 0)
    {
        if(isspace(temp.at(0))==true)
            temp.erase(0, 1);
        else
            break;
    }
    
    return temp;
}

void Utilities::setDelimiter(const char c)
{
    delimiter = c;
}

void Utilities::setLogFile(const char* filename)
{
    logFile.open(filename, std::ofstream::out | std::ofstream::app);
}
std::ofstream& Utilities::getLogFile()
{
    return logFile;
}
