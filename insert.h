#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            for (unsigned int i = 1; i < size; i++) {
                unsigned int j = i;
                while(j > 0 and elements[j - 1] > elements[j]) {
                    std::swap(elements[j - 1], elements[j]);
                    j--;
                }
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif