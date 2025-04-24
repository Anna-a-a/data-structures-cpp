/*
 * Common.cpp
 * Реализация общих функций
 * 
 * Изменения:
 * 1. Реализована функция safeInputInt
 * 2. Добавлена обработка ошибок ввода
 * 
 * Причины изменений:
 * - Централизация общей функциональности
 * - Единая точка изменения логики ввода
 */

#include "Common.h"

int safeInputInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Пожалуйста, введите целое число.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return value;
} 