========= READ ME Documentation =========

====== Purpose ======

To aid in the development for the Gameboy Advanced, by providing classes for sprites, backgrounds, the player, and a textbox.

====== Files Included ======

background.c - Contains all methods for the background class.
background.h - Contains method definitions and the struct definition for background.c
character.c - Contains all methods for the character class.
character.h - Contains method definitions and the struct definition for character.c
constants.h - Contains all constants to avoid magic numbers in code.
demo.c - Driver program that will be turned into a .gba file to be run.
player.c - Contains all methods for the player class.
player.h - Contains method definitions and the struct definition for player.c
sprite.c - Contains all methods for the sprite class.
sprite.h - Contains method definitions and the struct definition for sprite.c
textbox.c - Contains all methods for the textbox class.
textbox.h - Contains method definitions and the struct definition for textbox.c
border.grit - Contains the grit command to turn border.png into a valid format for the program to use.
border.png - Contains an image of a textbox border.
dlgbox.grit - Contains the grit command to turn dlgbox.png into a valid format for the program to use.
dlgbox.png - Contains an image of a textbox.
map.grit - Contains the grit command to turn map.png into a valid format for the program to use.
map.png - Contains an image of a room for the player to move around in.
npcSprite.grit - Contains the grit command to turn npcSprite.png into a valid format for the program to use.
npcSprite.png - Contains the sprite of a pokemart employee.
playerSprite.grit - Contains the grit command to turn playerSprite.png into a valid format for the program to use.
playerSprite.png - Contains a recolored image of the main character in Pokemon Emerald.
Makefile - Contains Instructions for computer on how to create executable of demo, and compile all libraries.

====== How to Compile ======

Running the command make while your present working directory is in this folder will compile your program, so long as libtonc is installed, as these libraries are built to abstract some of libtonc and as such rely on it.

====== How to Run ======

The Makefile will output a .gba file when run, and as a result, any GBA emulator that can run .gba files (at the time of writing mGBA and VisualBoyAdvance are both capable of this) will be able to read the .gba file as a ROM file which can then be played.

========= End of READ ME =========
