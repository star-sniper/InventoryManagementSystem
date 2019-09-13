/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/22
 Deliverable: MS3
 */
#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H
#include <iostream>
#include <vector>

class Item;
class ItemManager : public std::vector<Item> 
{
public:
    void display(std::ostream&, bool = false) const;
};

#endif
