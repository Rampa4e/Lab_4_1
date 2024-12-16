/// @file modAlphaChiper.cpp
/// @brief Реализация методов класса modAlphaCipher.

#include <stdexcept> // Для обработки исключений
#include <string>
#include <iostream>
#include <cctype>
#include "modAlphaChiper.h"

/// @brief Конструктор класса.
/// @param skey Ключ для шифрования и расшифровки.
modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    for (unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

/// @brief Зашифровывает текст.
/// @param open_text Исходный текст.
/// @return Зашифрованный текст.
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    std::vector<int> work = convert(open_text);
    for (unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

/// @brief Расшифровывает текст.
/// @param cipher_text Зашифрованный текст.
/// @return Расшифрованный текст.
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    std::vector<int> work = convert(cipher_text);
    for (unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

/// @brief Конвертирует строку в вектор индексов.
/// @param s Входная строка.
/// @return Вектор индексов.
inline std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Invalid text");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

/// @brief Конвертирует вектор индексов в строку.
/// @param v Вектор индексов.
/// @return Строка.
inline std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (auto i : v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}




