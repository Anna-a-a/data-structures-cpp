/*
 * CircularQueue.cpp
 * Реализация циклической очереди
 * 
 * Изменения:
 * 1. Выделен в отдельный файл из 2Task03.cpp
 * 2. Сохранены все комментарии и документация
 * 3. Добавлены необходимые включения
 * 
 * Причины изменений:
 * - Разделение интерфейса и реализации
 * - Улучшение организации кода
 * - Упрощение поддержки
 */

#include "CircularQueue.h"

CircularQueue::CircularQueue(int size) : size(size), front(-1), rear(-1) {
    data = new int[size];
}

CircularQueue::~CircularQueue() {
    delete[] data;
}

bool CircularQueue::isEmpty() const {
    return front == -1;
}

bool CircularQueue::isFull() const {
    return (rear + 1) % size == front;
}

void CircularQueue::enqueue(int value) {
    if (isFull()) {
        std::cout << "Очередь переполнена!" << std::endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    data[rear] = value;
}

void CircularQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Очередь пуста!" << std::endl;
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void CircularQueue::print() const {
    if (isEmpty()) {
        std::cout << "Очередь пуста" << std::endl;
        return;
    }

    std::cout << "Элементы очереди: ";
    int i = front;
    do {
        std::cout << data[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    std::cout << std::endl;
}

void CircularQueue::printPointers() const {
    std::cout << "Размер очереди: " << size << std::endl;
    std::cout << "Указатель front: " << front << std::endl;
    std::cout << "Указатель rear: " << rear << std::endl;
}

int CircularQueue::getFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Очередь пуста");
    }
    return data[front];
}

int CircularQueue::getRear() const {
    if (isEmpty()) {
        throw std::runtime_error("Очередь пуста");
    }
    return data[rear];
} 