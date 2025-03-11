#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void openInputFiles(ifstream &input1, ifstream &input2)
{
    input1.open("CAHanswers.txt");
    input2.open("CAHquestions.txt");
}
void initializeVectors(ifstream &input, vector<string> &cards, string card)
{
    while (getline(input, card))
    {
        cards.push_back(card);
    }
}
void getCards(int &randi, vector<string> &cards)
{
    randi = rand() * time(0) % (cards.size() + 1);
    cout << randi << endl
         << cards[randi] << endl;
}
void closeInputFiles(ifstream &input1, ifstream &input2)
{
    input1.close();
    input2.close();
}

int main()
{
    ifstream input1, input2;
    int ansNum, questNum, randiQuest, randiAns, index = 0;
    string ans, quest;
    vector<string> answers;
    vector<string> questions;

    // Opens input files
    openInputFiles(input1, input2);

    // initalizes answers vector with values from CAHanswers input
    initializeVectors(input1, answers, ans);
    // initalizes questions vector with values from CAHquestions input
    initializeVectors(input2, questions, quest);
    // random value to provide a question
    getCards(randiQuest, questions);
    // counts how many _ are in a question if none index = 1
    for (int i = 0; i < questions[randiQuest].length(); i++)
    {
        if (questions[randiQuest][i] == '_')
            index++;
    }
    // loops based on value of index to provide an answer
    if (index > 0)
    {
        for (int i = 0; i < index; i++)
        {
            getCards(randiAns, answers);
        }
    }
    else
    {
        getCards(randiAns, answers);
    }

    closeInputFiles(input1, input2);
    return 0;
}