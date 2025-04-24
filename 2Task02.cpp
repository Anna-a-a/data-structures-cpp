/*
 * Улучшенная версия Task02.cpp
 * Основные улучшения:
 * 1. Добавлен деструктор для автоматической очистки памяти
 * 2. Улучшена обработка ошибок ввода с помощью функции safeInputInt
 * 3. Добавлены методы front() и back() для доступа к элементам
 * 4. Все методы класса сделаны константными где это возможно
 * 5. Улучшена структура кода и именование (более понятные английские названия)
 * 6. Добавлена обработка исключений
 * 7. Код разделен на заголовочный файл и файл реализации
 * 8. Улучшена читаемость кода и документация
 */

#include "DataStructures.h"
#include <limits>

using namespace std;

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (head != nullptr) {
        QueueNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::enqueue(int num) {
    QueueNode* newNode = new QueueNode{num, nullptr};

    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return;
    }

    QueueNode* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) tail = nullptr;
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

void Queue::print() const {
    QueueNode* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void Queue::printPointers() const {
    cout << "Адрес начала: " << head;
    if (head != nullptr) cout << " (значение: " << head->value << ")";
    cout << endl;

    cout << "Адрес конца:  " << tail;
    if (tail != nullptr) cout << " (значение: " << tail->value << ")";
    cout << endl;
}

int Queue::front() const {
    if (isEmpty()) {
        throw runtime_error("Очередь пуста");
    }
    return head->value;
}

int Queue::back() const {
    if (isEmpty()) {
        throw runtime_error("Очередь пуста");
    }
    return tail->value;
}

int safeInputInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Пожалуйста, введите целое число.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return value;
}

int main() {
    cout << "Программа разделения 10 чисел на две очереди (чётные и нечётные позиции)\n\n";

    Queue oddQueue;  
    Queue evenQueue; 
    cout << "Введите 10 чисел:\n";
    for (int i = 1; i <= 10; i++) {
        string prompt = "Число " + to_string(i) + ": ";
        int num = safeInputInt(prompt);

        if (i % 2 != 0) {
            oddQueue.enqueue(num);
        } else {
            evenQueue.enqueue(num);
        }
    }

    cout << "\nОчередь с нечётными номерами (1, 3, 5, 7, 9):\n";
    oddQueue.print();
    oddQueue.printPointers();

    cout << "\nОчередь с чётными номерами (2, 4, 6, 8, 10):\n";
    evenQueue.print();
    evenQueue.printPointers();

    return 0;
}