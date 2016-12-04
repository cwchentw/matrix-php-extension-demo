# matrix PHP extension

A demo PHP extension implmented with Rust (see [here](https://github.com/cwchentw/libmatrix-rust-demo)) and glued with [PHP-CPP](http://www.php-cpp.com/).

## Demo

Rust doesn't generate header and other related files automatically; therefore, you have to implement it by yourself.  In this demo case, put `matrix.h` to `/usr/local/include` and `libmatrix.so`, generated from our Rust project, to `/usr/local/lib`.  Then, add the path `/usr/local/lib` to `/etc/ld.so.conf.d/matrix.conf`.  Finally, feed the following commands:

```
$ make
$ php -dextension=`pwd`/matrix.so main.php
```
