// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

@R0
M=2
@R1
M=9

(LOOP)
	@R0
	D=M+M //D=R0+R0
	@R0
	M=D
	@R1
	D=M-1 //decrement R1
	@COMPLETE
	D;JEQ //if R1=0, go to COMPLETE

(COMPLETE)
	@COMPLETE

