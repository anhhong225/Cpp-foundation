#ifndef ASSIGNMENT5_TRACKER_H
#define ASSIGNMENT5_TRACKER_H

#include <cstring>

class Tracker {
public:
    Tracker():m_instance_count{0},m_memory_count{0}{}

    // increments `m_instance_count`
    void add_instance();
    // decrements `m_instance_count`
    void remove_instance();
    // adds memory to `m_memory_count`
    void add_memory(std::size_t memory);
    // subtracts memory
    void remove_memory(std::size_t memory);
    std::size_t memory() const;
    std::size_t instances() const;
private:
    std::size_t m_instance_count;
    std::size_t m_memory_count;
};

class Simple{
public:
    static  const Tracker& tracker();
    Simple(): Simple(0){}
    Simple(double n):m_number{n}{
        s_tracker.add_instance();
        s_tracker.add_memory(sizeof(Simple));
    }
// this destructor is not needed - it is there to hook a Tracker
    ~Simple(){
        s_tracker.remove_instance();
        s_tracker.remove_memory(sizeof(*this));
    }

    double number() const;
private:
    double m_number;
    static inline Tracker s_tracker{};
};

#endif //ASSIGNMENT5_TRACKER_H
