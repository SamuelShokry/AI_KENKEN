#include "backtracking.h"


bool Backtracking::check_constraints(int cellIndex)
{
    int gridSize = variables->get_grid_size();
    int row = cellIndex / gridSize;
    int col = cellIndex % gridSize;

    cell * const cellsPtr = variables->get_cells_ptr();
    const int currentCellValue = cellsPtr[cellIndex].get_cell_value();

    //CheckCages
    int cageNum = cellsPtr[cellIndex].get_cage_index();
    if(!(variables->get_cages_ptr()[cageNum].cheak_cage()))
        return false;

    //Row_Checking
    int desiredCell = (row * gridSize); // first cell in the current row;
    for(int i=0; i<gridSize; i++)
    {
        if(desiredCell == cellIndex)
        {
        	desiredCell += 1;
            continue;
        }
        if(currentCellValue == cellsPtr[desiredCell].get_cell_value())
        {
            return false;
        }
        desiredCell += 1;
    }

    //Coulmn_Checking
    desiredCell = col; // first cell in the current column;
    for(int i=0; i<gridSize; i++)
    {
        if(desiredCell == cellIndex)
        {
            desiredCell += gridSize;
            continue;
        }
        if(currentCellValue == cellsPtr[desiredCell].get_cell_value())
        {
            return false;
        }
        desiredCell += gridSize;
    }

    return true;
}


