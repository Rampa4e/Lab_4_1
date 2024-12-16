/**
 * @mainpage Шифрование методом Гронсвельда
 *
 * @section intro Введение
 * Программа реализует шифрование и расшифровку русскоязычных сообщений с использованием метода Гронсвельда.
 * Алгоритм основан на модифицированном шифре Альфа и поддерживает только заглавные буквы русского алфавита, включая символ 'Ё'.
 *
 * @section usage Использование
 * 1. Пользователь вводит ключ для шифрования.
 * 2. Выбирает операцию: зашифровать или расшифровать текст.
 * 3. Вводит текст для обработки.
 * Программа проверяет корректность текста и выполняет выбранную операцию.
 *
 * @section files Состав проекта
 * - main.cpp: Главный файл программы.
 * - modAlphaChiper.cpp: Реализация методов шифрования и расшифровки.
 * - modAlphaChiper.h: Заголовочный файл с описанием класса modAlphaCipher.
 */

/// @file main.cpp
/// @brief Главный файл программы, реализующей шифрование и расшифровку текста методом модифицированного шифра Альфа.

#include <iostream>
#include <cctype>
#include "modAlphaChiper.h"
#include <locale>

using namespace std;

/// @brief Проверяет корректность строки.
/// @param s Входная строка.
/// @return true, если строка состоит только из заглавных букв русского алфавита или символа 'Ё'.
bool isValid(const std::wstring& s) {
    for (auto c : s) {
        if (!iswupper(c) && c != L'Ё') {
            return false;
        }
    }
    return true;
}

/// @brief Главная функция программы.
int main(int argc, char **argv) {
    try {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);

        wstring key;
        wstring text;
        int op;

        wcout << L"Введите ключ:  ";
        wcin >> key;
        modAlphaCipher cipher(key);

        do {
            wcout << L"Выберите операцию (0-exit, 1-encrypt, 2-decrypt): ";
            wcin >> op;
            if (op > 2) {
                wcout << L"Некорректная операция\n";
            } else if (op > 0) {
                wcout << L"Введите текст: ";
                wcin >> text;
                if (isValid(text)) {
                    if (op == 1) {
                        wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << endl;
                    } else {
                        wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
                    }
                } else {
                    wcout << L"Некорректный текст для шифрования/расшифрования\n";
                }
            }
        } while (op != 0);
    } catch (const std::exception& e) {
        std::wcerr << L"Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
