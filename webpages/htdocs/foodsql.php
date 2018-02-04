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

//select the Database
$sql="USE Smart";
if ($conn->query($sql) === TRUE) {
    echo "Database selected succesfully<br/>";
} else {
    echo "Error selecting database:<br/> " . $conn->error;
}

//insert data into tables
$first="Ram";
$last="Prasad";

$sql = "INSERT INTO Food (Food, Price, Num_selected, Prepared)
VALUES ('Dal',50,0,0)";

if ($conn->query($sql) === TRUE) {
    $last_id = $conn->insert_id;
    echo "New record created successfully. Last inserted ID is: " . $last_id;
    echo "<br/>";
} else {
    echo "Error: " . $sql . "<br/>" . $conn->error;
}

// insert multiple data at once
$sql = "INSERT INTO Food (Food, Price, Num_selected, Prepared)
VALUES ('Curry', 70, 0,0);";
$sql .= "INSERT INTO (Food, Price, Num_selected, Prepared)
VALUES ('Meat',150,0,0);"; // concatenate another string
$sql .= "INSERT INTO (Food, Price, Num_selected, Prepared)
VALUES ('Rice',60,0,0);"; // concatenate another string

if ($conn->multi_query($sql) === TRUE) { //more than one query
    echo "New records created successfully<br>";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
$conn->close();


$conn = new mysqli($server, $user, $pwd,"Smart");

//select data
$sql = "SELECT id,Food,Price FROM Food";
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
        echo "id: " . $row["id"]. " - Food: " . $row["Food"]. "   " . $row["Price"]. "<br/>";
    }
} else {
    echo "0 results";
  }



//get Sum
$result = $conn->query('SELECT SUM(Price) AS value_sum FROM Food');
$row = mysqli_fetch_assoc($result);
$sum = $row['value_sum'];
echo "$sum";

$conn->close();
 ?>
