#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        int partition(int low, int high) {
            int pivot = elements[high];
            int i = low - 1;
            for (unsigned int j = low; j <= high - 1; j++) {
                if (elements[j] < pivot) {
                    i++;
                    std::swap(elements[i], elements[j]);
                }
            }
            std::swap(elements[i + 1], elements[high]);
            return i + 1;
        }

        void sort(int low, int high) {
            if (low < high) {
                int partitionIndex = partition(low, high);
                sort(low, partitionIndex - 1);
                sort(partitionIndex + 1, high);
            }
        }

        void execute() override {
            sort(0, size - 1);
        }

        inline string name() { return "QuickSort"; }
};

#endif