#ifndef ACTION_H
#define ACTION_H

enum class Action { NOP, STOP, LOOT, DOOR, ATTACK };

Action KeyToAction ( char key );

#endif