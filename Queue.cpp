/*
 * Queue.cpp
 * Реализация очереди
 * 
 * Изменения:
 * 1. Выделен в отдельный файл из 2Task02.cpp
 * 2. Сохранены все комментарии и документация
 * 3. Добавлены необходимые включения
 * 
 * Причины изменений:
 * - Разделение интерфейса и реализации
 * - Улучшение организации кода
 * - Упрощение поддержки
 */

#include "Queue.h"

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
        std::cout << "Очередь пуста!" << std::endl;
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
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Queue::printPointers() const {
    std::cout << "Адрес начала: " << head;
    if (head != nullptr) std::cout << " (значение: " << head->value << ")";
    std::cout << std::endl;

    std::cout << "Адрес конца:  " << tail;
    if (tail != nullptr) std::cout << " (значение: " << tail->value << ")";
    std::cout << std::endl;
}

int Queue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Очередь пуста");
    }
    return head->value;
}

int Queue::back() const {
    if (isEmpty()) {
        throw std::runtime_error("Очередь пуста");
    }
    return tail->value;
} 