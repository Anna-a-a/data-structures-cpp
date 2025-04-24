/*
 * Улучшенная версия Task01.cpp
 * Основные улучшения:
 * 1. Добавлен деструктор для автоматической очистки памяти
 * 2. Улучшена обработка ошибок (pop теперь возвращает bool)
 * 3. Добавлен метод isEmpty() для проверки состояния стека
 * 4. Методы print() и getTop() сделаны константными
 * 5. Улучшен пользовательский интерфейс с более информативными сообщениями
 * 6. Добавлена поддержка русского языка
 * 7. Код разделен на заголовочный файл и файл реализации
 * 8. Улучшена структура кода и именование (более последовательное)
 */

#include "DataStructures.h"
#include <memory>

using namespace std;

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
        cout << "Стек пуст!" << endl;
        return;
    }
    
    cout << "Содержимое стека (вершина слева): ";
    StackNode* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void addAndPrintAddress(Stack& stack, int value) {
    StackNode* newTop = stack.push(value);
    cout << "Элемент " << value << " добавлен. Адрес новой вершины: " << newTop << endl;
}

void userInterface(Stack& stack) {
    int choice, value;
    
    while (true) {
        cout << "\nМеню управления стеком:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Показать содержимое\n";
        cout << "4. Очистить стек\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введите значение элемента: ";
                cin >> value;
                addAndPrintAddress(stack, value);
                break;
            case 2:
                if (stack.pop()) {
                    cout << "Элемент удален. ";
                    if (stack.getTop()) {
                        cout << "Новая вершина: " << stack.getTop() << endl;
                    } else {
                        cout << "Стек теперь пуст." << endl;
                    }
                } else {
                    cout << "Ошибка: стек пуст!" << endl;
                }
                break;
            case 3:
                stack.print();
                break;
            case 4:
                stack.clear();
                cout << "Стек очищен." << endl;
                break;
            case 5:
                cout << "Завершение работы." << endl;
                return;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    Stack myStack;
    userInterface(myStack);
    
    return 0;
}