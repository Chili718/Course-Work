<!--
Assignment Number: 3

Description:Writes the output of assignemnt 2 into a file 

Name: Jon Tice

Class: CSCI 297

Date: 9/27/2018
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
//open the file ray.txt to write the dates into
$fp = fopen("/tmp/ray.txt", "w") or die ("Could not open for writing.");

//writes Hello World
fwrite($fp, "Hello World. The next 7 days are: \n\n");

//for loop to write the next seven days
for($T = 0; $T < 7; $T++)
{
        //to get the preceding dates I multiplied the number of seconds in
        //a day by the counter ($T) for the preceding days and added it to the reult of time
	fwrite($fp, longdate(time() + ($T*86400)) . "\n");
}
//close the file
fclose($fp);

echo "Done";

?>

</body>
</html>
