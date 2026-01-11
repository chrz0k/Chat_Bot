#include "function.h"

std::vector<Question_Answer> database;

void loadData()
{
	std::string f;
	std::cout << "Введите имя файла для загрузки данных: ";
	std::getline(std::cin, f);
	if (f.empty())
	{
		std::cout << "\nОшибка: Имя файла не может быть пустым\n";
		return;
	}
	if (f.find('.') == std::string::npos)
	{
		f += ".txt";
	}
	std::ifstream file(f);
	if (!file)
	{
		std::cout << "\nФайл не найден, создан новый с указанным названием.\n"; return;
	}
	database.clear();
	Question_Answer item;
	while (std::getline(file, item.question))
	{
		if (std::getline(file, item.answer))
		{
			database.push_back(item);
		}
	}
	file.close();
	std::cout << "\nЗагружено " << database.size() << " вопросов.\n";
}

void saveData()
{
	std::string f;
	std::cout << "Введите имя файла для сохранения данных: ";
	std::getline(std::cin, f);
	if (f.empty())
	{
		std::cout << "\nОшибка: Имя файла не может быть пустым\n";
		return;
	}
	if (f.find('.') == std::string::npos)
	{
		f += ".txt";
	}
	std::ofstream file(f);
	for (auto& Question_Answer : database)
	{
		file << Question_Answer.question << "\n" << Question_Answer.answer << "\n";
	}
	file.close();
	std::cout << "\nДанные сохранены.\n";
}

void addQuestion_Answer()
{
	Question_Answer newQuestion_Answer;
	std::cout << "Вопрос: ";
	std::getline(std::cin, newQuestion_Answer.question);
	std::cout << "Ответ: ";
	std::getline(std::cin, newQuestion_Answer.answer);
	database.push_back(newQuestion_Answer);
	std::cout << "\nДобавлено.\n";
}

void findAnswer()
{
	if (database.empty())
	{
		std::cout << "Нет данных.\n";
		return;
	}
	std::string question;
	std::cout << "Ваш вопрос: ";
	std::getline(std::cin, question);
	if (question == " ")
	{
		std::cout << "\nОшибка: вы ввели пустой символ\n";
	}
	else
	{
		for (auto& Question_Answer : database)
		{
			if (Question_Answer.question == question)
			{
				std::cout << "Ответ: " << Question_Answer.answer << "\n";
				return;
			}
		}
		for (auto& Question_Answer : database)
		{
			if (Question_Answer.question.find(question) != std::string::npos)
			{
				std::cout << "\nНайдено похожее:\n";
				std::cout << "\nВопрос: " << Question_Answer.question << "\n";
				std::cout << "Ответ: " << Question_Answer.answer << "\n";
				return;
			}
		}
		std::cout << "\nВопрос не найден.\n";
	}
}

void printQuestion_Answer()
{
	if (database.empty())
	{
		std::cout << "Вопросов нет.\n";
		return;
	}
	std::cout << "Все вопросы:\n";
	for (int i = 0; i < database.size(); i++)
	{
		std::cout << i + 1 << ". " << database[i].question << "\n";
	}
}

void editQuestion_Answer()
{
	printQuestion_Answer();
	if (database.empty())
	{
		std::cout << "Нечего редактировать.\n";
		return;
	}
	int number;
	while (true)
	{
		std::cout << "\nВведите номер для редактирования (1-" << database.size() << "): ";
		std::string input;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\nОшибка: Введите число\n";
			continue;
		}
		bool checkNumber = true;
		for (char c : input)
		{
			if (!isdigit(c))
			{
				checkNumber = false;
				break;
			}
		}
		if (!checkNumber)
		{
			std::cout << "\nОшибка: Введите число\n";
			continue;
		}
		try
		{
			number = stoi(input);
		}
		catch (...)
		{
			std::cout << "\nОшибка: Неверное число\n";
			continue;
		}
		if (number < 1 || number > database.size())
		{
			std::cout << "\nОшибка: Число должно быть от 1 до " << database.size() << "\n";
			continue;
		}
		break;
	}
	std::cout << "Новый вопрос: ";
	std::string newQuestion;
	std::getline(std::cin, newQuestion);
	std::cout << "Новый ответ: ";
	std::string newAnswer;
	std::getline(std::cin, newAnswer);
	if (!newQuestion.empty())
		database[number - 1].question = newQuestion;
	if (!newAnswer.empty())
		database[number - 1].answer = newAnswer;
	std::cout << "Готово\n";
}

void deleteQuestion_Answer()
{
	printQuestion_Answer();
	if (database.empty())
	{
		std::cout << "Нечего удалять.\n";
		return;
	}
	int number;
	while (true)
	{
		std::cout << "\nВведите номер для удаления (1-" << database.size() << "): ";
		std::string input;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\nОшибка: Введите число\n";
			continue;
		}
		bool checkNumber = true;
		for (char c : input)
		{
			if (!isdigit(c))
			{
				checkNumber = false;
				break;
			}
		}
		if (!checkNumber)
		{
			std::cout << "\nОшибка: Введите число\n";
			continue;
		}
		try
		{
			number = stoi(input);
		}
		catch (...)
		{
			std::cout << "\nОшибка: Неверное число\n";
			continue;
		}
		if (number < 1 || number > database.size())
		{
			std::cout << "\nОшибка: Число должно быть от 1 до " << database.size() << "\n";
			continue;
		}
		break;
	}
	std::cout << "Вы уверены, что хотите удалить вопрос " << number << "? (y/n): ";
	std::string confirm;
	std::getline(std::cin, confirm);
	if (confirm == "y" || confirm == "Y" || confirm == "д" || confirm == "Д")
	{
		database.erase(database.begin() + (number - 1));
		std::cout << "Удалено\n";
	}
	else
	{
		std::cout << "Отменено\n";
	}
}

int checkmenu()
{
	std::string input;
	while (true)
	{
		std::cout << "Ваш выбор: ";
		std::getline(std::cin, input);
		if (input == " ")
		{
			std::cout << "Ошибка: вы ввели пустой символ\n\n";
			continue;
		}
		if (input.empty())
		{
			std::cout << "Ошибка: Введите число\n\n";
			continue;
		}
		bool checkNumber = true;
		for (char c : input)
		{
			if (!isdigit(c))
			{
				checkNumber = false;
				break;
			}
		}
		if (!checkNumber)
		{
			std::cout << "Ошибка: Введите число, а не текст\n\n";
			continue;
		}
		try
		{
			int choice = stoi(input);
			if (choice >= 0 && choice <= 7)
			{
				return choice;
			}
			else
			{
				std::cout << "Ошибка: Число должно быть от 0 до 7\n\n";
			}
		}
		catch (...)
		{
			std::cout << "Ошибка: Неверное число\n\n";
		}
	}
}

bool asksave()
{
	std::string answer;
	while (true)
	{
		std::cout << "Сохранить данные перед выходом? (y/n): ";
		std::getline(std::cin, answer);
		if (answer == "y" || answer == "Y")
		{
			return true;
		}
		else if (answer == "n" || answer == "N")
		{
			return false;
		}
		else
		{
			std::cout << "Не понял. Введите 'y' (да) или 'n' (нет)\n";
		}
	}
}