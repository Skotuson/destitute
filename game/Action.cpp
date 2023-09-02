#include "Action.h"

Action KeyToAction ( char key ) {
        switch ( key ) {
            case ' ' : return Action::ATTACK;
            default  : return Action::NOP;
    }
}