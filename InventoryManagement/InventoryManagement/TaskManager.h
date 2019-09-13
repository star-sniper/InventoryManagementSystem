/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/22
 Deliverable: MS3
 */

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include <iostream>
#include <vector>

class Task;
class ItemManager;

class TaskManager : public std::vector<Task> {
public:
    void validate(std::ostream&);
    void validate(const ItemManager&, std::ostream&);
    void display(std::ostream&) const;
};

#endif 
