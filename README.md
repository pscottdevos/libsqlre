# libsqlre
Regular expressions extension for sqlite3

## Compiling and Installing

### Linux
On Linux, compile with:

```
$ gcc -g -fPIC -Wall -Werror -shared -lpcre -lsqlite3 -olibsqlre.so re.c
```

and copy libsqlre.so into a shared library directory (/usr/lib64).

### Mac
On Mac, compile with:

```
$ gcc -g -fPIC -Wall -Werror -shared -lpcre -lsqlite3 -olibsqlre.dylib re.c
```

and copy libsqlre.dylib into a shared library directory (/usr/lib).


## Usage

To use:

```
$ sqlite3
SQLite version 3.7.17 2013-05-20 00:56:22
Enter ".help" for instructions
Enter SQL statements terminated with a ";"
sqlite> select load_extension('libsqlre');

sqlite> select '9987-654-3210' regexp '9-?[0-9]{3}-?[0-9]{3}-?[0-9]{4}';
1
sqlite> select regexp('9-?[0-9]{3}-?[0-9]{3}-?[0-9]{4}', '987-654-3210');
0
sqlite>
```
