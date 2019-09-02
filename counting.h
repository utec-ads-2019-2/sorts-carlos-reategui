#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            int max = *max_element(elements, elements + size), countingSort[size], count[max + 1];
            for (unsigned int i = 0; i < max + 1; i++) count[i] = 0;
            for (unsigned int i = 0; i < size; i++) count[elements[i]]++;
            for (unsigned int i = 1; i <= max; i++) count[i] += count[i - 1];
            for (unsigned int i = 0; i < size; i++){
                countingSort[count[elements[i]] - 1] = elements[i];
                count[elements[i]]--;
            }
            for (unsigned int i = 0; i < size; i++) elements[i] = countingSort[i];
        }

        inline string name() { return "CountingSort"; }
};

#endif