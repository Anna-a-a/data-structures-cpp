/*
 * DoublyLinkedList.cpp
 * Реализация двусвязного списка
 * 
 * Изменения:
 * 1. Выделен в отдельный файл из 2Task04.cpp
 * 2. Сохранены все комментарии и документация
 * 3. Добавлены необходимые включения
 * 
 * Причины изменений:
 * - Разделение интерфейса и реализации
 * - Улучшение организации кода
 * - Упрощение поддержки
 */

#include "DoublyLinkedList.h"

Node::Node(int val, Node* p, Node* n) : value(val), prev(p), next(n) {}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

size_t DoublyLinkedList::getSize() const {
    return size;
}

void DoublyLinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}

void DoublyLinkedList::append(int value) {
    Node* newNode = new Node(value, tail, nullptr);
    
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::insert(size_t index, int value) {
    if (index > size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    
    if (index == 0) {
        Node* newNode = new Node(value, nullptr, head);
        if (head) head->prev = newNode;
        head = newNode;
        if (!tail) tail = newNode;
    } else if (index == size) {
        append(value);
        return;
    } else {
        Node* current = getNodeAt(index);
        Node* newNode = new Node(value, current->prev, current);
        current->prev->next = newNode;
        current->prev = newNode;
    }
    size++;
}

void DoublyLinkedList::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    
    Node* toDelete = getNodeAt(index);
    
    if (toDelete->prev) {
        toDelete->prev->next = toDelete->next;
    } else {
        head = toDelete->next;
    }
    
    if (toDelete->next) {
        toDelete->next->prev = toDelete->prev;
    } else {
        tail = toDelete->prev;
    }
    
    delete toDelete;
    size--;
}

Node* DoublyLinkedList::getNodeAt(size_t index) const {
    if (index >= size) return nullptr;
    
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

void DoublyLinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* DoublyLinkedList::findMinNode() const {
    if (isEmpty()) return nullptr;
    
    Node* minNode = head;
    Node* current = head->next;
    
    while (current != nullptr) {
        if (current->value < minNode->value) {
            minNode = current;
        }
        current = current->next;
    }
    return minNode;
}

Node* DoublyLinkedList::findMaxNode() const {
    if (isEmpty()) return nullptr;
    
    Node* maxNode = head;
    Node* current = head->next;
    
    while (current != nullptr) {
        if (current->value > maxNode->value) {
            maxNode = current;
        }
        current = current->next;
    }
    return maxNode;
}

bool DoublyLinkedList::isBefore(const Node* node1, const Node* node2) const {
    Node* current = head;
    while (current != nullptr) {
        if (current == node1) return true;
        if (current == node2) return false;
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::printBetweenMinMax() {
    Node* minNode = findMinNode();
    Node* maxNode = findMaxNode();
    
    if (!minNode || !maxNode || minNode == maxNode) {
        std::cout << "Нет элементов для вывода!" << std::endl;
        return;
    }
    
    const Node* start = isBefore(minNode, maxNode) ? minNode : maxNode;
    const Node* end = (start == minNode) ? maxNode : minNode;
    
    std::cout << "Элементы между " << start->value << " и " << end->value << ": ";
    bool elementsExist = false;
    
    for (const Node* current = start->next; current && current != end; current = current->next) {
        std::cout << current->value << " ";
        elementsExist = true;
    }
    
    if (!elementsExist) {
        std::cout << "отсутствуют";
    }
    std::cout << std::endl;
} 