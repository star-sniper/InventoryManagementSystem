/*
 Name:        Harshit Arora
 Section:     D
 Student ID:  132895160
 Email:       harora4@myseneca.ca
 Prof:        Cornel Barna
 Date:        2017/12/08
 Deliverable: MS1
 */
#include <iomanip>
#include "Task.h"
#include "Utilities.h"
size_t Task::field_width=1;

Task::Task(const std::string& rec)
{
    slots = "1";
    pNextTask[0] = pNextTask[1] = nullptr;
    
    Utilities u;
    u.setFieldWidth(field_width);
    
    size_t pos=0;
    bool next=true;
    
    name=u.nextToken(rec, pos, next);
    
    if(!name.empty())
    {
        if(next==true)
        {
            slots=u.nextToken(rec, pos, next);
            if(next)
            {
                nextTask[passed]=u.nextToken(rec, pos, next);
                if(next)
                {
                    nextTask[redirect]=u.nextToken(rec, pos, next);
                }
            }
        }
    }
    else
        throw "Couldn't parse file";
    
     field_width = u.getFieldWidth();
}

const std::string& Task::getName() const
{
    return name;
}

unsigned int Task::getSlots() const
{
    return std::stoi(slots);
}

bool Task::validate(const Task& task)
{
    if(task.name==nextTask[passed])
        pNextTask[passed] = &task;
    else if(task.name==nextTask[redirect])
        pNextTask[redirect] = &task;
    
    return (nextTask[passed].empty() || pNextTask[passed]) &&
    (nextTask[redirect].empty() || pNextTask[redirect]);
}

const Task* Task::getNextTask(Quality quantity) const
{
        if(pNextTask[quantity]==nullptr)
            throw "*** Validate [" + nextTask[quantity] + "] @ [" + name + "] ***";
        return
            pNextTask[quantity];
}

void Task::display(std::ostream& os) const {
    os << "Task Name    : " << std::left << std::setw(field_width + 3) <<
    "[" + name + "]" <<
    "[" << slots << "]" << std::endl;
    
    if(!nextTask[passed].empty()) {
        os << " Continue to : " << std::left << std::setw(field_width + 2) <<
        "[" + nextTask[passed] + "]";
        if(pNextTask[passed]==nullptr) os << " *** to be validated ***";
        os << std::endl;
    }
    
    if(!nextTask[redirect].empty()) {
        os << " Redirect to : " << std::left << std::setw(field_width + 2) <<
        "[" + nextTask[redirect] + "]";
        if(pNextTask[redirect]==nullptr) os << " *** to be validated ***";
        os << std::endl;
    }
}
bool operator==(const Task& task1, const Task& task2)
{
    return task1.getName()==task2.getName();
}

