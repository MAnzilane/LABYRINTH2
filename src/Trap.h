//
//  Trap.h
//  Trap
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef Trap_h
#define Trap_h
#include "Constant.h"
#include "Object.h"

/**\brief represent Trap of the game
@param obj
@param condition : active or inactive : init inactive
@param typeTrap  : MOBILE or FIXED
*/
typedef struct sTrap {
    Object *obj;
    Type condition;
    Type typeTrap;
}Trap;

/**\brief constructor of Trap
@param obj
@param typeTrap
@return Trap
*/
Trap * createTrap(Object * obj, Type typeTrap);

/**\brief : modify the condition of Trap active or inactive
@param trap
@param cond : condition
@return trap : modify
*/
Trap * setConditionTrap(Trap * trap, Type cond);

/**\brief to have a contennair of trap
@param trap
@return Object
*/
Object * getObjTrap(const Trap * trap);

/**\brief to get sort of trap
@param trap
@return Type
*/
Type getTypTrap(const Trap * trap);

/**\brief to infome of the condition of trap : active or inactive
@param trap
@return Type
*/
Type getCondTrap(const Trap * trap);

/**\brief to have a containt box
@param trap
*/
DesignType getTypeOfTrap(const Trap * trap);

/**\brie free trap
@param trap
*/
void destroyTrap(Trap * trap);

void printTrap(const Trap * trap);
void testTrap();

#endif /* Trap_h */
