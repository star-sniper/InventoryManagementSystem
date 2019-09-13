/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/22
 Deliverable: MS3
 */

#include <algorithm>
#include "OrderManager.h"
#include "CustomerOrder.h"
#include "ItemManager.h"
#include "Item.h"

CustomerOrder&& OrderManager::extract()
{
    return std::move(*this->end());
}
void OrderManager::validate(const ItemManager& itemManager, std::ostream& os)
{
    std::vector<CustomerOrder>::iterator iter = this->begin();
  
    for (; iter != this->end(); iter++)
    {
        for (unsigned i = 0; i < iter->noOrders(); i++)
        {
            auto lamda_vaildate = [&](const Item& item)
            {
                return !item.getName().compare((*iter)[i]);
            };
            
            if (std::find_if(itemManager.cbegin(), itemManager.cend(), lamda_vaildate) == itemManager.cend())
                os << (*iter)[i] << " is unavailable " << std::endl;
            
        }
    }
}

void OrderManager::display(std::ostream& os) const
{
    std::vector<CustomerOrder>::const_iterator iter = this->cbegin();
    for (; iter != this->cend(); iter++){
        iter->display(os);
    }
    
}
