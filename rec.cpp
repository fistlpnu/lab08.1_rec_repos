#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

// Рекурсивний підрахунок груп "OGO" або "AGA"
int Count(const char* str, int i) {
    // Базовий випадок: якщо залишилося менше 3 символів, завершити
    if (strlen(str) < 3 || str[i + 2] == '\0') 
        return 0;
    // Перевіряємо, чи є поточна трійка "OGO" або "AGA"
    if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
        (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) {
        // Якщо збіг знайдено, додаємо 1 і переходимо до наступного символу
        return 1 + Count(str, i + 1);
    }
    // Інакше просто переходимо до наступного символу
    return Count(str, i + 1);
}

// Рекурсивна заміна "OGO" та "AGA"
char* Change(char* dest, const char* str, char* t, int i) {
    // Базовий випадок: якщо залишилося менше 3 символів, копіюємо залишок
    if (str[i + 2] == '\0') {
        strcpy(t, str + i);
        return dest;
    }
    // Якщо поточна трійка - це "OGO" або "AGA", замінюємо на "***"
    if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
        (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')) {
        strcat(t, "***");
        return Change(dest, str, t + 3, i + 3);
    }
    // Інакше додаємо поточний символ до нового рядка
    *t++ = str[i];
    *t = '\0';
    return Change(dest, str, t, i + 1);
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Рекурсивний підрахунок
    cout << "String contained " << Count(str, 0) << " groups of \"OGO\" or \"AGA\"." << endl;

    // Рекурсивна заміна
    char* dest = new char[151]; // Виділяємо пам'ять з запасом
    dest[0] = '\0'; // Ініціалізуємо порожній рядок
    Change(dest, str, dest, 0);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // Звільняємо пам'ять
    return 0;
}
