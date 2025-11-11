#define ROTATE_SPEED 30

Set Ob_A 2 0 3 30 10 0
Set Ob_B 10 10 5 0 0 20
Rotate Ob_B OY ROTATE_SPEED 40 //komentarz testowy
Pause 1000
Move Ob_A 10 10
Rotate Ob_B OZ ROTATE_SPEED 60 //inny komentarz
Move Ob_B 10 20