#include "Automata.h"

using std::cout;
using std::string;
using std::endl;

static void PrintInfo(STATES state) 
{
    switch (state) 
    {
        case OFF:
            cout << "Automata is off" << endl;
            break;
        case WAIT:
            cout << "Automata is waiting for order" << endl;
            break;
        case ACCEPT:
            cout << "Select the menu item" << endl;
            break;
        case CHECK:
            cout << "Financial check" << endl;
            break;
        case COOK:
            cout << "Cooking" << endl;
            break;
        default:
            break;       
    }
}

namespace Automata {

    void Choice(int pos) 
    {
        if (position <= MENU_SIZE && position > 0) 
        {
            if (state == ACCEPT) 
            {
                state = CHECK;
                position = pos - 1;
            }
        }
        else 
        {
            cout << "Invalid value entered" << endl;
        }
        PrintInfo(state);
    }

    void On() 
    {
        if (state == OFF) 
        {
            state = WAIT;

            cout << "Menu of Automata" << endl;
            for (int i = 0; i < MENU_SIZE; i++) 
            {
                cout << i + 1 << " position: " << menu[i] << endl;
            }

        }
        PrintInfo(state);
    }

    void Off() 
    {
        if (state == WAIT)
        {
            state = OFF;
        }
        PrintInfo(state);
    }

    void Coin(double money)
    {
        if (state == WAIT || state == ACCEPT) 
        {
            state = ACCEPT;
            cash += money;
        }
        PrintInfo(state);
    }

    void Check() 
    {
        if (state == CHECK)
        {
            cout << "---" << cash << endl;
            if (cash >= prices[position]) 
            {
                state = COOK;
            }
            else 
            {
                cout << "Not enough money" << endl;
                position = -1;
                state = WAIT;
            }
        }
        PrintInfo(state);
    }

    int Cancel()
    {
        if (state == ACCEPT || state == CHECK) 
        {
            position = -1;
            state = WAIT;
            double change = cash;
            cash = 0;
            PrintInfo(state);
            return change;
        }
        return -1;
    }

    void Cook() 
    {
        if (state == COOK) 
        {
            cash -= prices[position];
            cout << "Processing..." << endl;
        }
    }

    void Finish()
    {
        if (state == COOK) 
        {
            state = WAIT;
        }
        PrintInfo(state);
    }
}
