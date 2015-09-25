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

Binary file created is located in **bin/my_printf**. You can execute it as follow:

```
./bin/my_printf
```

#Implementation

**printf** function is avalaible on **my_printf.c** file.

That implementation is not the perfectest one. Your are free to improve it as you wish.

##Work 

Function works with:
<ul>
<li>*</li>
<li>char</li>
<li>int</li>
<li>octal</li>
<li>hexadecimal integer</li>
<li>upper hexadecimal integer</li>
</ul>

Specifiers:
<ul>
<li>%%</li>
<li>%s</li>
<li>%S (extended string)</li>
<li>%b (binary)</li>
<li>%x</li>
<li>%X</li>
<li>%d</li>
<li>%i</li>
<li>%u (unsigned integer)</li>
<li>%p</li>
<li>%c</li>
<li>%o (octal values)</li>
</ul>

Flags:
<ul>
<li>+</li>
<li>-</li>
<li>(space)</li>
<li>#</li>
<li>0</li>
</ul>
