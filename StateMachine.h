#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

#ifndef Automaton
#define Automaton

using namespace std;

class FiniteAutomaton {
private:
    set<char> alphabet;
    vector<string> states;
    string startState;
    string acceptState;
    vector<vector<int>> transitionTable;
    string inputString;
public:
    // Метод для поиска индекса состояния
    int getIndex(const string &state) {
        auto it = find(states.begin(), states.end(), state);
        if (it != states.end())
            return distance(states.begin(), it);
        else {
            cout << "Ошибка: Состояние не найдено" << endl;
            return 0;
        }
    }

    void setInputString(const string &input) {
        inputString = input;
    }

    // Конструктор
    FiniteAutomaton(set<char> alphabet,
                    vector<string> states,
                    string startState,
                    string acceptState,
                    vector<vector<string>> transitionTableStrings)
        : alphabet(alphabet), states(states), startState(startState), acceptState(acceptState) {
        
        // Преобразование строк в числовые индексы и заполнение transitionTable
        for (const auto& row : transitionTableStrings) {
            vector<int> numericRow;
            for (const auto& state : row) {
                numericRow.push_back(getIndex(state));
            }
            transitionTable.push_back(numericRow);
        }
    }

    bool isReachable(string targetState) {
        int currentStateIndex = getIndex(startState); 
        for (char symbol : inputString) {
            if (currentStateIndex < transitionTable.size() && symbol - '0' < alphabet.size()) {
                currentStateIndex = transitionTable[currentStateIndex][symbol - '0'];
            } 
            else {
                cout << "Ошибка: Недопустимый символ в строке или таблице переходов" << endl;
                return false;
            }
        }
        return states[currentStateIndex] == targetState;
    }
};

#endif