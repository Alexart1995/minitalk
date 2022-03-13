# minitalk

## About
The purpose of this project is to code a small data exchange program using UNIX signals.

## Mandatory
Produce server & client executables
client must communicate a string passed as a parameter to server (referenced by its process ID) which then displays it
Use SIGUSR1 & SIGUSR2 signals ONLY
## Bonus
Add reception acknowledgement system
Support Unicode characters

## Make commands
`make` to compile mandatory part.
`make bonus` to compile with bonuses(ACK and UNICODE).
`make clean` to clean all object files of libft.
`make fclean` to remove executable files.
`make re` to recompile this project.
## Usage
The server must be launched first, and after being launched it must display its PID.
```
$ ./server
PID: <PID_SERVER>

(wait)
```
After the server is started, in the second window of the term, start the client, as parameters, give it the server PID and the string
```
$ ./client <PID_SERVER> <STRING>
```
## Allowed Functions
malloc
free
write
getpid
signal
sigemptyset & sigaddset
sigaction
pause
kill
sleep
usleep
exit
