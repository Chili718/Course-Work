<!--
Assignment Number: 3 p2

Description: Retreves the contents of the file and outputs them to the browser

Name: Jon Tice

Class: CSCI 297

Date: 9/27/2018
-->
<html>
<body>
<P>
<center>

<?php

//print the contents of the file and swap \n with <br>
echo nl2br(file_get_contents("/tmp/ray.txt"));

?>

</body>
</html>

