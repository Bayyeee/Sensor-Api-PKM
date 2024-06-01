<?php
// Start MySQL connection
include('koneksi.php');

// Array untuk menyimpan data
$data = array();

// Retrieve all records and store them in $data array
$result = $conn->query("SELECT * FROM deteksi_api ORDER BY id ASC");
while ($row = mysqli_fetch_assoc($result)) {
    $data[] = $row;
}

// Convert array to JSON
$json = json_encode($data);

// Output JSON
header('Content-Type: application/json');
echo $json;
