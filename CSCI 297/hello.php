<!--
Assignment Number: 1

Description: Prints 'Hello World' and the current date

Name: Jon Tice

Class: CSCI 297

Date: 9/2/2018
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
echo "Hello World<P>Today is ";
echo longdate(time());

?>

</body>
</html>
