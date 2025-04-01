#include <iostream>
#include "priority-queue.h"

using namespace std;

void test_priority_queue() {
    priority_queue<int> pq;
    
    cout << "Тестирование пустой очереди...\n";
    cout << "Очередь пуста: " << (pq.empty() ? "Да" : "Нет") << "\n";
    cout << "Размер очереди: " << pq.size() << "\n";
    
    try {
        pq.top();
    } catch (const runtime_error& e) {
        cout << "Исключение при попытке доступа к top(): " << e.what() << "\n";
    }
    
    try {
        pq.pop();
    } catch (const runtime_error& e) {
        cout << "Исключение при попытке вызова pop(): " << e.what() << "\n";
    }
    
    cout << "Добавляем элементы: 10, 20, 5, 30, 25\n";
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(30);
    pq.push(25);

    cout << "Элементы в порядке кучи: ";
    pq.print_heap();
    
    cout << "Текущий размер очереди: " << pq.size() << "\n";
    cout << "Максимальный элемент: " << pq.top() << "\n";
    
    cout << "Извлечение элементов из очереди:\n";
    while (!pq.empty()) {
        cout << "top(): " << pq.top() << "\n";
        pq.pop();
    }
    
    cout << "Очередь пуста: " << (pq.empty() ? "Да" : "Нет") << "\n";
}

int main() {
    test_priority_queue();
    return 0;
}