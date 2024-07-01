# cub3d

## Subject

Create a simulation using raycasting

Makefile: All rules, minilib compilation, libft compilation

Allowed: open, close, read, write, printf, malloc, free, perror, strerror, exit, all of math library, all of minilib

Smooth windows management, minimizing, changing window

On error, the program should print “Error\n”, then a message explaining the error, on STDERR, and exit

## File parsing

Only .cub files are valid

Maps are composed of lines containing the following symbols

- 0 - Empty space
- 1 - Wall
- N, S, W or E - The player and the direction it faces
- Spaces - Void
- [Bonus] D - A door
- [Bonus] A/B/C - Sprite 1, 2, or 3 (Only if they have a texture)

All 0 must be enclosed by 1

The map content is last, and it should have no empty lines

The other elements of the file can be separated by empty lines, and the information of each element can be separated by spaces

All elements consist of an identifier and the information, always in the order described below.

- North texture

    NO ./path

- South texture

    SO ./path

- East texture

    EA ./path

- West texture

    WE ./path

- Floor color

    F r,g,b

- Ceiling color

    C r,g,b

- [Bonus] Sprite 1

    SA ./path

- [Bonus] Sprite 2

    SB ./path

- [Bonus] Sprite 3

    SC ./path

- [Bonus] Door texture

    DR ./path


## Keys

The texture of the wall depends on which direction is facing, you can set floor and ceiling colors

Left and right keys change the direction you are looking (Maybe add Q and E)

WASD is movement

 Closing with X and ESC

[Bonus]: Mouse rotates the POV

[Bonus]: R open and closes doors

## Bonus

- Wall collision
- Minimap
- Doors that you can open and close
- Animated sprites
- Rotate the POV with the mouse
