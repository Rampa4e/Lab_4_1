/// @file modAlphaChiper.h
/// @brief Описание класса modAlphaCipher.

#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>

/// @class modAlphaCipher
/// @brief Класс для шифрования и расшифровки текста методом Гронсвельда.
class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Алфавит.
    std::map<char, int> alphaNum; ///< Словарь для сопоставления символов и их индексов.
    std::vector<int> key; ///< Ключ для шифрования.

    /// @brief Конвертирует строку в вектор индексов.
    /// @param s Входная строка.
    /// @return Вектор индексов.
    std::vector<int> convert(const std::wstring& s);

    /// @brief Конвертирует вектор индексов в строку.
    /// @param v Вектор индексов.
    /// @return Строка.
    std::wstring convert(const std::vector<int>& v);

public:
    /// @brief Удалённый конструктор по умолчанию.
    modAlphaCipher() = delete;

    /// @brief Конструктор класса.
    /// @param skey Ключ для шифрования и расшифровки.
    modAlphaCipher(const std::wstring& skey);

    /// @brief Зашифровывает текст.
    /// @param open_text Исходный текст.
    /// @return Зашифрованный текст.
    std::wstring encrypt(const std::wstring& open_text);

    /// @brief Расшифровывает текст.
    /// @param cipher_text Зашифрованный текст.
    /// @return Расшифрованный текст.
    std::wstring decrypt(const std::wstring& cipher_text);
};
