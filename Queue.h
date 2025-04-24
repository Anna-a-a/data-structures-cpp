/*
 * Queue.h
 * Заголовочный файл для реализации очереди
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

#ifndef QUEUE_H
#define QUEUE_H

#include "Common.h"

struct QueueNode {
    int value;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* head;
    QueueNode* tail;

public:
    Queue();
    ~Queue();
    
    void enqueue(int num);
    void dequeue();
    bool isEmpty() const;
    void print() const;
    void printPointers() const;
    int front() const;
    int back() const;
};

#endif // QUEUE_H 