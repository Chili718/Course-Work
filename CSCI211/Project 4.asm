# Project 4
#
#Reads up to 10 integers to into an array then finds
#the sum, average, min, max, and how many values are 
#above and below the average using functions
#
#Jon Tice
#
#CSCI 211
#
#3/13/2017
.data 
array: .space 40
enterIntPrompt: .asciiz "\nEnter up to ten integers then enter -9:\n"
sumPrompt:.asciiz "\nSum of Integers: "
averagePrompt: .asciiz "\nAverage of Integers: "
minPrompt: .asciiz "\nMinimum of the Integers: "
maxPrompt: .asciiz "\nMaximum of the Integers: "
valuesAbovePrompt: .asciiz "\nNumber of Values above Average: "
valuesBelowPrompt: .asciiz "\nNumber of Values below Average: "
.text
main:
	
	la $a0, enterIntPrompt
	jal printString
	
	la $a1, array
	jal inputTenIntegers
	
	#move the returned values (array and element count)
	#to the s registers to be used in the arguments for later functions
	move $s0, $v0
	move $s1, $v1
######################################
	la $a0, sumPrompt
	jal printString
	#passing arguments to function before call
	move $a1, $s0
	move $a2, $s1
	jal findSum
	#printing the returned value from function
	move $a0, $v0
	jal printInt
######################################	
	la $a0, averagePrompt
	jal printString
	#passing arguments to function before call
	move $a1, $s0
	move $a2, $s1
	jal findAverage
	#printing the returned value from function
	move $a0, $v0
	jal printInt
######################################
	la $a0, minPrompt
	jal printString
	#passing arguments to function before call
	move $a1, $s0
	move $a2, $s1
	jal findMin
	#printing the returned value from function
	move $a0, $v0
	jal printInt
######################################
	la $a0, maxPrompt
	jal printString
	#passing arguments to function before call
	move $a1, $s0
	move $a2, $s1
	jal findMax
	#printing the returned value from function
	move $a0, $v0
	jal printInt
######################################
	#passing arguments to function before call
	move $a1, $s0
	move $a2, $s1
	jal findAboveBelow
	#push both returned values onto the stack to save them
	#so the print functions can be called
	sw $v1, 0($sp)
	addi $sp, $sp, -4
	sw $v0, 0($sp)
	addi $sp, $sp, -4
	#print the number of values above
	la $a0, valuesAbovePrompt
	jal printString
	
	addi $sp, $sp, 4
	lw $a0, 0($sp)
	jal printInt
	#print the number of values below
	la $a0, valuesBelowPrompt
	jal printString
	
	addi $sp, $sp, 4
	lw $a0, 0($sp)
	jal printInt

endPrg:	
	#terminate program
	li $v0, 10
	syscall
	
############################################
#Function: printString
#Arguments: $a0 - address of the string to be printed 
#Description: prints the string from the address passed 
#Return: None
############################################	
printString:
	li $v0, 4
	syscall
	
	jr $ra
############################################
#Function: printInt
#Arguments: $a0 - number to be printed 
#Description: prints the number passed 
#Return: None
############################################	
printInt:
	li $v0, 1
	syscall
	
	jr $ra
############################################
#Function: inputTenIntegers
#Arguments: $a1 - array to be filled
#Description: reads up to ten integers into the array that is removed
#from the stack and counts the # of elements
#Return: the filled array($v0) and element count ($v1)
############################################	
inputTenIntegers:
	#number to end input
	li $t0, -9
	#max numbers that can be input
	li $t1, 10
	move $t7, $a1
	#count for the total number of elements
	li $t6, 0
	
	inputLoop:

	li $v0, 5
	syscall
	#Conditions to break input loop
	#if user enters -9
	beq $v0, $t0, endReadLoop
	#number of elements increases by 1
	addi $t6, $t6, 1
	#storing the value entered into the position in memory
	sw $v0, 0($t7)
	#moving to the next "position in array"
	addi $t7, $t7, 4
	
	#if all ten integers have been input it will break from loop
	beq $t6, $t1, endReadLoop
	
	j inputLoop
	
	endReadLoop:
	#if the count is 0 then -9 was first input so the program ends
	beqz $t6, endPrg
	
	li $t4, 4
	mult $t6, $t4
	mflo $t5
	
	sub $t7, $t7, $t5
	
	#returning the array and element count
	move $v0, $t7
	move $v1, $t6
	
	jr $ra

############################################
#Function: findSum
#Arguments: $a1 - array, $a2 - element count
#Description: find the total sum of all the elements in the array 
#Return: the sum of elements($v0) 
############################################
findSum:
	#reset both registers to 0
	li $t5, 0
	li $t4, 0
	
	sumLoop:
	#once "i = number of elements" the array has been fully traversed 
	beq $t5, $a2, endSumLoop
	
	#loading the value at the "position in the array" into $t3
	lw $t3, 0($a1)
	
	addi $a1, $a1, 4
	
	#sum of all will be stored in $t4
	add $t4, $t4, $t3
	
	#adds 1 to "i"
	addi $t5, $t5, 1
	
	j sumLoop
	
	endSumLoop:
	li $t0, 4
	mult $t0, $a2
	mflo $t1
	
	sub $a1, $a1, $t1
	
	#return the sum of elements
	move $v0, $t4
	
	jr $ra

############################################
#Function: findAverage
#Arguments: $a1 - array, $a2 - element count
#Description: find the average of all the elements in the array 
#Return: the average of elements($v0)
############################################
findAverage:

	#saving the correct return address to call another function
	sw $ra, 0($sp)
	addi $sp, $sp, -4
	
	jal findSum
	
	#average is the sum/total # of elements
 	div $v0, $a2
 	#average is stored in $t1 for later use
 	mflo $v0
 	
	#restoring the correct return address in $ra
	addi $sp, $sp, 4
	lw $ra, 0($sp)
	
	jr $ra
############################################
#Function: findMin
#Arguments: $a1 - array, $a2 - element count
#Description: find the minimum value of all the elements in the array 
#Return: the min value of the elements($v0)
############################################
findMin:
	#reset i to 0
	li $t5, 0
	#loads 1st element from array
	lw $t4, 0($a1)

	minLoop:
	#increase i by 1
	addi $t5, $t5, 1
	#will break loop when i is equal to number of elements in array
	beq $t5, $a2, endMinLoop
	#move to next "array position"
	addi $a1, $a1, 4
	#loads the value to be compared
	lw $t3, 0($a1)
	
	#if the value in $t3 is less than then $t4 the min will be updated in $t4
	bge $t3, $t4, notLess
	
	move $t4, $t3
	
	notLess:
	
	j minLoop

	endMinLoop:
	#return the min value
	move $v0, $t4
	
	jr $ra
	
############################################
#Function: findMax
#Arguments: $a1 - array, $a2 - element count
#Description: find the maximum value of all the elements in the array 
#Return: the max value of the elements($v0)
############################################
findMax:
	#reset i to 0
	li $t5, 0
	#loads 1st element from array
	lw $t4, 0($a1)

	maxLoop:

	addi $t5, $t5, 1
	#will break loop when i is equal to number of elements in array
	beq $t5, $a2, endMaxLoop
	#moves to next position of the value that will be compared
	addi $a1, $a1, 4
	#loads what is to be compared in $t3
	lw $t3, 0($a1)
	#if the value that is being comparted to $t4 is greater
	ble $t3, $t4, notGreater
	#moves the greater value in $t3 to $t4
	move $t4, $t3
	
	notGreater:
	
	j maxLoop

	endMaxLoop:
	#return the max value
	move $v0, $t4
	
	jr $ra
	
############################################
#Function: findAboveBelow
#Arguments: $a1 - array, $a2 - element count
#Description:returns the number of values above and below the average in the array
#Return: the number of values above the average($v0) 
#the number of values below the average($v1)
############################################
findAboveBelow:
	#saving correct return address for correct return
	sw $ra, 0($sp)
	addi $sp, $sp, -4
	
	jal findAverage
	#reset the registers that will be used to 0 
	li $t5, 0
	li $t4, 0
	li $t3, 0
	
	aboveBelowLoop:
			
	lw $t2, 0($a1)
	#if the "integer" being compared is above the average
	#average returned in $v0 from function call
	blt $t2, $v0, lessThanAverage
	bgt $t2, $v0, greaterThanAverage
	
	b wasEqualThanAverage
	
	greaterThanAverage:
	#increasing values above by 1
	addi $t4, $t4, 1
	
	b wasEqualThanAverage
	
	#if the "integer" is below average
	lessThanAverage:
	#increasing values below by 1
	addi $t3, $t3, 1

	wasEqualThanAverage:
	#increase i by 1
	addi $t5, $t5, 1
	#will break loop when i is equal to number of elements in array
	beq $t5, $a2, endAboveBelowLoop
	
	addi $a1, $a1, 4
	
	j aboveBelowLoop

	endAboveBelowLoop:
	
	#return # above
	move $v0, $t4
	#return # below
	move $v1, $t3
	#restoring the correct return address
	addi $sp, $sp, 4
	lw $ra, 0($sp)
	
	jr $ra
