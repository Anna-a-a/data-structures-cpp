/*
 * Улучшенная версия Task04.cpp
 * Основные улучшения:
 * 1. Добавлен деструктор для автоматической очистки памяти
 * 2. Добавлен указатель на хвост списка для более эффективной работы
 * 3. Добавлен счетчик размера списка
 * 4. Добавлены методы для работы с индексом (insert, remove, getNodeAt)
 * 5. Улучшена обработка ошибок с использованием исключений
 * 6. Добавлена безопасная функция ввода safeInputInt
 * 7. Все методы класса сделаны константными где это возможно
 * 8. Код разделен на заголовочный файл и файл реализации
 * 9. Улучшена структура кода и именование (более понятные английские названия)
 * 10. Добавлена проверка на пустой список и граничные случаи
 */

#include "DataStructures.h"
#include <limits>
#include <stdexcept>

using namespace std;

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
        throw out_of_range("Индекс вне диапазона");
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
        throw out_of_range("Индекс вне диапазона");
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
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
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
        cout << "Нет элементов для вывода!" << endl;
        return;
    }
    
    const Node* start = isBefore(minNode, maxNode) ? minNode : maxNode;
    const Node* end = (start == minNode) ? maxNode : minNode;
    
    cout << "Элементы между " << start->value << " и " << end->value << ": ";
    bool elementsExist = false;
    
    for (const Node* current = start->next; current && current != end; current = current->next) {
        cout << current->value << " ";
        elementsExist = true;
    }
    
    if (!elementsExist) {
        cout << "отсутствуют";
    }
    cout << endl;
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
    try {
        DoublyLinkedList list;
        
        cout << "Программа вывода элементов между минимальным и максимальным значениями\n\n";
        
        int n = safeInputInt("Введите количество элементов: ");
        if (n <= 0) {
            throw invalid_argument("Количество элементов должно быть положительным числом");
        }
        
        cout << "Введите элементы списка:\n";
        for (int i = 0; i < n; ++i) {
            string prompt = "Элемент " + to_string(i + 1) + ": ";
            int value = safeInputInt(prompt);
            list.append(value);
        }
        
        cout << "\nСодержимое списка: ";
        list.print();
        
        cout << "\nРезультат:\n";
        list.printBetweenMinMax();
        
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}