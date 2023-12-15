#include "StateMachine.h"

int main() {
    set<string> alphabet = {"zero", "one"};
    vector<string> states = {"S0", "S1", "S2", "S3"};
    string startState = "S0";
    vector<string> acceptStates = {"S1", "S3"};
    map<pair<string, string>, string> transitionTable = {
        {{"S0", "zero"}, "S1"},
        {{"S0", "one"}, "S2"},
        {{"S1", "zero"}, "S2"},
        {{"S1", "one"}, "S0"},
        {{"S2", "zero"}, "S1"},
        {{"S2", "one"}, "S3"},
        {{"S3", "zero"}, "S0"},
        {{"S3", "one"}, "S0"},
    };
    string inputString;
    cout << "input string to check : " << endl;
    cin >> inputString;

    FiniteAutomaton ATM(alphabet, states, startState, transitionTable, inputString);
    ATM.lexemesCheck();

     
    if (ATM.isReachable(acceptStates)) 
        cout << "Target is achievable!" << endl;
    else
        cout << "Target is not achievable!"; 
    
    
    return 0;
}
