//
//  Character.h
//  Character
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef Character_h
#define Character_h
#include "Constant.h"
#include "Object.h"

/**\brief represnt game's Character
@param obj
@param life
@name
*/
typedef struct sCharacter {
    Object * obj;
    int life;   //init 5
    char *name;
}Character;

/**\brief constructor of Character
@param obj : contains Character
@param name : name of Character
@return Character
*/
Character * createCharac(Object * obj, char * name);

/**\brief name of Character
@param charac
@return name : of Character
*/
char * getNameCharac(const Character * charac);

/**\brief modify Character's life
@param charac
@param life : new life
*/
Character * setLifeCharac(Character * charac, int life);

/**\brief know remaning life
@param charac
@return life
*/
int getLifeCharac(const Character * charac);

/**\brief
@param charac
@return Object
*/
Object * getObjCharac(const Character * charac);

/**\brief free Character
@param charac
*/
void destroyCharac(Character * charac);

void printCharac(const Character * charac);

void testCharac();

#endif /* Character_h */
