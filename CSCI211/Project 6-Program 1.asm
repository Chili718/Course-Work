# Project 6 - Program 1
#
#Dynamically creates two strings then creates a third by appending
#the first string to the second then prints all of the strings 
#with proper labels
#
#Jon Tice
#
#CSCI 211
#
#4/17/2017
.data
stringOne: .asciiz "This is a test"
stringTwo: .asciiz " of our string routines"
title: .asciiz "Test of the String Methods."
stringOneTitle: .asciiz "\nFirst String: "
stringTwoTitle: .asciiz "\nSecond String:"
mergedStringTitle: .asciiz "\nMerged String: "

.text
main:
	#dynamically creates the first string and stores in $s0
	la $a0, stringOne
	jal create
	move $s0, $v0
	#dynamically creates the second string and stores in $s1
	la $a0, stringTwo
	jal create
	move $s1, $v0
	#appends the second string to the end of first one and stores in $s2
	move $a0, $s0
	move $a1, $s1
	jal append
	move $s2, $v0
	#prints the title and created strings using print function
	la $a0, title
	jal print
	
	la $a0, stringOneTitle
	jal print
	move $a0, $s0
	jal print
	
	la $a0, stringTwoTitle
	jal print
	move $a0, $s1
	jal print
	
	la $a0, mergedStringTitle
	jal print
	move $a0, $s2
	jal print
	#terminate program
	li $v0, 10
	syscall
	
############################################
#Function: length
#Arguments: $a0 - the referenced string whos length will be found
#Description: returns the length of the string referenced
#Return: $v0 - the length of the string
############################################
length:
	
	li $t0, 0
	#move through the string passed and count the number of bytes(chars)
	#until the null terminator is met
loopL:
	lb $t1, 0($a0)
	
	beqz $t1, endL

	addi $a0, $a0, 1
	
	addi $t0, $t0, 1
	
	j loopL	
endL:
	#return the position to beginning of the passed string
	sub $a0, $a0, $t0
	#return the length
	move $v0, $t0

	jr $ra
	
############################################
#Function: create
#Arguments: $a0 - string to be copied 
#Description: dynamically allocates and copies the string passed into 
#the new string created
#Return: $v0 - pointer to the string created
############################################
create:
	#saving the return address and one s register that will be used 
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	addi $sp, $sp, -8
	
	move $s0, $a0
	#gain the length of string to determine how much space needs to be allocated
	jal length
	#allocate that space
	move $a0, $v0 
	li $v0, 9
	syscall
	#move address of that space to t register to have the string coppied
	move $t0, $v0
	
copyString:	
	#load the byte from current position
	lb $t1, ($s0)
	#check if the byte loaded is the null terminator
	beqz $t1, endCreate
	#store the byte in memory
	sb $t1, ($t0)
	#move the positions to the next byte
	addi $t0, $t0, 1
	addi $s0, $s0, 1
	
	j copyString
	
endCreate:
	#restore address and s register
	addi $sp, $sp, 8
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	#move the position back to start of the string
	sub $t0, $t0, $a0
	#return the pointer to the newly created string
	move $v0, $t0
	
	jr $ra

############################################
#Function: append
#Arguments: $a0 - first string, $a1 - second string
#Description: appends the two strings into a new one
#Return: $v0 - the pointer to combined string
############################################
append:
	#save address and the current values of s registers 
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	sw $s2, 12($sp)
	addi $sp, $sp, -16
	#move the two strings to s registers
	move $s0, $a0
	move $s1, $a1
	li $s2, 0
	#find and combine the length of both strings 
	jal length
	
	add $s2, $v0, $s2
	
	move $a0, $s1
	
	jal length
	
	add $s2, $v0, $s2
	#allocate the space needed for combined strings
	move $a0, $s2
	li $v0, 9
	syscall
	
	move $t0, $v0
	#copy first string into the allocated memory
copyFirstString:	
	
	lb $t1, ($s0)

	beqz $t1, copySecondString

	sb $t1, ($t0)

	addi $t0, $t0, 1
	addi $s0, $s0, 1
	
	j copyFirstString
	#copy the second string into the allocated memory
copySecondString:	
	
	lb $t1, ($s1)

	beqz $t1, endCopy

	sb $t1, ($t0)

	addi $t0, $t0, 1
	addi $s1, $s1, 1
	
	j copySecondString
	
endCopy:
	#return the position to beginning of string
	sub $t0, $t0, $s2
	#return pointer to string and retstore s registers and return address
	move $v0, $t0
			
	addi $sp, $sp, 16
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	lw $s2, 12($sp)

	jr $ra


############################################
#Function: print
#Arguments: $a0 - pointer to the string to be printed
#Description: prints the string pointed to in $a0
#Return: none
############################################
print:

	li $v0, 4
	syscall
	
	jr $ra
