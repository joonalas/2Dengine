#ifndef STATE_CHANGE_EXCEPTION_H
#define STATE_CHANGE_EXCEPTION_H

#include <string>

// So the function here is to make game states stop updating game objects
// if the state is changed.

class StateChangeException {
    public:
        StateChangeException() {}
        ~StateChangeException() {}

        std::string getType() {return "!StateChangeException!";}
};

#endif // !STATE_CHANGE_EXCEPTION_H