#include "function.h"

using namespace std;

struct Question_Answer
{
	string question;
	string answer;
};

vector<Question_Answer> database;

void loadData()
{
	string f;
	cout << "Введите имя файла для загрузки данных: ";
	cin >> f;
	ifstream file(f);
	cin.ignore();
	if (!file)
	{
		cout << "\nФайл не найден, создан новый.\n"; return;
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
	cin >> f;
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
	cout << "\nДобавлено.\n";
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