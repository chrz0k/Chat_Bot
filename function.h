#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Question_Answer
{
    string question;
    string answer;
};

extern vector<Question_Answer> database;

int checkmenu();
void loadData();
void saveData();
void addQuestion_Answer();
void findAnswer();
void printQuestion_Answer();
void editQuestion_Answer();
void deleteQuestion_Answer();