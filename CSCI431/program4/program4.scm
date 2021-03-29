;
;Name: Jon Tice
;
;Title: Program 4 - Scheme
;
;Description:User inputs an amount of numbers to then obtain the 
;average of the collection of numbers
;
;Class: CSCI431
;
;Date:3/2/2018
;

;
;Name: getN
;
;Description: obtains the amount of number (n) and sums them (sum) to be returned
;
;Parameters: n: amount of numbers to be read, sum: the sum of the values read
;
;Return Value: sum
;
(define getN
	(lambda (n sum)
		(if (= n 0)
			sum
			(+ sum (getN (- n 1) (read)))
		)
	)
)

(begin
	(newline)
	;gain the amount of numbers from the user, I was not able to get the syntax correct 
	;to do it without knowing the numbers ahead of time
	(display "Enter the amount of numbers you would like to average: ")
	(define size (read))
	;(display size)
	;gain the number from the user and return the sum
	(define sum (getN size 0))
	;(display sum)
	;originally used a list for the whole of the program but was not able to get the syntax
	;right for appending 
	(define lst (list sum size))
	;(display avg)
	;calculate and display the average
	(define avg (/ sum size))
	(display "The average of the collection of numbers is: ")
	(display avg)
	(newline)
	;return the average rather than not return a value
	avg
	
)
