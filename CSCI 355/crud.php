<?php
//conect to the database
$con = new mysqli ("deltona.birdnest.org", "my.ticej2", "Chili71814", "my_ticej2_crud");

if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

?>
<a href = "insert.php">Add New</a>
<a href = "select.php">Select</a>
<table cellpadding = "5" cellspacing = "0" border = "1">
	<tr>
		<th>id</th>
		<th>Name</th>
		<th>AcctID</th>
		<th>Action</th>
	</tr>
<?php
//get all the records in PROFILE to display
$query = mysqli_query($con, "SELECT * FROM PROFILE");
if(mysqli_num_rows($query) > 0)
{
	
	while($row = mysqli_fetch_object($query))
	{
//each record will have an update and delete option
?>	
	<tr>
		<td><?php echo $row->id; ?></td>
                <td><?php echo $row->Name; ?></td>
                <td><?php echo $row->AcctID; ?></td>
                <td>
			<a href = "insert.php?edited=1&id=<?php echo $row->id; ?>">Edit</a> |
			<a href = "insert.php?deleted=1&id=<?php echo $row->id; ?>">Delete</a>
		</td>
	</tr>
<?php
	}
}
$con -> close();
?>
</table>
