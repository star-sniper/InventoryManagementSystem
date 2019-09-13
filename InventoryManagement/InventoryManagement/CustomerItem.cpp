/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/15
 Deliverable: MS2
 */
#include <iomanip>
#include "CustomerItem.h"
#include "Item.h"


CustomerItem::CustomerItem(const std::string& c_name)
{
    name = c_name;
    code=0;
    filled= false;
    
}
bool CustomerItem::asksFor(const Item& Item) const
{
    return false;
}
bool CustomerItem::isFilled() const
{
    return filled;
}
void CustomerItem::fill(const unsigned int c)
{
    code = c;
    filled = true;
}
void CustomerItem::clear()
{
    code = 0;
    filled = false;
}
const std::string& CustomerItem::getName() const
{
    return name;
}
void CustomerItem::display(std::ostream& os) const
{
    char cSign ='-';
    if (filled)
        cSign = '+';
    
    if (!name.empty())
    {
        os << " " << cSign << " [" << std::right << std::setw(CODE_WIDTH)
        << std::setfill('0') << code << std::setfill(' ') << "] "
        << name << std::endl;
    }
}
