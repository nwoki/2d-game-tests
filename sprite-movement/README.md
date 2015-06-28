Hi all! This is a simple project I decided to make out of boredom (what else?). It's a series of tests for making
a 2D top view game like Legend of Zelda, Pok�mon etc. You get the idea.

This project in particular simply loads a given map and lets you move your player around it.



## Requisites

This project has/is being developed on a linux machine. So I can't guarantee it'll work on other systems. You'll need:

* **Required**
    * Cmake
    * Qt 5.x
    * g++ compiler

* **Optional**
    * Tiled (for making your custom maps and exporting them)


## Building

After cloning the project, simply go to the desired project folder:

```
$ mkdir build && cd build
$ cmake ../
$ make -j4 && ./output/<binary file depending on project>
```

## Settings file

In the settings file you must specify information regarding the `player` sprite and the `map` to use. The file should be self
explanatory. It's located in the `"assets/"` folder as `"settings.rc"`.


## Adding maps, npcs, player

### Maps

The maps go in the `"assets/maps"` directory, divided by name. So basically, every map **must** have its own folder. In a map folder you'll
need the following files (let's assume the map name is _"greenmap"_):

* greenmap.json
* greenmap.png
* tiles.png
* greenmap.tmx

When creating a map (I suggest using [Tiled](http://www.mapeditor.org/) for best results) you'll need to create the following layers for game interaction.

#### Layers

Every map must/can have a series of object layers as follows:

* ![ObjectImage](doc/readme-imgs/obj.png) **collision:** used to indicate areas not accessible by the player (wall, tree, boulder, etc)
* ![ObjectImage](doc/readme-imgs/obj.png) **playerstart:** used to indicate where the player spawns (this is used only for the first map)

### NPCs

TODO

### Player

The player sprite tile **must** go in the `"assets/players"` folder. The player tile must be arranged as follows:

* **first row:** the player's "up" animation
* **second row:** the player's "right" animation
* **third row:** the player's "down" animation
* **fourth row:** the player's "left" animation
