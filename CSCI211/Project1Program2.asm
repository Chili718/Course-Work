# Project 1 - Program 2
#
#Calculates the sum, difference, product, and quoteint/remainder
#using 2 user given values.
#
#Jon Tice
#
#CSCI 211
#
#1/29/2017
.data
prompt: .asciiz "\nEnter an Integer: "
nums_Input: .asciiz "\nNumber Input: "
sumP: .asciiz "\nSum: "
diffP: .asciiz "\nDifference: "
multP: .asciiz "\nProduct: "
quotP: .asciiz "\nQuotient: "
remainP: .asciiz "\nRemainder: "
.text
main:
	#Gains First Number from User
	la $a0, prompt
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $t3, $v0
	
	#Gains Second Number from User
	la $a0, prompt
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $t4, $v0
	
	#Prints both numbers the user chose
	
	#The First
	la $a0, nums_Input
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $t3
	syscall
	
	#The Second
	la $a0, nums_Input
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $t4
	syscall
	
	#Calculates the Sum and Prints
	add $t0, $t3, $t4
	la $a0, sumP
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $t0
	syscall
	
	#Calculates the Difference and Prints
	sub $t0, $t3, $t4
	la $a0, diffP
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $t0
	syscall
	
	#Calculates the Product and Prints
	la $a0, multP
	li $v0, 4
	syscall
	mult $t3, $t4
	mflo $a0
	li $v0, 1
	syscall
		
	#Calculates the difference/remainder and Prints
	
	#Quotient
	div $t3, $t4
	la $a0, quotP
	li $v0, 4
	syscall
	mflo $a0 #move the quotient from low register to be printed
	li $v0, 1
	syscall
	
	#Remainder
	la $a0, remainP
	li $v0, 4
	syscall
	mfhi $a0 #move remainder from high register to be printed
	li $v0, 1
	syscall
	
	#Terminate Program
	li $v0, 10
	syscall
