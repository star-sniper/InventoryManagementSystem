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
#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "CustomerItem.h"
#include "Item.h"

size_t CustomerOrder::field_width = 1;
CustomerOrder::CustomerOrder(const std::string& rec)
{
    nOrders=0;
    order = nullptr;

    Utilities u;
    u.setFieldWidth(field_width);
    size_t pos = 0;
    bool more = true;
    std::vector<std::string> temp_token;
    
    name = u.nextToken(rec, pos, more);
    
    if (!name.empty())
    {
        if (more)
        {
            product = u.nextToken(rec, pos, more);
            while (more)
            {
                std::string temp = u.nextToken(rec, pos, more);
                if (!temp.empty())
                    temp_token.push_back(std::move(temp));
            }
            nOrders = temp_token.size();
            order = new CustomerItem[nOrders];
            for(std::vector<int>::size_type i=0; i<nOrders; i++) {
                order[i] = CustomerItem(temp_token[i]);
            }
            
            field_width = u.getFieldWidth();
            }
        }
    else
    {
        std::string err = rec + "<-- *** no token found before the delimiter ***";
        throw err;
    }
    field_width = u.getFieldWidth();

}

CustomerOrder::CustomerOrder(const CustomerOrder& CO)
{
    std::string err = "Copy constructor shouldn't be called";
    throw err;
}

CustomerOrder::CustomerOrder(CustomerOrder&& CO) /* NOEXCEPT OSX */ : order (nullptr)
{
    *this = std::move(CO);
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& CO) /* NOEXCEPT OSX */ 
{
    if(this!=&CO)
    {
        if(order)
        {
            delete[] order;
            order = nullptr;
            nOrders = 0;
        }
        
        name = CO.name;
        product = CO.product;
        nOrders = CO.nOrders;
        order = CO.order;
        
        CO.name.clear();
        CO.product.clear();
        CO.nOrders = 0;
        CO.order = nullptr;
    }
    
    return std::move(*this);
}

CustomerOrder::~CustomerOrder()
{
    if(order)
    {
        delete[] order;
        order = nullptr;
    }
}
bool CustomerOrder::empty() const
{
    return name.empty();
}

unsigned int CustomerOrder::noOrders() const
{
    return nOrders;
}

const std::string& CustomerOrder::operator[](unsigned int i) const
{
    if (i >= nOrders)
    {
        std::string errmsg = "Index out of bounds exception";
        throw errmsg;
    }
    return order[i].getName();
}

void CustomerOrder::fill(Item& item)
{
    for (unsigned int i = 0; i < nOrders; i++)
    {
        if(order[i].getName()==item.getName())
        {
            order[i].fill(item.getCode());
            item++;
        }
    }
}

void CustomerOrder::remove(Item& item)
{
    for(unsigned int i=0; i<nOrders; i++)
    {
        if(order[i].getName()==item.getName())
            order[i].clear();
    }
}

void CustomerOrder::display(std::ostream& os) const
{
    os << std::left << std::setw(field_width) << name
    << " : " << std::setw(field_width) << product << std::endl;
    for (unsigned int i = 0; i < nOrders; i++)
        order[i].display(os);
}
