#include "StateMachine.h"

int main() {
    set<string> alphabet = {"zero", "one"};
    vector<string> states = {"S0", "S1", "S2"};
    string startState = "S0";
    string acceptState = "S2";
    map<pair<string, string>, string> transitionTable = {
        {{"S0", "zero"}, "S1"},
        {{"S0", "one"}, "S0"},
        {{"S1", "zero"}, "S1"},
        {{"S1", "one"}, "S2"},
        {{"S2", "one"}, "S0"},
        {{"S2", "zero"}, "S1"},
    };
    string inputString;
    cout << "ВВедите строку для проверки: " << endl;
    cin >> inputString;

    FiniteAutomaton ATM(alphabet, states, startState, transitionTable, inputString);
    ATM.lexemesCheck();

     
    if (ATM.isReachable(startState, acceptState)) 
        cout << "Целевое состояние достижимо" << endl;
    else
        cout << "Целевое состояние не достижимо"; 
    
    
    return 0;
}
