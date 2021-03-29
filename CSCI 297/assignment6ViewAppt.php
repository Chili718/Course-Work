<!--
Assignment Number: 6

Description:Dumps all of the scheduled appointment times to the screen
for the professor to view

Name: Jon Tice

Class: CSCI 297

Date: 10/19/2018
-->
<html>
<head>
    <title>Scheduled Appointment(s)</title>
</head>
<center>
<Body bgcolor="#42dff4">

<h2 align=center>All Scheduled Appointments</h2>
</center>
<?php
//make an array out of all the lines in the file
$lines = file("/tmp/schedTimeJT.txt", FILE_IGNORE_NEW_LINES);

$count = 1;
//print each of the appointment times
foreach($lines as $line)
{
	$words = explode(" ", $line);

	echo $count . "- " . $words[0] . ", " . $words[1] . " - " . $words[2] . ", " . $words[3] . " " . $words[4] . " " . $words[5] . " at " . $words[6] . "<br>";

	$count += 1;	
}	

?>

</body>
</html>
