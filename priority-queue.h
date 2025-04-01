#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>

using namespace std;

template <typename T, typename Container = vector<T>>
class priority_queue {
private:
    Container data;

    void heapify_up(size_t index) {
        while (index > 0) {
            size_t parent = (index - 1) / 2;
            if (data[parent] >= data[index]) break;
            swap(data[parent], data[index]);
            index = parent;
        }
    }

    void heapify_down(size_t index) {
        size_t size = data.size();
        while (2 * index + 1 < size) {
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;
            size_t largest = left;
            if (right < size && data[right] > data[left])
                largest = right;
            if (data[index] >= data[largest]) break;
            swap(data[index], data[largest]);
            index = largest;
        }
    }

    

public:
    priority_queue() = default;
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
    const T& top() const { return data.front(); }
    
    void push(const T& value) {
        data.push_back(value);
        heapify_up(data.size() - 1);
    }
    
    void print_heap() const {
        for (const auto& element : data) {
            cout << element << " ";
        }
        cout << endl;
    }

    void pop() {
        if (data.empty()) return;
        swap(data.front(), data.back());
        data.pop_back();
        if (!data.empty()) heapify_down(0);
    }
};

#endif // PRIORITY_QUEUE_H