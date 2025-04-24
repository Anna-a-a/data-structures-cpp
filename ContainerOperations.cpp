/*
 * ContainerOperations.cpp
 * Реализация операций с контейнерами
 * 
 * Изменения:
 * 1. Выделен в отдельный файл из 2Task05.cpp
 * 2. Сохранены все комментарии и документация
 * 3. Добавлены необходимые включения
 * 
 * Причины изменений:
 * - Разделение интерфейса и реализации
 * - Улучшение организации кода
 * - Упрощение поддержки
 */

#include "ContainerOperations.h"
#include <iostream>
#include <random>
#include <chrono>

template <typename Container>
void fillContainer(Container& container, int size) {
    // Инициализация генератора случайных чисел
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 100);
    
    // Заполнение контейнера случайными числами
    for (int i = 0; i < size; ++i) {
        container.push_back(distribution(generator));
    }
}

template <typename Container>
void printContainer(const Container& container) {
    std::cout << "Элементы контейнера: ";
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void printReverse(const Container& container) {
    std::cout << "Элементы в обратном порядке: ";
    for (auto it = container.rbegin(); it != container.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void swapMiddleElements(Container& container) {
    if (container.size() < 2) {
        std::cout << "Контейнер слишком мал для обмена элементов" << std::endl;
        return;
    }
    
    size_t middle = container.size() / 2;
    auto first = std::next(container.begin(), middle - 1);
    auto second = std::next(container.begin(), middle);
    
    std::iter_swap(first, second);
    std::cout << "Элементы после обмена: ";
    printContainer(container);
}

// Явное инстанцирование шаблонов для используемых типов
template void fillContainer(std::vector<int>&, int);
template void fillContainer(std::deque<int>&, int);
template void fillContainer(std::list<int>&, int);

template void printContainer(const std::vector<int>&);
template void printContainer(const std::deque<int>&);
template void printContainer(const std::list<int>&);

template void printReverse(const std::vector<int>&);
template void printReverse(const std::deque<int>&);
template void printReverse(const std::list<int>&);

template void swapMiddleElements(std::vector<int>&);
template void swapMiddleElements(std::deque<int>&);
template void swapMiddleElements(std::list<int>&); 