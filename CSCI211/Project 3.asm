# Project 3
#
#Reads up to 10 integers to into an array then finds
#the sum, average, min, max, and how many values are 
#above and below the average
#
#Jon Tice
#
#CSCI 211
#
#2/20/2017
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
	#loads the arrays address to a register
	la $t7, array
	#initiates a count at zero in $t6
	li $t6, 0 
	#"i" for looping through array
	li $t5, 0
	
#
#Read in up to 10 integer values into an array
#
	
	la $a0, enterIntPrompt
	li $v0, 4
	syscall
	
inputLoop:

	li $v0, 5
	syscall
	#Conditions to break input loop
	#if user enters -9
	beq $v0, -9, endReadLoop
	#number of elements increases by 1
	addi $t6, $t6, 1
	#storing the value entered into the position in memory
	sw $v0, 0($t7)
	#moving to the next "position in array"
	addi $t7, $t7, 4
	
	#if all ten integers have been input it will break from loop
	beq $t6, 10, endReadLoop
	
	j inputLoop
	
endReadLoop:
	#if the count is 0 then -9 was first input so the program ends
	beqz $t6, endPrg

#
#Sum all of the "integers" in the array
#

sumLoop:
	#once "i = number of elements" the array has been fully traversed 
	beq $t5, $t6 endSumLoop
	
	#move backwards through array to "position 0"
	#add -4 first because the position is the next after the last "integer" 
	addi $t7, $t7, -4
	#I personally found it easier to do this instead of just taking 
	#the size of the element in bytes and multiplying it by the number of 
	#elements to get the total size and subtracting it from $t7 
	
	#loading the value at the "position in the array" into $t3
	lw $t3, 0($t7)
	#sum of all will be stored in $t4
	add $t4, $t4, $t3
	#adds 1 to "i"
	addi $t5, $t5, 1
	
	j sumLoop
	
endSumLoop:
	#display prompt and print sum
	la $a0, sumPrompt
	li $v0, 4
	syscall
	move $a0, $t4
	li $v0, 1
	syscall
	
#
#The integer average
#
 	#average is the sum/total # of elements
 	div $t4, $t6
 	#average is stored in $t1 for later use
 	mflo $t1
 	
 	#display prompt and print average
	la $a0, averagePrompt
	li $v0, 4
	syscall
	move $a0, $t1
	li $v0, 1
	syscall
	
#
#The minimum value in the array
#
	#reset i to 0
	li $t5, 0
	#the position is at the first element in the array after the sum loop
	#overwrites the sum in $t4 with the first value in array
	lw $t4, 0($t7)

minLoop:
	#increase i by 1
	addi $t5, $t5, 1
	#will break loop when i is equal to number of elements in array
	beq $t5, $t6, endMinLoop
	#move to next "array position"
	addi $t7, $t7, 4
	#loads the value to be compared
	lw $t3, 0($t7)
	#if the value in $t3 is less than then $t4 the min will be updated in $t4
	bge $t3, $t4, notLess
	
	move $t4, $t3
	
notLess:
	
	j minLoop

endMinLoop:
	#prints prompt and minimum value
	la $a0, minPrompt
	li $v0, 4
	syscall
	move $a0, $t4
	li $v0, 1
	syscall
	
#
#The maximum value in the array
#

	#reset i to 0
	li $t5, 0
	
	#overwrites the min in $t4 with the first value in array
	lw $t4, 0($t7)

maxLoop:

	addi $t5, $t5, 1
	#will break loop when i is equal to number of elements in array
	beq $t5, $t6, endMaxLoop
	#moves to next position of the value that will be compared
	addi $t7, $t7, -4
	
	#loads what is to be compared in $t3
	lw $t3, 0($t7)
	#if the value that is being comparted to $t4 is greater
	ble $t3, $t4, notGreater
	#moves the greater value in $t3 to $t4
	move $t4, $t3
	
notGreater:
	
	j maxLoop

endMaxLoop:
	#display prompt and print max 
	la $a0, maxPrompt
	li $v0, 4
	syscall
	move $a0, $t4
	li $v0, 1
	syscall

#
#How many values above and below the average
#
	#values above average
	li $t4, 0
	#values below average
	li $t3, 0
	#reset "i" to 0
	li $t5, 0

aboveBelowLoop:
			
	#after max loop the position is at the first element in array
	lw $t2, 0($t7)
	#if the "integer" being compared is above the average
	blt $t2, $t1, lessThanAverage
	bgt $t2, $t1, greaterThanAverage
	
	b wasEqualToAverage
	
greaterThanAverage:
	#increasing values above by 1
	addi $t4, $t4, 1
	
	b wasEqualToAverage
	
	#if the "integer" is below average
lessThanAverage:
	#increasing values below by 1
	addi $t3, $t3, 1

wasEqualToAverage:
	#increase i by 1
	addi $t5, $t5, 1
	#will break loop when i is equal to number of elements in array
	beq $t5, $t6, endAboveBelowLoop
	
	addi $t7, $t7, 4
	
	j aboveBelowLoop

endAboveBelowLoop:

	#display prompt and print number of values above
	la $a0, valuesAbovePrompt
	li $v0, 4
	syscall
	move $a0, $t4
	li $v0, 1
	syscall
	#display prompt and print number of values above
	la $a0, valuesBelowPrompt
	li $v0, 4
	syscall
	move $a0, $t3
	li $v0, 1
	syscall		

endPrg:	
	#terminate program
	li $v0, 10
	syscall
