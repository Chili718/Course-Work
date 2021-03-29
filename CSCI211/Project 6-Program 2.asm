# Project 6 - Program 2
#
#Reads two strings from a file, concatenates them and 
#prints out the new string
#
#Jon Tice
#
#CSCI 211
#
#4/17/2017
.data
firstWord: .asciiz "First Word: "
secondWord: .asciiz "\nSecond Word: "
mergedWord: .asciiz "\nMerged Word without new line: "
fileName: .asciiz "datafile.txt"
openError: .asciiz "Error! File could not open."
bufferOne: .space 8

.text
main:
	#file must be in the same directory as Mars.jar 
	la $a0, fileName
	li $a1, 0
	li $a2, 0
	li $v0, 13
	syscall
	#moving file descriptor for later use
	move $s0, $v0
	
	li $t0, -1
	#if the file was not properly opened it will display proper
	#message and end program
	bne $s0, $t0, fileOpened
	
	la $a0, openError
	jal print
	
	j fileNotOpen
	
fileOpened:
	#dynamically creating string to hold combined string for later 
	#based on the size of the first two lines
	li $a0, 16
	li $v0, 9
	syscall
	#storing that address of memory in $s3
	move $s3, $v0
	#start a count for number of valid bytes stored into the 
	#allocated memory for the merged string to return the position 
	#to beginning of the string
	li $s4, 0
###############################################

	#reads the first string from the first line into $s1 and prints it
	la $a0, firstWord
	jal print
	
	move $a0, $s0
	la $a1, bufferOne
	#reads the first 8 bytes which is the size of the first line in the file
	li $a2, 8
	li $v0, 14
	syscall
	
	move $s1, $a1
	
	move $a0, $s1
	jal print
	#new line is ascii code 10
	li $t2, 10
	
	#copies the string to the allocated memory
copyString:	
	
	lb $t1, ($s1)

	beqz $t1, endCreateone
	beq $t1, $t2, endCreateone

	sb $t1, ($s3)

	addi $s3, $s3, 1
	
	addi $s4, $s4, 1

	addi $s1, $s1, 1
	
	j copyString
	
endCreateone:
	
	move $a0, $s3
	jal print
	
###############################################

	#reads the second string from the second line into $s2 and prints it
	li $a0, 0
	la $a0, secondWord
	jal print
	
	move $a0, $s0
	la $a1, bufferOne
	#reads the size of the seconds line in the file including the new line character
	li $a2, 8
	li $v0, 14
	syscall
	
	move $s2, $a1
	
	move $a0, $s2
	jal print
	
	li $t2, 10
	#copies the second string into the allocated memory appending it to the first string
copyStringtwo:	
	
	lb $t1, ($s2)

	beqz $t1, endCreatetwo
	beq $t1, $t2, endLinetwo

	sb $t1, ($s3)

	addi $s3, $s3, 1
	addi $s4, $s4, 1
endLinetwo:
	addi $s2, $s2, 1
	
	j copyStringtwo
	
endCreatetwo:


################################################

	li $a0, 0
	
	la $a0, mergedWord
	jal print
	#moves position to beginning of string
	sub $s3, $s3, $s4
	
	move $a0, $s3
	jal print

################################################

	#close the file
	move $a0, $s0
	li $v0, 16
	syscall
	
fileNotOpen:

	li $v0, 10
	syscall


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
