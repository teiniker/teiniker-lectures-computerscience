# Example: Database Access - Tracing System Calls

The following example shows how dynamic reverse engineering techniques can be 
used to analyze a client's communication with a database.

## Setup

We need a running database server and a command line client.

First, we start the MySQL server:
```
$ sudo systemctl start mariadb.service
```

As soon as the database verver is up, we connect the **mysql** console client to it.
We change the actual database and source the given SQL script `createTable.sql`.
```
$ mysql -u student -p
Enter password: student

MariaDB [(none)]> use testdb;
MariaDB [testdb]> source createTable.sql
```

## System Call Analysis

We attach **strace** to the running `mysql` process.
Using the **ps** command, we get the needed process ID (PID).
```
$ ps -a
 PID TTY          TIME CMD
 2194 pts/2    00:00:00 su
 2202 pts/2    00:00:00 bash
 2691 pts/0    00:00:00 vim
 2694 pts/3    00:00:00 mysql   <=
 2737 pts/1    00:00:00 ps

$ strace -p 2694 -s 1024
```

Now, we switch back to the mysql `console` and enter some **SQL statements**:
```
MariaDB [testdb]> select * from User;

read(0, "s", 1)                         = 1
write(1, "s", 1)                        = 1
read(0, "e", 1)                         = 1
write(1, "e", 1)                        = 1
...
write(3, "\23\0\0\0\3select * from User", 23) = 23
read(3, "\1\0\0\1\3(\0\0\2\3def\6testdb\4User\4User\2id\2id\f?\0\v\0\0\0\3\3B\0\0\0004\0\0\3\3def\6testdb\4User\4User\10username\10username\f!\0\300\0\0\0\375\1\20\0\0\0004\0\0\4\3def\6testdb\4User\4User\10password\10password\f!\0\0\3\0\0\375\1\20\0\0\0\5\0\0\5\376\0\0\"\0\20\0\0\6\0011\5homer\7*******\17\0\0\7\0012\4bart\7*******\17\0\0\10\0013\4lisa\7*******\5\0\0\t\376\0\0\"\0", 16384) = 237
times({tms_utime=0, tms_stime=6, tms_cutime=0, tms_cstime=0}) = 429889215
write(1, "+----+----------+------------------------------------------------------------------+\n", 85) = 85
write(1, "| id | username | password                                                         |\n", 85) = 85
write(1, "+----+----------+------------------------------------------------------------------+\n", 85) = 85
write(1, "|  1 | homer    | 2aaab795b3836904f82efc6ca2285d927aed75206214e1da383418eb90c9052f |\n", 85) = 85
write(1, "|  2 | bart     | 9551dadbf76a27457946e70d1aebebe2132f8d3bce6378d216c11853524dd3a6 |\n", 85) = 85
write(1, "|  3 | lisa     | d84fe7e07bedb227cffff10009151d96fc944f6a1bd37cff60e8e4626a1eb1c3 |\n", 85) = 85
write(1, "+----+----------+------------------------------------------------------------------+\n", 85) = 85
write(1, "\33(B\33[0;1m3 rows in set (0.01 sec)\n", 34) = 34
write(1, "\33(B\33[m\33(B\33[0;1m\n", 16) = 16
...
```

Because all the communication between the client and the database server is done via system calls,
we can see all the commands and data.

To stop `strace` hit [Ctrl-c]


*Egon Teiniker, 2020-2022, GPL v3.0*
