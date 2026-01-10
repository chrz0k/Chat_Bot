#include "function.h"

using namespace std;

vector<Question_Answer> database;

void loadData()
{
	string f;
	cout << "Введите имя файла для загрузки данных: ";
	getline(cin, f);
	if (f.empty())
	{
		cout << "\nОшибка: Имя файла не может быть пустым\n";
		return;
	}
	if (f.find('.') == string::npos)
	{
		f += ".txt";
	}
	ifstream file(f);
	cin.ignore();
	if (!file)
	{
		cout << "\nФайл не найден, создан новый с указанным названием.\n"; return;
	}
	database.clear();
	Question_Answer item;
	while (getline(file, item.question))
	{
		if (getline(file, item.answer))
		{
			database.push_back(item);
		}
	}
	file.close();
	cout << "\nЗагружено " << database.size() << " вопросов.\n";
}

void saveData()
{
	string f;
	cout << "Введите имя файла для сохранения данных: ";
	getline(cin, f);
	if (f.empty())
	{
		cout << "\nОшибка: Имя файла не может быть пустым\n";
		return;
	}
	if (f.find('.') == string::npos)
	{
		f += ".txt";
	}
	ofstream file(f);
	cin.ignore();
	for (auto& Question_Answer : database)
	{
		file << Question_Answer.question << "\n" << Question_Answer.answer << "\n";
	}
	file.close();
	cout << "\nДанные сохранены.\n";
}

void addQuestion_Answer()
{
	Question_Answer newQuestion_Answer;
	cout << "Вопрос: ";
	getline(cin, newQuestion_Answer.question);
	cout << "Ответ: ";
	getline(cin, newQuestion_Answer.answer);
	database.push_back(newQuestion_Answer);
	cout << "\nВопрос добавлен.\n";
}

void findAnswer()
{
	if (database.empty())
	{
		cout << "Нет данных.\n";
		return;
	}
	string question;
	cout << "Ваш вопрос: ";
	getline(cin, question);
	for (auto& Question_Answer : database)
	{
		if (Question_Answer.question == question)
		{
			cout << "Ответ: " << Question_Answer.answer << "\n";
			return;
		}
	}
	for (auto& Question_Answer : database)
	{
		if (Question_Answer.question.find(question) != string::npos)
		{
			cout << "\nНайдено похожее:\n";
			cout << "\nВопрос: " << Question_Answer.question << "\n";
			cout << "Ответ: " << Question_Answer.answer << "\n";
			return;
		}
	}
	cout << "\nВопрос не найден.\n";
}

void printQuestion_Answer()
{
	if (database.empty())
	{
		cout << "Вопросов нет.\n";
		return;
	}
	cout << "Все вопросы:\n";
	for (int i = 0; i < database.size(); i++)
	{
		cout << i + 1 << ". " << database[i].question << "\n";
	}
}

void editQuestion_Answer()
{
	printQuestion_Answer();
	if (database.empty())
	{
		cout << "Нечего редактировать.\n";
		return;
	}
	int number;
	cout << "\nВведите номер для редактирования: ";
	cin >> number;
	while (true)
	{
		cout << "\nВведите номер для редактирования (1-" << database.size() << "): ";
		string input;
		getline(cin, input);
		if (input.empty())
		{
			cout << "\nОшибка: Введите число\n";
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
			cout << "\nОшибка: Введите число\n";
			continue;
		}
		try
		{
			number = stoi(input);
		}
		catch (...)
		{
			cout << "\nОшибка: Неверное число\n";
			continue;
		}
		if (number < 1 || number > database.size())
		{
			cout << "\nОшибка: Число должно быть от 1 до " << database.size() << "\n";
			continue;
		}
		break;
	}
	cout << "Новый вопрос: ";
	string newQuestion;
	getline(cin, newQuestion);
	cout << "Новый ответ: ";
	string newAnswer;
	getline(cin, newAnswer);
	if (!newQuestion.empty())
		database[number - 1].question = newQuestion;
	if (!newAnswer.empty())
		database[number - 1].answer = newAnswer;
	cout << "Готово\n";
}

void deleteQuestion_Answer()
{
	printQuestion_Answer();
	if (database.empty())
	{
		cout << "Нечего удалять.\n";
		return;
	}
	int number;
	cout << "\nВведите номер для удаления: ";
	cin >> number;
	while (true)
	{
		cout << "\nВведите номер для удаления (1-" << database.size() << "): ";
		string input;
		getline(cin, input);
		if (input.empty())
		{
			cout << "\nОшибка: Введите число\n";
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
			cout << "\nОшибка: Введите число\n";
			continue;
		}
		try
		{
			number = stoi(input);
		}
		catch (...)
		{
			cout << "\nОшибка: Неверное число\n";
			continue;
		}
		if (number < 1 || number > database.size())
		{
			cout << "\nОшибка: Число должно быть от 1 до " << database.size() << "\n";
			continue;
		}
		break;
	}
	cout << "Вы уверены, что хотите удалить вопрос \"" << database[number - 1].question << "\"? (y/n): ";
	string confirm;
	getline(cin, confirm);
	if (confirm == "y" || confirm == "Y" || confirm == "д" || confirm == "Д")
	{
		database.erase(database.begin() + (number - 1));
		cout << "Удалено\n";
	}
	else
	{
		cout << "Отменено\n";
	}
}

int checkmenu()
{
	string input;
	while (true)
	{
		cout << "Ваш выбор: ";
		getline(cin, input);
		if (input.empty())
		{
			cout << "Ошибка: Введите число\n\n";
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
			cout << "Ошибка: Введите число, а не текст\n\n";
			continue;
		}
		try
		{
			int choice = stoi(input);
			if (choice >= 0 && choice <= 8)
			{
				return choice;
			}
			else
			{
				cout << "Ошибка: Число должно быть от 0 до 8\n\n";
			}
		}
		catch (...)
		{
			cout << "Ошибка: Неверное число\n\n";
		}
	}
}