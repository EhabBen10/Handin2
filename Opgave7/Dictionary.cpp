#include "Dictionary.h"

bool Dictionary::insert(pair<int, string> p)
{
    if (!contains(p))
    {
        d.push_back(p);
        return true;
    }
    else
    {
        return false;
    }
}

void Dictionary::remove(pair<int, string> p)
{
    for (auto it = d.begin(); it != d.end(); ++it)
    {
        if (it->first == p.first)
        {
            d.erase(it);
            return;
        }
    }
}

bool Dictionary::contains(pair<int, string> p)
{
    for (auto it = d.begin(); it != d.end(); it++)
    {
        if (it->first == p.first)
        {
            return true;
        }
    }
    return false;
}
