#ifndef BACKTRACKINGFCHAC_H
#define BACKTRACKINGFCHAC_H

#include "kenken.h"
#include "arc.h"

class BacktrackingFCHAC
{
private:
    std::queue <Arc> q;
    std::vector <std::vector <int>> Domains;
    std::vector <std::vector <Arc>> arcsPerCell;
    std::vector <std::vector<bool>> arcsFlag;
};

#endif // BACKTRACKINGFCHAC_H
