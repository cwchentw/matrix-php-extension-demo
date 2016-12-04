<?php
$m = new Matrix(3, 3);
echo $m->get_at(1, 1), "\n";
$m->set_at(99, 1, 1);
echo $m->get_at(1, 1), "\n";
