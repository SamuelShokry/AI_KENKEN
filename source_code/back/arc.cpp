bool Arc::remove_inconsistant_values(std::vector <int>* firstDomain, std::vector <int>* secondDomain)
{
    bool result = false;
    bool foundedFlag = false;

    auto iter1 = firstDomain->begin();
    auto begin2 = secondDomain->begin();

    auto end1 = firstDomain->end();
    auto end2 = secondDomain->end();

    std::vector <int> changedVector;
    changedVector.reserve(firstDomain->size()<<1);

    switch(this->constraintChar)
    {
    case' ':
        for(; iter1 != end1; ++iter1)
        {
            if((*iter1) == constraintValue)
            {
                changedVector.push_back((*iter1));
            }
            else
            {
                result = true;
            }
        }
        break;
    case '!':
        for(; iter1 != end1; ++iter1)
        {
            for(auto iter2 = begin2; iter2 != end2; ++iter2)
            {
                if((*iter1) != (*iter2))
                {
                    foundedFlag = true;
                    break;
                }
            }
            if(foundedFlag)
            {
                changedVector.push_back((*iter1));
                foundedFlag = false;
            }
            else
            {
                result = true;
            }
        }
        break;
    case '+':
        for(; iter1 != end1; ++iter1)
        {
            for(auto iter2 = begin2; iter2 != end2; ++iter2)
            {
                if((*iter1) + (*iter2) <= constraintValue)
                {
                    foundedFlag = true;
                    break;
                }
            }
            if(foundedFlag)
            {
                changedVector.push_back((*iter1));
                foundedFlag = false;
            }
            else
            {
                result = true;
            }
        }
        break;
    case '*':
        for(; iter1 != end1; ++iter1)
        {
            for(auto iter2 = begin2; iter2 != end2; ++iter2)
            {
                if((*iter1) * (*iter2) <= constraintValue)
                {
                    foundedFlag = true;
                    break;
                }
            }
            if(foundedFlag)
            {
                changedVector.push_back((*iter1));
                foundedFlag = false;
            }
            else
            {
                result = true;
            }
        }
        break;
    case '-':
        for(; iter1 != end1; ++iter1)
        {
            for(auto iter2 = begin2; iter2 != end2; ++iter2)
            {
                if(std::abs((*iter1) - (*iter2)) == constraintValue)
                {
                    foundedFlag = true;
                    break;
                }
            }
            if(foundedFlag)
            {
                changedVector.push_back((*iter1));
                foundedFlag = false;
            }
            else
            {
                result = true;
            }
        }
        break;
    case '/':
        for(; iter1 != end1; ++iter1)
        {
            for(auto iter2 = begin2; iter2 != end2; ++iter2)
            {
                int minValue = std::min((*iter1), (*iter2));
                int maxValue = std::max((*iter1), (*iter2));
                if((maxValue/minValue) == constraintValue && (maxValue % minValue) == 0)
                {
                    foundedFlag = true;
                    break;
                }
            }
            if(foundedFlag)
            {
                changedVector.push_back((*iter1));
                foundedFlag = false;
            }
            else
            {
                result = true;
            }
        }
        break;
    }

    if(result)
    {
        (*firstDomain) = changedVector;
    }

    return result;
}
