//
//  Object.h
//  Object
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef Object_h
#define Object_h
#include "Constant.h"
#include "Box.h"

/**\brief reprente an object of game's environment
@param box : contains this object
@param typeObj : sort of pbject [FIXED or MOBILE]
@param typeOfObj : design of obj
*/
typedef struct sObject {
    Box *box;
    Type typeObj;
    DesignType typeOfObj;
}Object;

/**\brief init an Object
@return an Object
*/
Object * initObj();

/**\brief constructor of Object
@param box : contains this object
@param typeObj :  sort of pbject [FIXED or MOBILE]
@param typeOfObj :
@return obj
*/
Object * createObj(Box *box, Type typeObj, DesignType typeOfObj);

/**\brief to get sort of object
@param obj
@return typeObj
*/
Type getTypeObj(const Object * obj);

/**\brief to get contennair of object
@param obj
@return box
*/
Box * getBoxObj(const Object * obj);

/**\brief
@param obj
*/
int getTypeOfObj(const Object * obj);

/**\brief return the reely x position of obj
@param coordX
@param w
return pxPosX
*/
int calcPxPosXOfObj(int coordX, int w);

/**\brief return the reely y position of obj
@param coordY
@param h
return pxPosY
*/
int calcPxPosYOfObj(int coordY, int h);

/**\brief to free obj
@param obj : object to be destroy
*/
void destroyObj(Object *obj);


void printObj(const Object *obj);
void testObj();
#endif /* Objcet_h */
