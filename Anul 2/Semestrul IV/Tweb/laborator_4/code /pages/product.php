<?php
include 'data/products.php';

$id = $_GET['id'] ?? null;

if (!$id || !isset($products[$id])) {
  echo "<h1>Produsul nu a fost găsit!</h1>";
  exit;
}

$product = $products[$id];
?>
<!DOCTYPE html>
<html>
<head>
  <title><?= $product['title'] ?></title>
</head>
<body>

  <h1><?= $product['title'] ?></h1>
  <img src="<?= $product['image'] ?>" alt="<?= $product['title'] ?>" style="max-width:200px;">
  <p><strong>Descriere:</strong> <?= $product['description'] ?></p>
  <p><strong>Cantitate:</strong> <?= $product['qty'] ?></p>
  <p><strong>Rating:</strong> ⭐ <?= $product['rating'] ?></p>
  <p><strong>Preț:</strong> $<?= $product['price'] ?></p>
  <a href="index.php">← Înapoi la produse</a>

</body>
</html>
