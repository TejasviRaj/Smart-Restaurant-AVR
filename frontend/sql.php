<?php
$server="127.0.0.1";
$user="Tejas";
$pwd="teamsedra";


// Create connection
$conn = new mysqli($server, $user, $pwd);
if ($conn->connect_error) {
    die("Connection failed: <br/>" . $conn->connect_error);
}
echo "Connected successfully<br/>";


//create database
 $sql = 'CREATE Database IF NOT EXISTS  testi';
 if ($conn->query($sql) === TRUE) {
     echo "Database created successfully<br/>";
 } else {
     echo "Error creating database:<br/> " . $conn->error;
 }


//select the Database
$sql="USE testi";
if ($conn->query($sql) === TRUE) {
    echo "Database created successfully<br/>";
} else {
    echo "Error creating database:<br/> " . $conn->error;
}

//create tables in a database

$sql = "CREATE TABLE IF NOT EXISTS MyGuests (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
firstname VARCHAR(30) NOT NULL,
lastname VARCHAR(30) NOT NULL,
email VARCHAR(50),
reg_date TIMESTAMP
)";

if ($conn->query($sql) === TRUE) {
    echo "Table MyGuests created successfully<br/>";
} else {
    echo "Error creating table: <br/>" . $conn->error;
}

//insert data into tables
$first="Ram";
$last="Prasad";

$sql = "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('$first', '$last', 'john@example.com')";

if ($conn->query($sql) === TRUE) {
    $last_id = $conn->insert_id;
    echo "New record created successfully. Last inserted ID is: " . $last_id;
    echo "<br/>";
} else {
    echo "Error: " . $sql . "<br/>" . $conn->error;
}

// insert multiple data at once
$sql = "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('John', 'Doe', 'john@example.com');";
$sql .= "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('Mary', 'Moe', 'mary@example.com');"; // concatenate another string
$sql .= "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('Julie', 'Dooley', 'julie@example.com')"; // concatenate another string

if ($conn->multi_query($sql) === TRUE) { //more than one query
    echo "New records created successfully<br>";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
$conn->close();


$conn = new mysqli($server, $user, $pwd,"testi");

//select data
$sql = "SELECT id,firstname,lastname FROM MyGuests";
$result = $conn->query($sql);
if ($result==TRUE)
{
  echo "Data succesfully selected<br>";

}
else {
  echo "Error selecting data ".$conn->error;
}


if ($result->num_rows>0) {
  //  output data of each row
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "<br/>";
    }
} else {
    echo "0 results";
  }

//delete a data
$sql = "DELETE FROM MyGuests WHERE id=3";

echo "<br><br>";
if ($conn->query($sql) === TRUE) {
    echo "Record deleted successfully<br/><br/>";
} else {
    echo "Error deleting record: " . $conn->error;
}

/*
$sql ="SET  @num := 0;

UPDATE MyGuests SET id = @num := (@num+1);

ALTER TABLE MyGuests AUTO_INCREMENT =1;";

if ($conn->multi_query($sql) === TRUE) {
    echo "Primary key readjusted succesfully<br>";
} else {
    echo "Error adjusting record:<br> " . $conn->error;
}
*/


$sql = "SELECT id,firstname,lastname FROM MyGuests";
$result = $conn->query($sql);
if ($result->num_rows>0) {
  //  output data of each row
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "<br/>";
    }
} else {
    echo "0 results";
  }

  echo "<br><br>";

//update data

$sql = "UPDATE MyGuests SET lastname='Bikram' WHERE id=24";

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully<br>";
} else {
    echo "Error updating record:<br> " . $conn->error;
}
echo "<br><br>";

$sql = "SELECT id,firstname,lastname FROM MyGuests";
$result = $conn->query($sql);
if ($result->num_rows>0) {
  //  output data of each row
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "<br/>";
    }
} else {
    echo "0 results";
  }
  echo "<br><br>";

//get Sum
$result = $conn->query('SELECT SUM(id) AS value_sum FROM MyGuests');
$row = mysqli_fetch_assoc($result);
$sum = $row['value_sum'];
echo "$sum";

//delete all records
/*
$sql="DELETE FROM MyGuests";
if ($conn->query($sql) === TRUE) {
    echo "All Records deleted successfully<br>";
} else {
    echo "Error deleting record:<br> " . $conn->error;
}  */

/*
$sql=" TRUNCATE TABLE MyGuests";
if ($conn->query($sql) === TRUE) {
    echo "All Records deleted successfully<br>";
} else {
    echo "Error deleting record:<br> " . $conn->error;
}
*/




$conn->close();
 ?>
