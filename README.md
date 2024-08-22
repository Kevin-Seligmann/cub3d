# cub3D

## usage

Check [MLX42](https://github.com/codam-coding-college/MLX42) for requirements


Build with `make`


`./cub3D config_file.cub`

## Controls

W - Forwards movement

S - Backwards movement

A - Left strafe

D - Right strafe

E - Open/close doors

Left arrow - Rotate left

Right arrow - Rotate right

Mouse - Rotate left/right

Z, X - Zoom minimap

C - Restore default zoom

M - Hide/show minimap

ESC - Exit

## Configuration file

Configuration files must end with .cub

The first part consist of lines, empty or with so called elements. Elements have an identifier and attributes.

### Elements
`SO texture.png` - South wall

`NO texture.png`- North wall

`EA texture.png`- East wall

`WE texture.png`- West wall

`F 255, 255, 255` - Floor color

`C 0,0,0` - Ceiling color

`DR side_texture.png door_texture.png` - Door

`S2-S9 sprite_texture.png` - Sprite



Only .png textures are allowed.

Wall textures, color and door or sprites present on the map are obligatory.

Two textures must be provided for doors (Side texture and door texture).

There are 7 sprites, S2, S3 ... S9. Each sprite can have up to 30 textures, more than one texture will result in an animation effect.

Sprite textures must be placed as if they were different elements, e.g:

`S2 texture_1.png`

`S2 texture_2.png`

`...`


The second part is the map, consists of the following objects


### Map objects
1 - Wall

0 - Floor

N, S, W, E - Player

Space - Void

O - North-south wall

P - West-east wall

2 ... 9 - Sprite


All floor tiles, players, sprites and doors must be enclosed by walls.


The map content is last, and it should have no empty lines or anything after it.


## Features

- Map parsing and config file
- Raycasting renderization
- 'Paper' walls (At doors)
- Player movement
- Player collision
- Minimap system
- Animated sprites
- Actionable doors
