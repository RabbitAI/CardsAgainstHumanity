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

    // input1.open("CAHanswers.txt");
    // input2.open("CAHquestions.txt");
    openInputFiles(input1, input2);

    // initalizes answers vector with values from CAHanswers input
    // while (getline(input1, ans))
    // {
    //     answers.push_back(ans);
    // }
    initializeVectors(input1, answers, ans);
    // initalizes questions vector with values from CAHquestions input
    // while (getline(input2, quest))
    // {
    //     questions.push_back(quest);
    // }
    initializeVectors(input2, questions, quest);
    // random value to provide a question
    // randiQuest = rand() * time(0) % (questions.size() + 1);
    // cout << randiQuest << endl
    //      << questions[randiQuest] << endl;
    getCards(randiQuest, questions);
    // counts how many _ are in a question if none index = 1
    for (int i = 0; i < questions[randiQuest].length(); i++)
    {
        if (questions[randiQuest][i] == '_')
            index++;
        // else
        //     index = 1;
    }
    // cout << "index " << index << endl;
    // loops based on value of index to provide an answer
    if (index > 0)
    {
        for (int i = 0; i < index; i++)
        {
            // randiAns = rand() * time(0) % (answers.size() + 1);
            // cout << randiAns << endl
            //      << answers[randiAns] << endl;
            getCards(randiAns, answers);
        }
    }
    else
    {
        // randiAns = rand() * time(0) % (answers.size() + 1);
        // cout << randiAns << endl
        //      << answers[randiAns] << endl;
        getCards(randiAns, answers);
    }

    // input1.close();
    // input2.close();
    closeInputFiles(input1, input2);
    return 0;
}