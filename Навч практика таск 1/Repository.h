#pragma once

#include <vector>

template <class T>
class Repository {
protected:
    vector<T> clothes;
    vector<T> ordered;
public:
    virtual void AddItem(T& item) = 0;
    virtual void RemoveItem(int index) = 0;
    virtual void RemoveAll() = 0;

    virtual void PrintItems() = 0;

    virtual void GetTotal() = 0;
};
