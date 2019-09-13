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
#include "Item.h"
#include "Task.h"
#include "ItemManager.h"
#include "TaskManager.h"


void TaskManager::validate(std::ostream& os)
{
    size_t vec_size = this->size();
    bool valid = true;
    
    for (unsigned i = 0u; i < vec_size && valid; i++)
    {
        bool invalid = true;
        for (unsigned j = 0u; j < vec_size && invalid; j++)
        {
            if (this->at(i).validate(this->at(j)))
                invalid = false;
        }
        valid = !invalid;
    }
    if (!valid)
        std::cerr << "*** Not all Tasks have been validated ***\n";
    
}
void TaskManager::validate(const ItemManager& itemM, std::ostream& os)
{
    std::vector<Item>::const_iterator i = itemM.cbegin();
    for (; i != itemM.cend(); i++){

        auto lamda_vaildate1 = [&](const Task& T)
        {
            return !T.getName().compare(i->getRemover());
        };
        
        auto lamda_vaildate2 = [&](const Task& T)
        {
            return !T.getName().compare(i->getFiller());
        };
        
        if (std::find_if(this->cbegin(), this->cend(), lamda_vaildate1) == this->cend())
        {
            os << i->getRemover() << " is not available"<< std::endl;
        }
        
        if (std::find_if(this->cbegin(), this->cend(), lamda_vaildate2) == this->cend())
        {
            os << i->getFiller() << " is not available"<< std::endl;
        }
    }
}
void TaskManager::display(std::ostream& os) const
{
    std::vector<Task>::const_iterator iter = this->cbegin();
  
    for (; iter != this->cend(); iter++)
        iter->display(os);
    
}
