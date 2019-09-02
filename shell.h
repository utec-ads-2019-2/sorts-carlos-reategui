#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            int i, j, gap, temp;
            gap = size/2;
            while(gap > 0) {
                i = gap;
                while(i < size) {
                    temp = elements[i];
                    for(j = i; (j >= gap) && (elements[j - gap] > temp); j -=gap) {
                        elements[j] = elements[j - gap];
                    }
                    elements[j] = temp;
                    i++;
                }
                gap = gap / 2;
            }
        }

        inline string name() { return "ShellSort"; }
};

#endif