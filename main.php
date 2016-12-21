<?php
$m = new Matrix(3, 3);
echo $m->get(1, 1), "\n";
$m->set(1, 1, 99);
echo $m->get(1, 1), "\n";
