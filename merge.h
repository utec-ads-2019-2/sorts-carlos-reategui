#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}

        void sort(int low, int high){
            if (low < high) {
                int mid = (low + high) / 2;
                sort(low, mid);
                sort(mid + 1, high);
                sortElements(low, mid, mid + 1, high);
            }
        }

        void sortElements(int low1, int high1, int low2, int high2) {
            int low1cpy = low1, low2cpy = low2, tempIndex = low1, temp[size];
            while (low1cpy <= high1 and low2cpy <= high2) {
                if (elements[low1cpy] < elements[low2cpy])
                    temp[tempIndex++] = elements[low1cpy++];
                else
                    temp[tempIndex++] = elements[low2cpy++];
            }
            if (low1cpy > high1) {
                while (low2cpy <= high2)
                    temp[tempIndex++] = elements[low2cpy++];
            } else {
                while (low1cpy <= high1)
                    temp[tempIndex++] = elements[low1cpy++];
            }
            for (unsigned int i = low1; i <= high2; i++) elements[i] = temp[i];
        }

        void execute() override {
            sort(0, size - 1);
        }

        inline string name() { return "MergeSort"; }
};

#endif