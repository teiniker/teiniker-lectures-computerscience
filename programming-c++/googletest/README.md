# GoogleTest Framework

GoogleTest is a testing framework developed by the Testing Technology team with 
Google’s specific requirements and constraints in mind. 

## Setup 

```
$ cd Downloads/
$ git clone https://github.com/google/googletest
$ cd googletest/
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ sudo make install 
```

```
/usr/local/lib/libgmock.a
/usr/local/include/gtest/gtest.h
```

## Using the Framework

```
$ g++ test.cpp -o test -lgtest -lgtest_main -pthread
```


## References
* [GoogleTest User’s Guide](https://google.github.io/googletest/)

* [YouTube (Google C++ Testing): GTest, GMock Framework Part- 1 : Introduction](https://youtu.be/nbFXI9SDfbk?si=aA0FZvMv6gr2yu7A)