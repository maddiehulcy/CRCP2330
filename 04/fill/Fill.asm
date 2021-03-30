// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(BEGIN)
	@SCREEN
	D = A
	@curr
	M = D

(LOOP)
	@IN
	D = M
	@WHITE
	D;JEQ //if no input, white
	@BLACK
	0;JMP //if input, black

(BLACK)
	@curr
	M = -1
	D = M + 1
	M = D //go to next pixel
	@IN
	D = A - D
	@BEGIN
	D;JEQ
	@LOOP
	0;JMP

(WHITE)
	@curr
	M = 0
	D = M + 1
	M = D //go to next pixel
	@IN
	D = A - D
	@BEGIN
	D;JEQ
	@LOOP
	0;JMP


