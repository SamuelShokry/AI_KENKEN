#ifndef ARC_H
#define ARC_H

#include "cell.h"

class Arc
{
private:
    int firstCell;
    int secondCell;
    char constraintChar;
    int  constraintValue;

public:
    void set_arc(int cell1, int cell2, char c, int value);

    int get_first_cell(void);

    int get_second_cell(void);
};

#endif // ARC_H
