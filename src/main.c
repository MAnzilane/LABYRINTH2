#include "Constant.h"
#include "Coordinates.h"
#include "Box.h"
#include "Object.h"
#include "Trap.h"
#include "Character.h"
#include "WorldGame.h"
#include "IhmSdl.h"



int main(int argc, char ** argv) {
    //testCoodintes(); // test ok !
    // testBox(); //ok
    // testObj(); //ok
    // testTrap(); //ok
    //testCharac(); //ok
    // testWorldGame("/home/manzilane/Documents/Labyrith2/LABYRINTH2/data/niveauTest.txt");
    IhmSdl * ihmSdl = CreateISdl("/home/manzilane/Documents/Labyrith2/LABYRINTH2/data/niveauTest.txt");
    printISdl(ihmSdl);
    eventment();
    destroyISdl(ihmSdl);
    return 0;
}
