#include "StateMachine.h"

int main(){
    set<char> alphabet = {'0', '1'};
    vector<string> states = {"S1", "S2"};
    string startState = "S1";
    string acceptState = "S2";
    vector<vector<string>> transitionTable = {
        {"S2", "S1"},
        {"S1", "S2"}
    };
    FiniteAutomaton Oleg(alphabet, states, startState, acceptState, transitionTable);
    string inputString = "112321312";

    Oleg.setInputString(inputString);
    if (Oleg.isReachable(acceptState)) 
        cout << "Целевое состояние достижимо" << endl;
    else
        cout << "Целевое состояние не достижимо";
    return 0;
}