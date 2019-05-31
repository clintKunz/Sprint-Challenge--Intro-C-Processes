**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running -> The process is executing
Waiting -> The process is waiting for an event or resource
Stopped -> The process has been stopped
Zombie -> The process is dead but has not been removed 

**2. What is a zombie process?**
After a fork, a child process finishes before the parent, and the child stays in memory in case the parent needs information on the child process.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process gets created when a child process finishes before a parent process. The wait() system call cleans up the zombie process.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
A compiled language is more efficient because it does not use an interpreter. It also has more direct access to the machine, which can be beneficial. 
