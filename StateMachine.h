#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#ifndef Automaton
#define Automaton

using namespace std;

class FiniteAutomaton {
private:
    string startState;
    string inputString;
    set<string> alphabet;
    vector<string> states;
    vector<string> lexemes;
    map<pair<string, string>, string> transitionTable;
public:
    // Конструктор
    FiniteAutomaton(set<string> alphabet,
                    vector<string> states,
                    string startState,
                    map<pair<string, string>, string> transitionTable,
                    string inputString)
        : alphabet(alphabet), states(states), startState(startState), transitionTable(transitionTable), inputString(inputString) {
        
        // Конвертация входной строки в символы алфавита
        for (int stringIndex = 0; stringIndex < inputString.length();) {
            bool isSymbolFound = false;

            for (const auto& symbol : alphabet) {
                if (inputString.compare(stringIndex, symbol.length(), symbol) == 0) {
                    lexemes.push_back(symbol);
                    stringIndex += symbol.length();
                    isSymbolFound = true;
                    break;
                }
            }

            if (!isSymbolFound) {
                cerr << "Error: Invalid input string!" << endl;
                break;
            }
        }
    }

    void lexemesCheck(){
        for (auto elem: lexemes)
            cout << elem << " ";
        cout << endl;
    }

    bool isReachable(string currentState, string targetState) {
    for (const auto &lexeme : lexemes) {
        auto transition = make_pair(currentState, lexeme);

        if (transitionTable.find(transition) != transitionTable.end()) {
            currentState = transitionTable[transition];
            if (currentState == targetState)
            return true;
        } else {
            cerr << "Error: No transition for state " << currentState << " with lexeme " << lexeme << endl;
            return false;
        }
    }

    return false;
}

};

#endif