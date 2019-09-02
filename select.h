#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:



    void execute() override {
        int min;
        for (unsigned int i = 0; i < size - 1; i++) {
            min = i;
            for (unsigned int j = i + 1; j < size; j++)
                if (elements[j] < elements[min])
                    min = j;
            std::swap(elements[min], elements[i]);
        }
    }

        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        inline string name() { return "SelectSort"; }
};

#endif