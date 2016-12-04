# matrix PHP extension

A demo PHP extension implmented with Rust (see [here](https://github.com/cwchentw/libmatrix-rust-demo)) and glued with [PHP-CPP](http://www.php-cpp.com/).

## Demo

Rust doesn't generate header file automatically; therefore, you have to implement it by your self.  In this demo case, put `matrix.h` to `/usr/local/include` and `libmatrix.so`, generated from our Rust project, to `/usr/local/lib`.  Then, feed the following commands:

```
$ make
$ LD_LIBRARY_PATH=/usr/local/lib php -dextension=`pwd`/matrix.so main.php
```
