# libsqlre
Regular expressions extension for sqlite3

On Linux, compile with:

```
$ gcc -g -fPIC -Wall -Werror -shared -lpcre -lsqlite3 -olibsqlre.so re.c
```

and copy libsqlre.so into a shared library directory.

To use:

```
$ sqlite3
SQLite version 3.7.17 2013-05-20 00:56:22
Enter ".help" for instructions
Enter SQL statements terminated with a ";"
sqlite> select load_extension('libsqlre');

sqlite> select '987-654-321' regexp '9[0-9]{2}-?[0-9]{3}-?[0-9]{3}';
1
sqlite> select regexp('9[0-9]{2}-?[0-9]{3}-?[0-9]{3}', '887-654-321');
0
sqlite>
```

No, I'm not Canadian.
