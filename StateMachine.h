#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#ifndef Automaton
#define Automaton

using namespace std;

class FiniteAutomaton{
private:
    set<char> alphabet;
    vector<string> states;
    string startState;
    string acceptState;
    vector<vector<string>> transitionTable;
    string inputString;
public:
    // функция для поиска индекса состояния
    int getIndex(const string& state) {
        auto it = find(states.begin(), states.end(), state);
        if (it != states.end())
            return distance(states.begin(), it);

        else {
            cout << "Состояние не найдено";
            return 0;
        }    
    }

    void setInputString (const string& input){
        inputString = input;
    }

    // конструктор
    FiniteAutomaton(
        set<char> alphabet,
        vector<string> states,
        string startState,
        string acceptState,
        vector<vector<string>> transitionTable
    ) : alphabet(alphabet), states(states), startState(startState), acceptState(acceptState), transitionTable(transitionTable) {}

    bool isReachable(string tergetString){
        string currentState = startState;

        if (inputString.length() == 0){
            cout << "Длина строки нулевая" << endl;
            return false;
        }

        for (const char symbol : inputString){
            auto symbolIndex = alphabet.find(symbol);
            if (symbolIndex == alphabet.end()){
                cout << "символ не найден в алфавите" << endl;
                return false;
            }

            currentState = transitionTable[getIndex(currentState)][*symbolIndex];

        }
        if (currentState == acceptState)
            return true;
        else
            return false;
    }
};

#endif