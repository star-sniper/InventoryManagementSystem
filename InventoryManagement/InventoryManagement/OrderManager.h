/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/22
 Deliverable: MS3
 */
#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <iostream>
#include <vector>

class ItemManager;
class CustomerOrder;

class OrderManager : public std::vector<CustomerOrder> {
public:
    CustomerOrder&& extract();
    void validate(const ItemManager&, std::ostream&);
    void display(std::ostream&) const;
};
#endif
