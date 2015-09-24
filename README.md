#MY_PRINTF

This is a project developped during C classe in aims to understand system and to learn C

That function permit to understand some basics C

#Uses of the tool

##Download repository

```
git clone https://github.com/arn0f/my_printf
cd my_printf
```

##Compile it

I used a Makefile for an easiest compilation. You can use it as follow:

```
mkdir bin
make
```

##Try it

Binary file created is located in *bin/my_printf*. You can execute it as follow:

```
./bin/my_printf
```

#Implementation

*printf* function is avalaible on *my_printf.c* file.

That implementation is not the perfectest one. Your are free to improve it as you wish.

##Work 

Function works with:
*\*
*char
*int
*octal
*hexadecimal integer
*upper hexadecimal integer

Specifiers:
*%%
*%s
*%S (extended string)
*%b (binary)
*%x
*%X
*%d && %i
*%u (unsigned integer)
*%p
*%c
*%o (octal values)

Flags:
*+
*-
*(space)
*\#
*0
