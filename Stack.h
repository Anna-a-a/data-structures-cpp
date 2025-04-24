/*
 * Stack.h
 * Заголовочный файл для реализации стека
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

#ifndef STACK_H
#define STACK_H

#include "Common.h"

struct StackNode {
    int data;
    StackNode* next;
    StackNode(int value);
};

class Stack {
private:
    StackNode* top;

public:
    Stack();
    ~Stack();
    
    StackNode* push(int value);
    bool pop();
    bool isEmpty() const;
    StackNode* getTop() const;
    void print() const;
    void clear();
    
    friend void addAndPrintAddress(Stack& stack, int value);
};

void addAndPrintAddress(Stack& stack, int value);
void userInterface(Stack& stack);

#endif // STACK_H 