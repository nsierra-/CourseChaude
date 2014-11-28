CourseChaude
============

Really simple search engine.
Made with love by nsierra- and zleub (https://github.com/zleub) for a 2-days school contest.
Ended up 4th.

How to use it ?
---------------

```shell
$ git clone https://github.com/nsierra-/CourseChaude.git
$ cd CourseChaude
$ make
$ ./hotrace
```

Then enter a serie of key-value pair as follow :

```shell
key
value
...
```

When you're done, leave one space blank. You can now ask for value by typing them, the program will (almost) instantaneously output the corresponding value.

Use Case
--------

```
$ ./hotrace
This is my first key and it's quite cool
But not as cool as this fantastic first value !
Okay, well, you're kind of okay, but since I'm the SECOND key, I'm super better
I'm associated with a super-pretentious key.
cat
kitten
dog
woof
fish
blop

fish
blop
This is my first key and it's quite cool
But not as cool as this fantastic first value !
```

or

```
$ ./hotrace < super_big_key_value_file
```
