# Filler
The concept of the game is simple: two players gain points by placing the shape on a board,
one after the other, the shape obtained by the virtual machine (special executable Ruby program).
The game ends when the shape cannot be placed anymore. I realized my own ai "vnekhay.filler" for this mini-game.
# How_to
``` bash
To start - use make; and write this:

"./filler_vm -f ./resources/maps/map02 -p1 ./resources/players/vnekhay.filler

-p2 ./resources/players/carli.filler"

To add some visual use make visual; and add "| ./SomeVisual" at the end.
```
