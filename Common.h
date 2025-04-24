/*
 * Common.h
 * Общий заголовочный файл для всех структур данных
 * 
 * Изменения:
 * 1. Вынесены общие включения заголовочных файлов
 * 2. Добавлена функция safeInputInt для безопасного ввода
 * 3. Определены общие типы и константы
 * 
 * Причины изменений:
 * - Уменьшение дублирования кода
 * - Централизация общих компонентов
 * - Упрощение поддержки кода
 */

#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

// Безопасный ввод целого числа с обработкой ошибок
int safeInputInt(const std::string& prompt);

#endif // COMMON_H 