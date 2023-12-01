#include "StateMachine.h"

int main() {
    set<char> alphabet = {'0', '1'};
    vector<string> states = {"S0", "S1", "S2"};
    string startState = "S0";
    string acceptState = "S2";
    vector<vector<string>> transitionTable = {
        {"S1", "S0"},
        {"S2", "S1"},
        {"S1", "S2"}
    };
    FiniteAutomaton ATM(alphabet, states, startState, acceptState, transitionTable);
    string inputString;
    cout << "ВВедите строку для проверки: " << endl;
    cin >> inputString;


    ATM.setInputString(inputString);
    if (ATM.isReachable(acceptState)) 
        cout << "Целевое состояние достижимо" << endl;
    else
        cout << "Целевое состояние не достижимо";
    return 0;
}
