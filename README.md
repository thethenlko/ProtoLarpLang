#  ![protolarplang logo](https://github.com/thethenlko/ProtoLarpLang/blob/main/docs/protolarplang.png?raw=true) ProtoLarpLang  

Hello! Welcome to my language named ProtoLarpLang which is made on C!


## What is ProtoLarpLang?
**ProtoLarpLang** is a *simple programming language* that's was made without a goal to become a big programming language.
I have made this project just for **fun** :) 
Also this Project was a way to learn C


### Files in ProtoLarpLang ends with .prll 
## How to code in it?
 Very **simple!**
 While writing this README, this language only 2 commands
 
|Command| Purpose |
|--|--|
| say | Prints content |
| wait | Waits any amount of time |

---

### Know, every command after argument ends with keyword "OwO"
For example:
```
say Hello World OwO
say ProtoLarpLang yes OwO
```
Result:
```
Hello World
ProtoLarpLang yes
```
**This example is correct! Woo-ho!**

But what's going to happen if we remove "OwO"?
Another Example:
```
say Hello World
say ProtoLarpLang yes
```
Result:
```

```
Yes, **Nothing will be printed**
Why? Because ProtoLarpLang will doesn't know where to end so it will result **Nothing**.

---
### Alright, Now you understand what "OwO" does and the "say" command too (i hope)

Let's try **"wait" command**!

As you might guess, it's adds a delay in the code.

For example:

```
say Can you wait for 5 secs please? OwO
wait 5 OwO
say Thank you! OwO
```

Result:
```
Can you wait for 5 secs please?
*5 seconds delay*
Thank you!
```

That's it!

# How to use the compiler
First of all, check **releases page** for the compiler
**Compiler that's in releases is only for Linux so if you're on different OS (such as Windows or MacOS), you have to build it yourself.**

How to use it?

You have to put attach the file by using like this
```bash
$ ./prllc example.prll
```

# How to compile the ProtoLarpLang Compiler for different OS?

**Requirements: Have gcc installed on your system AND make**

1. Clone the repo: 
```bash
$ git clone https://github.com/thethenlko/ProtoLarpLang.git
```
2. Enter the directory that you copied the repo.
3. Type:
```bash
$ make
```
4. After it compiles, you should have a file named **"prllc.exe"** or something like that.
5. Follow the previous category that's explains how to use the prllc compiler.




# Thank you for reading!
Made by thethenlko (@thenlko) (also owner of protogen.name).
Have a great day! :D
