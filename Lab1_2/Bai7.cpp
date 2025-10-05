#include <iostream>
#include <vector>

class CounterManager;

class Counter {
private:
    int id;                        
    static int objectCount;       

public:
    Counter() {
        id = ++objectCount;
    }
    ~Counter() {
        --objectCount;
    }

    int getId() const {
        return id;
    }

    static int getObjectCount() {
        return objectCount;
    }

    friend bool areEqual(const Counter& c1, const Counter& c2);

    friend class CounterManager;
};

int Counter::objectCount = 0;

bool areEqual(const Counter& c1, const Counter& c2) {
    return c1.id == c2.id;
}

class CounterManager {
public:
    std::vector<Counter*> counters;

    void addCounter(Counter* counter) {
        counters.push_back(counter);
    }

    void printCounters() const {
        std::cout << "Danh sach Counter dang duoc quan ly:\n";
        for (const Counter* counter : counters) {
            std::cout << "Counter ID: " << counter->id << std::endl;
        }
    }

    void printTotalCount() const {
        std::cout << "Tong so Counter objects: " << Counter::getObjectCount() << std::endl;
    }

    ~CounterManager() {
        for (Counter* counter : counters) {
            delete counter;
        }
    }
};

int main() {
    int n;
    std::cout << "Nhap so Counter muon tao: ";
    std::cin >> n;

    CounterManager manager;

    for (int i = 0; i < n; i++) {
        manager.addCounter(new Counter());
    }

    manager.printCounters();
    manager.printTotalCount();

    if (manager.counters.size() >= 2) {
        std::cout << "So sanh Counter 1 va Counter 2: "
                  << (areEqual(*manager.counters[0], *manager.counters[1]) ? "Bang nhau" : "Khong bang")
                  << std::endl;
        std::cout << "c1 ID: " << manager.counters[0]->getId()
                  << ", c2 ID: " << manager.counters[1]->getId() << std::endl;
    }

    return 0;
}
