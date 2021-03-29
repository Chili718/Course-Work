# Project 5
#
#Prints how many instructions are executed between keyboard 
#presses and the characters input
#
#Jon Tice
#
#CSCI 211
#
#4/2/2017
.data
instructExecutedPrompt: .asciiz "Instructions Executed: "

.text
main:
	#load reciever control
	li $t1, 0xffff0000 
	
#################################################
#1-Poll the keyboard until a key is pressed
#################################################	
loopInp:

	lw $t0, 0($t1)
	
	andi $t0, $t0, 1

	beqz $t0, loopInp
#################################################
#2-Save the key pressed
#################################################
	lw $t5, 4($t1)
#################################################
#3-Initialize a counter with the number of instructions 
#  executed after the key was pressed and now.
#################################################
 	#five instructions were executed after the key was pressed
 	#this includes the initialization of the counter
 	li $t7, 5
 
#################################################
#4-Create a keyboard polling loop that increments a counter by the number 
#  of statements executed in the loop until another key is pressed.
#################################################	 	 
 loopInpCount:
 	#4 instructions are executed everytime the loop is repeated
 	#including the statement that updates the counter
	addi $t7, $t7, 4

	lw $t0, 0($t1)
	
	andi $t0, $t0, 1

	beqz $t0, loopInpCount
#################################################
#5-Save the key pressed
#################################################
	lw $t6, 4($t1)
#################################################
#6-Output the 2 characters and the value of the counter.
#################################################

	#prints the characters using memory mapped I/O
	li $t3, 1
	
	sw $t3, 8($t1)
	
loopOut1:

	lw $t0, 8($t1)
	
	andi $t0, $t0, 1

	beqz $t0, loopOut1
	
	sw $t5, 12($t1)
	
loopOut2:

	lw $t0, 8($t1)
	
	andi $t0, $t0, 1

	beqz $t0, loopOut2
	
	sw $t6, 12($t1)

	#print the # of instructions executed

	la $a0, instructExecutedPrompt
	li $v0, 4
	syscall
	
	move $a0, $t7
	li $v0, 1
	syscall
	
	#terminate program
	li $v0, 10
	syscall
