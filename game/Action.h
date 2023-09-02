#ifndef ACTION_H
#define ACTION_H

enum class Action { NOP, STOP, LOOT, DOOR, ATTACK };

Action KeyToAction ( char key ) {
        switch ( key ) {
            case ' ' : return Action::ATTACK;
            default  : return Action::NOP;
    }
}

#endif