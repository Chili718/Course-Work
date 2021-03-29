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
	
	move $s0, $v0
	
	li $t0, -1
	
	bne $s0, $t0, fileOpened
	
	la $a0, openError
	jal print
	
	j fileNotOpen
	
fileOpened:
	
###############################################
	
	move $a0, $s0
	la $a1, bufferOne
	li $a2, 8
	li $v0, 14
	syscall
	
	add $s3, $s3, $v0
	
	move $a0, $a1
	jal create
	move $s1, $v0
	
###############################################
	
	move $a0, $s0
	la $a1, bufferOne
	li $a2, 8
	li $v0, 14
	syscall
	
	add $s3, $s3, $v0
	
	move $a0, $a1
	jal create
	move $s2, $v0

###############################################

	la $a0, firstWord
	jal print
	
	move $a0, $s1
	jal print

	la $a0, secondWord
	jal print
	
	move $a0, $s2
	jal print
	
################################################

	#addi $s3, $s3, -2
	move $a0, $s3
	li $v0, 9
	syscall
	
	move $t0, $v0
	
	li $t2, 10
	
copyStringone:	
	
	lb $t1, ($s1)

	beqz $t1, endCreate
	beq $t1, $t2, newLineone

	sb $t1, ($t0)

	addi $t0, $t0, 1
newLineone:
	addi $s1, $s1, 1
	
	j copyStringone
	
endCreate:
	
copyStringTwo:	
	
	lb $t1, ($s2)

	beqz $t1, endCreateTwo
	beq $t1, $t2, newLineTwo

	sb $t1, ($t0)

	addi $t0, $t0, 1
newLineTwo:
	addi $s2, $s2, 1
	
	j copyStringTwo
	
endCreateTwo:

	la $a0, mergedWord
	jal print

	sub $t0, $t0, $s3
	move $a0, $t0
	jal print
	
	#close the file
	move $a0, $s0
	li $v0, 16
	syscall
	
fileNotOpen:

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
	
loopL:
	lb $t1, 0($a0)
	
	beqz $t1, endL

	addi $a0, $a0, 1
	
	addi $t0, $t0, 1
	
	j loopL	
endL:
	sub $a0, $a0, $t0

	move $v0, $t0

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

############################################
#Function: create
#Arguments: $a0 - string to be copied 
#Description: dynamically allocates and copies the string passed into 
#the new string created
#Return: $v0 - pointer to the string created
############################################
create:
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	addi $sp, $sp, -8
	
	move $s0, $a0
	
	jal length
	
	move $a0, $v0
	li $v0, 9
	syscall
	
	move $t0, $v0
	li $t2, 10
	
copyString:	
	
	lb $t1, ($s0)

	beqz $t1, endCreateone
	beq $t1, $t2, newLine

	sb $t1, ($t0)

	addi $t0, $t0, 1
newLine:
	addi $s0, $s0, 1
	
	j copyString
	
endCreateone:
	
	addi $sp, $sp, 8
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	
	sub $t0, $t0, $a0
	
	move $v0, $t0
	
	jr $ra
