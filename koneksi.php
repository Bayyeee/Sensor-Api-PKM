<?php
$servername = "localhost"; // replace with your server name
$username = "jack"; // replace with your username
$password = "sayangbunda0098"; // replace with your password
$dbname = "api"; // replace with your database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
die("Connection failed: " . $conn->connect_error);
}