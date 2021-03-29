<!--
Assignment Number: 2

Description: Prints 'Hello World' and the next seven dates

Name: Jon Tice

Class: CSCI 297

Date: 9/14/2018
-->
<html>
<body>
<P>
<center>

<?php
//Name: longdate
//Description: returns a formatted date string
function longdate ($timestamp)
{
	return date("l F jS Y", $timestamp);
}

//Print Hello World and todays date
echo "Hello World. The next 7 days are:<P>";

//for loop to print the next seven days 
for($T = 0; $T < 7; $T++)
{
	//to get the preceding dates I multiplied the number of seconds in 
	//a day by the counter ($T) for the preceding days and added it to the reult of time
	echo longdate(time() + ($T*86400)) . "<br>";
}

?>

</body>
</html>
