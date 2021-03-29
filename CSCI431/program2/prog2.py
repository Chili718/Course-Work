'''
Title:Program 2

Name:Jon Tice

Description:Obtains the average of a collectioin of numbers the user chose.

Class:CSCI431

Date:2/4/2018
'''

#!/usr/bin/python

'''
Function: average

Description: returns the average of the numbers in the list given

Parameters: myRay

Return Value: sum(myRay)/len(myRay) "The average of the list"
'''

def average(myRay):
	#checking if the array passed is empty or not
	if (len(myRay) != 0):
        	return (sum(myRay)/len(myRay))
	else:
		return 0

'''
Start of program
'''
#prompt the user asking if they would like to run the program
answer = raw_input("Would you like to obtain the average of a collection of numbers (Type 'Yes' or 'No'): ")
#if their response was Yes the program will run 
while (answer == "Yes"):

	#the user enters the amount of integers ahead of time in order to for the loop to 
	#obtain the users input that amount of times
	size = raw_input("Enter the amount of integers you would like to average: ")

	#if a non integer is entered then the program will exit
	try:
		size = int(size)
	except ValueError:
		print "Valid integer not entered. Cannot Recover. Exiting."
		exit()
	#if a valid integer was entered the number can still be negative so that is being accounted for
	if(size < 0):
		print "Cannot find the average of ", size, " numbers. Exiting."
		exit()

	#create the empty list that will contain all the number the user would like to enter
	arr = []

	#print prompt for the user to enter 'size' amount of numbers
	print "Please enter ", size," numbers: "

	for x in range(size):
		num = raw_input()
		#if a non integer is entered then the program will exit
		try:
			num = float(num)
		except ValueError:
        		print "Valid integer not entered. Cannot Recover. Exiting."
        		exit()
		#if the input made it past error checking then it is a 
		#number that can be append to the list
		arr.append(num)

	print "The average of the numbers entered is: ", average(arr)
	#prompting the user to run the program again
	answer = raw_input("Would you like to obtain the average of another collection of numbers (Type 'Yes' or 'No'): ")
