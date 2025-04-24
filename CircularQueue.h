/*
 * CircularQueue.h
 * Заголовочный файл для реализации циклической очереди
 * 
 * Изменения:
 * 1. Выделен в отдельный файл из DataStructures.h
 * 2. Добавлены необходимые включения
 * 3. Сохранены все комментарии и документация
 * 
 * Причины изменений:
 * - Улучшение организации кода
 * - Упрощение поддержки
 * - Изоляция компонентов
 */

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "Common.h"

class CircularQueue {
private:
    int* data;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int size);
    ~CircularQueue();
    
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(int value);
    void dequeue();
    void print() const;
    void printPointers() const;
    int getFront() const;
    int getRear() const;
};

#endif // CIRCULAR_QUEUE_H 