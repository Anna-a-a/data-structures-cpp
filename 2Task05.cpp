/*
 * Улучшенная версия Task05.cpp
 * Основные улучшения:
 * 1. Использование generate_n и copy_n для более эффективного заполнения контейнеров
 * 2. Использование back_inserter для безопасного добавления элементов
 * 3. Использование iter_swap вместо ручной реализации обмена
 * 4. Добавлен метод printReverse для демонстрации обратных итераторов
 * 5. Улучшена обработка ошибок и валидация входных данных
 * 6. Код разделен на заголовочный файл и файл реализации
 * 7. Улучшена структура кода и именование (более понятные английские названия)
 * 8. Использование const для параметров, которые не изменяются
 * 9. Более эффективное использование итераторов и алгоритмов STL
 */

#include "DataStructures.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <ctime>

using namespace std;

template <typename Container>
void fillContainer(Container& container, int size) {
    int inputMethod;
    cout << "Выберите способ заполнения контейнера:\n"
         << "1) Ввод с клавиатуры\n"
         << "2) Случайная генерация\n"
         << "3) Чтение из файла\n";
    cin >> inputMethod;

    if (size < 2 || size % 2 != 0) {
        cout << "Ошибка: размер должен быть четным числом ≥ 2\n";
        return;
    }

    switch (inputMethod) {
        case 1: {
            cout << "Введите " << size << " элементов:\n";
            generate_n(back_inserter(container), size, []() {
                int value;
                cin >> value;
                return value;
            });
            break;
        }
        case 2: {
            srand(time(nullptr));
            generate_n(back_inserter(container), size, []() { return rand() % 101 - 50; });
            break;
        }
        case 3: {
            ifstream file("input.txt");
            if (!file) {
                cout << "Ошибка: не удалось открыть файл\n";
                return;
            }
            copy_n(istream_iterator<int>(file), size, back_inserter(container));
            break;
        }
        default:
            cout << "Ошибка: неверный выбор\n";
    }
}

template <typename Container>
void printContainer(const Container& container) {
    copy(container.begin(), container.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}

template <typename Container>
void printReverse(const Container& container) {
    copy(container.rbegin(), container.rend(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}

template <typename Container>
void swapMiddleElements(Container& container) {
    auto middle = container.begin();
    advance(middle, container.size() / 2 - 1);
    iter_swap(middle, next(middle));
}

int main() {
    int sizes[3];
    const char* containerNames[] = {"вектора", "дека", "списка"};
    
    for (int i = 0; i < 3; ++i) {
        cout << "Введите размер " << containerNames[i] << " (≥2, четный): ";
        cin >> sizes[i];
        if (sizes[i] < 2 || sizes[i] % 2 != 0) {
            cout << "Некорректный размер!\n";
            return 1;
        }
    }

    vector<int> vec;
    deque<int> deq;
    list<int> lst;

    fillContainer(vec, sizes[0]);
    fillContainer(deq, sizes[1]);
    fillContainer(lst, sizes[2]);

    cout << "\nИсходное содержимое:\n";
    cout << "Вектор:  "; printContainer(vec);
    cout << "Дек:     "; printContainer(deq);
    cout << "Список:  "; printContainer(lst);

    cout << "\nВ обратном порядке:\n";
    cout << "Вектор:  "; printReverse(vec);
    cout << "Дек:     "; printReverse(deq);
    cout << "Список:  "; printReverse(lst);

    swapMiddleElements(vec);
    swapMiddleElements(deq);
    swapMiddleElements(lst);

    cout << "\nПосле обмена средних элементов:\n";
    cout << "Вектор:  "; printContainer(vec);
    cout << "Дек:     "; printContainer(deq);
    cout << "Список:  "; printContainer(lst);

    return 0;
}