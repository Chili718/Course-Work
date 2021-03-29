# Project 1 - Program 1
#
#Computes b+(a-c) using the variables already defined.
#
#Jon Tice
#
#CSCI 211
#
#1/28/2017
.data
resultP: .asciiz "Resulting Number: "
a: .word 7
b: .word 10
c: .word 3

.text 
main:
	lw $t0, a
	lw $t1, c
	sub $t0, $t0, $t1 #(a-c)
	lw $t1, b #c is not needed now that the result in $t0
	add $t0, $t1, $t0 # b + (^)
	
	#Output Text
	la $a0, resultP
	li $v0, 4
	syscall
	#Output Result Number
	move $a0, $t0 
	li $v0, 1
	syscall
	#Terminate Program
	li $v0, 10
	syscall
