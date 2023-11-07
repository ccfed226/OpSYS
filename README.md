# OpSYS
## Author: Jonathan Gillispie

Note
============
There are two versions of the code, I intend to have the .cpp files graded. While the C code does compile, the C++ code works better in my opinion. 

Consumer Producer Example
========================
A generic example of the consumer producer problem using semaphores to prevent modifying shared variables in the critical section. Algorithms like this would generally be used when adding and removing memory from the buffer. While the only thing this will do is print, "hello world" to the screen, it's nice to see how we would need to implement it. 

Starting the terminal
----------------------
A version of unix/linux will need installed. Otherwise, you can run this using a unix/linux emulator, or online through **www.github.com**. Regardless, you should see a **Terminal** tab somewhere, under it you'll see something like this:

```
$
```

This is where you type your commands. When you see the ``$`` in the following examples, *don't* type it. It's just there to show you where the commands are being entered. Press enter after typing a command to execute it. 

**Unix/linux doesn't use mousepads in the command line.** Unless you're switching between windows or applications, you likely won't need a mouse the whole time. 

Running and compiling the program
--------------------------
Type or copy the commands below to compile and then run the code. Again, don't type ``$`` into the command line, it's just there to show that the command goes into the command line. 
```
$ gcc producer.c -pthread -lrt -o producer
$ gcc consumer.c -pthread -lrt -o consumer
$ ./producer & ./consumer &
```

Example output
----------------------
Below are some examples of the code running. 
```
[1] 236550
[2] 236551

hello there!!!
hello there!!!
hello there!!!
hello there!!!
hello there!!!
hello there!!!
hello there!!!
hello there!!!
hello there!!!
[1]-  Done                    ./producer
[2]+  Done                    ./consumer
```
