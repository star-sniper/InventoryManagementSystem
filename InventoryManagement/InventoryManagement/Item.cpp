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
#include "Item.h"
#include "Utilities.h"

size_t Item::field_width = 0;
Item::Item(const std::string& rec)
{
	code=1;
	description = "no detailed description";

	Utilities u;
	u.setFieldWidth(field_width);

	size_t pos = 0;
	bool more = true;
	name = u.nextToken(rec, pos, more);
	field_width = u.getFieldWidth();

	if (!name.empty())
{
		if (more)
{
			filler = u.nextToken(rec, pos, more);
			if (more)
{
				remover = u.nextToken(rec, pos, more);
				if (more)
{
					code = (unsigned int)atoi(u.nextToken(rec, pos, more).data());
					if (more)
						description = u.nextToken(rec, pos, more);
				}
			}
		}
	}
	else
{
		std::string err = rec + "<-- *** no token found before the delimiter ***";
		throw err;
	}

	
}
bool Item::empty() const
{
    return name.empty();
}
Item& Item::operator++(int)
{
    code++;
    return *this;
}

const std::string& Item::getName() const
{
    return name;
}
const std::string& Item::getFiller() const
{
    return filler;
}
const std::string& Item::getRemover() const
{
    return remover;
}

unsigned int Item::getCode() const
{
    return code;
}

void Item::display(std::ostream& os, bool full) const
{
    os << std::left << std::setw(field_width) << name
    << " [" << std::right << std::setw(CODE_WIDTH) << std::setfill('0') << code << "]"
    << std::left << std::setfill(' ');
    
    if (full)
    {
        os << " From " << std::setw(field_width) << filler;
        os << " To " << std::setw(field_width) << remover << std::endl;
        os << std::right << std::setw(field_width + CODE_WIDTH + 4) << " : " << description;
    }
    os << std::left << std::endl;
}
