#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* s, char c) // кількість символів c у рядку
{
    int k = 0,
        pos = 0;                   // pos = позиція початку пошуку
    char* t;
    while (t = strchr(s + pos, c)) // t = вказівник на знайдений символ
    {
        pos = t - s + 1;
        k++;
    }

    return k;
}

char* Change(char* s) // заміна кожного слова "BASIC" на "Delphi"
{
    char* t = new char[strlen(s) * 6 / 5 + 1];
    char* p;
    int pos1 = 0,                       // pos1 = позиція початку пошуку
        pos2 = 0;
    *t = 0;

    while (p = strstr(s + pos1, "BASIC")) // p = вказівник на "BASIC"
    {
        pos2 = p - s + 5;               // pos2 = позиція після "BASIC"
        strncat(t, s + pos1, pos2 - pos1 - 5);
        strcat(t, "Delphi");
        pos1 = pos2;
    }
    strcat(t, s + pos1);

    return t;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "B : " << Count(str, 'B') << endl;
    cout << "A : " << Count(str, 'A') << endl;
    cout << "S : " << Count(str, 'S') << endl;
    cout << "I : " << Count(str, 'I') << endl;
    cout << "C : " << Count(str, 'C') << endl;

    char* dest = Change(str);

    cout << "Modified string: " << dest << endl;

    delete[] dest;

    return 0;
}
