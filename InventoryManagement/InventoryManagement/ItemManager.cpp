/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/22
 Deliverable: MS3
 */
#include "ItemManager.h"
#include "Item.h"
void ItemManager::display(std::ostream& os, bool full) const
{
    std::vector<Item>::const_iterator i = this->cbegin();
    for (; i != this->cend(); i++){
        i->display(os, full);
    }
}
