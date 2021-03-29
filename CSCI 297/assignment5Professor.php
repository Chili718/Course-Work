<!--
Assignment Number: 5

Description:Form that allows the professor to add times for advising

Name: Jon Tice

Class: CSCI 297

Date: 10/19/2018
-->
<html>
<head>
    <title>Times for Students</title>
</head>
<center>
<Body bgcolor="#ffcc00">
<h3 align=center>Add More Times for Advising</h3>

<form method='post' action='assignment5ProcessForm.php'>
     
     <P>
<table cellpadding=40 rules=all align=center>

<tr><td>
Select A Day:<br><hr>

<?php
//Name: longdate
//Description: returns a formatted date string
function longdate ($timestamp)
{
        return date("l F jS Y", $timestamp);
}

//for loop to print the next 21 days (3 weeks) without saturday and sunday
for($T = 0; $T < 21; $T++)
{
	$val = longdate(time() + ($T*86400));
	
	//the days for times do not include saturday and sunday
	if(strpos($val, 'Saturday') === false && strpos($val, 'Sunday') === false)
	{
		echo "<input type='radio' name='date' value='$val' unchecked>$val<br>";
		//if the day is friday then a hr will be added after to break up the weeks
		if(strpos($val, 'Friday') !== false)
		{
			echo"<hr>";
		}
	}
}

?>
</td><td>
Choose your time(s):<br><hr>

<input type='checkbox' name='timee[]' value='08:00am'>08:00am<br>
<input type='checkbox' name='timee[]' value='08:30am'>08:30am<br>
<input type='checkbox' name='timee[]' value='09:00am'>09:00am<br> 
<input type='checkbox' name='timee[]' value='09:30am'>09:30am<br> 
<input type='checkbox' name='timee[]' value='10:00am'>10:00am<br> 
<input type='checkbox' name='timee[]' value='10:30am'>10:30am<br> 
<input type='checkbox' name='timee[]' value='11:00am'>11:00am<br> 
<input type='checkbox' name='timee[]' value='11:30am'>11:30am<br> 
<hr>
<input type='checkbox' name='timee[]' value='12:00pm'>12:00pm<br> 
<input type='checkbox' name='timee[]' value='12:30pm'>12:30pm<br> 
<input type='checkbox' name='timee[]' value='01:00pm'>01:00pm<br> 
<input type='checkbox' name='timee[]' value='01:30pm'>01:30pm<br> 
<input type='checkbox' name='timee[]' value='02:00pm'>02:00pm<br> 
<input type='checkbox' name='timee[]' value='02:30pm'>02:30pm<br> 
<input type='checkbox' name='timee[]' value='03:00pm'>03:00pm<br> 
<input type='checkbox' name='timee[]' value='03:30pm'>03:30pm<br> 
<input type='checkbox' name='timee[]' value='04:00pm'>04:00pm<br> 
<input type='checkbox' name='timee[]' value='04:30pm'>04:30pm<br> 
<input type='checkbox' name='timee[]' value='05:00pm'>05:00pm<br>
<input type='checkbox' name='timee[]' value='05:30pm'>05:30pm<br>
<input type='checkbox' name='timee[]' value='06:00pm'>06:00pm<br>

</td></tr>
<tr><td colspan=2>

</table>
	<input type='submit' value="SUBMIT">
</form>

</Body>
</html>
