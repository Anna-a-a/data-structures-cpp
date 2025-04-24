/*
 * Stack.cpp
 * Реализация стека
 * 
 * Изменения:
 * 1. Выделен в отдельный файл из 2Task01.cpp
 * 2. Сохранены все комментарии и документация
 * 3. Добавлены необходимые включения
 * 
 * Причины изменений:
 * - Разделение интерфейса и реализации
 * - Улучшение организации кода
 * - Упрощение поддержки
 */

#include "Stack.h"

StackNode::StackNode(int value) : data(value), next(nullptr) {}

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    clear();
}

StackNode* Stack::push(int value) {
    StackNode* newNode = new StackNode(value);
    newNode->next = top;
    top = newNode;
    return top;
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }
    
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return true;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

StackNode* Stack::getTop() const {
    return top;
}

void Stack::print() const {
    if (isEmpty()) {
        std::cout << "Стек пуст!" << std::endl;
        return;
    }
    
    std::cout << "Содержимое стека (вершина слева): ";
    StackNode* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void addAndPrintAddress(Stack& stack, int value) {
    StackNode* newTop = stack.push(value);
    std::cout << "Элемент " << value << " добавлен. Адрес новой вершины: " << newTop << std::endl;
}

void userInterface(Stack& stack) {
    int choice, value;
    
    while (true) {
        std::cout << "\nМеню управления стеком:\n";
        std::cout << "1. Добавить элемент\n";
        std::cout << "2. Удалить элемент\n";
        std::cout << "3. Показать содержимое\n";
        std::cout << "4. Очистить стек\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите значение элемента: ";
                std::cin >> value;
                addAndPrintAddress(stack, value);
                break;
            case 2:
                if (stack.pop()) {
                    std::cout << "Элемент удален. ";
                    if (stack.getTop()) {
                        std::cout << "Новая вершина: " << stack.getTop() << std::endl;
                    } else {
                        std::cout << "Стек теперь пуст." << std::endl;
                    }
                } else {
                    std::cout << "Ошибка: стек пуст!" << std::endl;
                }
                break;
            case 3:
                stack.print();
                break;
            case 4:
                stack.clear();
                std::cout << "Стек очищен." << std::endl;
                break;
            case 5:
                std::cout << "Завершение работы." << std::endl;
                return;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
        }
    }
} 