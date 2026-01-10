#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Question_Answer
{
    std::string question;
    std::string answer;
};

extern std::vector<Question_Answer> database;

bool asksave();
int checkmenu();
void loadData();
void saveData();
void addQuestion_Answer();
void findAnswer();
void printQuestion_Answer();
void editQuestion_Answer();
void deleteQuestion_Answer();