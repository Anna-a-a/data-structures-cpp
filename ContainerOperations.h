/*
 * ContainerOperations.h
 * Заголовочный файл для операций с контейнерами
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

#ifndef CONTAINER_OPERATIONS_H
#define CONTAINER_OPERATIONS_H

#include "Common.h"
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>

template <typename Container>
void fillContainer(Container& container, int size);

template <typename Container>
void printContainer(const Container& container);

template <typename Container>
void printReverse(const Container& container);

template <typename Container>
void swapMiddleElements(Container& container);

#endif // CONTAINER_OPERATIONS_H 