/*
 * DoublyLinkedList.h
 * Заголовочный файл для реализации двусвязного списка
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

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Common.h"
#include <cstddef>

class Node {
public:
    int value;
    Node* prev;
    Node* next;
    Node(int val, Node* p = nullptr, Node* n = nullptr);
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    bool isEmpty() const;
    size_t getSize() const;
    void clear();
    void append(int value);
    void insert(size_t index, int value);
    void remove(size_t index);
    Node* getNodeAt(size_t index) const;
    void print() const;
    Node* findMinNode() const;
    Node* findMaxNode() const;
    bool isBefore(const Node* node1, const Node* node2) const;
    void printBetweenMinMax();
};

#endif // DOUBLY_LINKED_LIST_H 