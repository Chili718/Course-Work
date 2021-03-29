<!--
Assignment Number: 6

Description:Form that allows the student to choose a timeslot the professor set up

Name: Jon Tice

Class: CSCI 297

Date: 10/26/2018
-->
<html>
<head>
    <title>Set Up Appointment</title>
</head>
<center>
<Body bgcolor="#42dff4">

<h2 align=center>Select An Appointment Time</h2>

<form action='assignment6ProcessStudent.php' method='POST'>
<center>

<table>
   <tr>
        <td align=left> <b>Your First Name: </b>
        <td> <input type=text name=stud_f_name>
   <tr>
        <td align=left> <b>Your Last Name: </b>
        <td> <input type=text name=stud_l_name>
</table>


<table align=center rules=all cellpadding=10 border=4>
<TR>

<?php
/*
 *Name: date_sort
 *
 *Description: returns the difference between the two times
 *
 *Parameters: $a, $b
 *
 *Return Value:strtotime($a)-strtotime($b)
*/
function date_sort($a, $b)
{
	return strtotime($a)-strtotime($b);
}

//echo strtotime("Friday October 26th 2018 10:00am");

$lines = file("/tmp/apptTimesJT.txt", FILE_IGNORE_NEW_LINES) or die ("Could not open file");
//uses the date sort fucntion to sort the dates from the file in the array
usort($lines, "date_sort");
//varibles for checking when a new day has started 
$previousWD = "";
$previousMonth = "";
$previousDay = "";

foreach($lines as $line)
{
	//break the line up into separate words
	$words = explode(" ", $line);

	//words[0] = weekday | words[1] = month | words[2] = day | words[3] = year | words[4] = time

	//if the date is not the same as the previous time printed then a new day will start for the times to be 
	//placed under
	if($previousWD != $words[0] || $previousMonth != $words[1] || $previousDay != $words[2])
	{
		$dateNme = $words[0] . " " . $words[1] . " " . $words[2] . " " . $words[3]; 
		echo "<td valign=top>";
		echo "<h4 style='color:#DDDDFF;background-color:#3311AA'>&nbsp;&nbsp;$dateNme&nbsp;&nbsp;</h4>";
	}

	//print the time option for the date	
	echo "<input type=radio name=aptslot value='$line'>$words[4]</input><br>";
	//set the previous for the next date
	$previousWD = $words[0];
	$previousMonth = $words[1];
	$previousDay = $words[2];
		
}

?>

</table>
<center>
<P>
<input type=submit value="Sign Me Up!">
</form>

</Body>
</html>
