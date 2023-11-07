# OpSYS
## Author: Jonathan Gillispie

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
Type or copy the commands below to compile and then run the code. Again, don't type ``$`` into the command line, it's just there to show that the command goes into the command line. "qewpfjkdaa" is just an example of a random string that you can name your shared memory. 
```
$ g++ producer.cpp -pthread -lrt -o producer
$ g++ consumer.cpp -pthread -lrt -o consumer
$ ./producer "qewpfjkdaa" & ./consumer "qewpfjkdaa"
```

Some modifications to the previous program
---------------------------------------
There were several core dumps, and generally items weren't added and removed from the table randomly. To fix this, random numbers were generated to call the sleep() function after the critical sections for the producer and consumer codes were finished. THen to prevent the producer from adding too many items to the table due to a longer waiting time from the consumer, the producer has been set to sleep for one second after every two iterations. For some reason the consumer code knows to wait for the producer to add items to the table, but the producer doesn't know if the table is full or not. Because of this, additional modifications will need to be make to improve the code. 

Example output
----------------------
Below are some examples of the code running. 
```
[13] 787918
Produced: hello there!!!
Produced: hello there!!!
Consumed: hello there!!!
Consumed: hello there!!!
Produced: hello there!!!
Consumed: hello there!!!
Produced: hello there!!!
Consumed: hello there!!!
Produced: hello there!!!
Consumed: hello there!!! 
[13]+  Done                    ./producer "qewpfjkdaa"
```
