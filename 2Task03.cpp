/*
 * Улучшенная версия Task03.cpp
 * Основные улучшения:
 * 1. Добавлен деструктор для автоматической очистки памяти
 * 2. Улучшена обработка ошибок ввода с помощью функции safeInputInt
 * 3. Добавлены методы front() и back() для доступа к элементам
 * 4. Все методы класса сделаны константными где это возможно
 * 5. Улучшена структура кода и именование (более понятные английские названия)
 * 6. Добавлена обработка исключений
 * 7. Код разделен на заголовочный файл и файл реализации
 * 8. Улучшена читаемость кода и документация
 */

#include "DataStructures.h"
#include <limits>

using namespace std;

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
        cout << "Очередь переполнена!" << endl;
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
        cout << "Очередь пуста!" << endl;
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
        cout << "Очередь пуста" << endl;
        return;
    }

    cout << "Элементы очереди: ";
    int i = front;
    do {
        cout << data[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
}

void CircularQueue::printPointers() const {
    cout << "Размер очереди: " << size << endl;
    cout << "Указатель front: " << front << endl;
    cout << "Указатель rear: " << rear << endl;
}

int CircularQueue::getFront() const {
    if (isEmpty()) {
        throw runtime_error("Очередь пуста");
    }
    return data[front];
}

int CircularQueue::getRear() const {
    if (isEmpty()) {
        throw runtime_error("Очередь пуста");
    }
    return data[rear];
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
    cout << "Программа работы с циклической очередью\n\n";

    int size = safeInputInt("Введите размер очереди: ");
    CircularQueue queue(size);

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Показать очередь\n";
        cout << "4. Показать указатели\n";
        cout << "5. Выход\n";
        
        int choice = safeInputInt("Выберите действие: ");

        switch (choice) {
            case 1: {
                int value = safeInputInt("Введите значение: ");
                queue.enqueue(value);
                break;
            }
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.print();
                break;
            case 4:
                queue.printPointers();
                break;
            case 5:
                cout << "Программа завершена.\n";
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}