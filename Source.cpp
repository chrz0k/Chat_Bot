#include "function.h"
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = 1;
    while (choice != 0)
    {
        string input;
        system("cls");
        cout << "             ЧАТ-БОТ      \n"
            << "=================================\n"
            << "0. Выход из программы\n"
            << "1. Загрузить данные из файла\n"
            << "2. Вывод всех доступных вопросов\n"
            << "3. Поиск ответа на веденный вопрос\n"
            << "4. Добавить вопрос\n"
            << "5. Редактировать вопрос и его ответ\n"
            << "6. Удалить вопрос\n"
            << "7. Сохранение данных\n"
            << "=================================\n";
        choice = checkmenu();
        switch (choice)
        {
        case 0:
            cout << "=================================\n";
            cout << "Уже уходите? Выход из программы...\n";
            break;
        case 1:
            loadData();
            cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            cin.ignore();
            break;
        case 2:
            printQuestion_Answer();
            cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            cin.ignore();
            break;
        case 3:
            findAnswer();
            cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            cin.ignore();
            break;
        case 4:
            addQuestion_Answer();
            cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            cin.ignore();
            break;
        case 5:
            editQuestion_Answer();
            cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            cin.ignore();
            break;
        case 6:
            deleteQuestion_Answer();
            cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            cin.ignore();
            break;
        case 7:
            saveData();
            cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            cin.ignore();
            break;
        if (choice != 0)
        {
            cout << "\n=================================\n"
                << "Нажмите Enter чтобы продолжить...";
            cin.ignore();
            cin.get();
        }
        }
    }
}