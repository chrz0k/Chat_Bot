#include "function.h"
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = 1;
    while (choice != 0)
    {
        std::string input;
        system("cls");
        std::cout << "             ЧАТ-БОТ      \n"
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
            std::cout << "Уже уходите?\n";
            if (!database.empty())
            {
                if (asksave())
                {
                    std::cout << "\nСохранение данных...\n";
                    saveData();
                }
                else
                {
                    std::cout << "\nДанные не сохранены.\n";
                }
            }

            std::cout << "\nВыход из программы...\n";
            break;
        case 1:
            loadData();
            std::cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            std::cin.ignore();
            break;
        case 2:
            printQuestion_Answer();
            std::cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            std::cin.ignore();
            break;
        case 3:
            findAnswer();
            std::cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            std::cin.ignore();
            break;
        case 4:
            addQuestion_Answer();
            std::cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            std::cin.ignore();
            break;
        case 5:
            editQuestion_Answer();
            std::cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            std::cin.ignore();
            break;
        case 6:
            deleteQuestion_Answer();
            std::cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            std::cin.ignore();
            break;
        case 7:
            saveData();
            std::cout <<
                "=================================\n" <<
                "Нажмите Enter чтобы продолжить...";
            std::cin.ignore();
            break;
        if (choice != 0)
        {
            std::cout << "\n=================================\n"
                << "Нажмите Enter чтобы продолжить...";
            std::cin.ignore();
            std::cin.get();
        }
        }
    }
}