#ifndef ASSIGNMENT5_DYNAMICARRAY_H
#define ASSIGNMENT5_DYNAMICARRAY_H

#include "Tracker.h"

class DynamicArray {
    const static int DEFAULT_CAP{16};
public:
    DynamicArray(int capacity):m_capacity{capacity? capacity:DEFAULT_CAP}
                               //m_size{0},
                               //m_array{new double[m_capacity]}
                               {
        m_tracker.add_instance();
        m_tracker.add_memory(m_capacity);
    }
    DynamicArray(): DynamicArray(DEFAULT_CAP){}
    ~DynamicArray(){
        m_tracker.remove_instance();
        m_tracker.remove_memory(m_capacity);
    }
    // accessors
//    double* get();
//    const double* get() const;
//    double& at(std::size_t index);//access the element by index
//    const double& at(std::size_t index) const;
//
//    int size() const;
//    int capacity() const;
    static Tracker tracker();

private:
    int m_capacity;
    //int m_size;
    //double* m_array;
    static inline Tracker m_tracker{};
};



#endif //ASSIGNMENT5_DYNAMICARRAY_H
