# rdproc - System and Processes Information

`rdproc` tool is a line comand utility to get system and processes information using `/proc` directory.

## Use

rdproc [-s] [-l <interval> <duration>] [-p <pid>] [-f <pid>] [-t]

### Options

- `-s`: Prints system stadistics.
- `-l <interval> <duration>`: Prints system stadistics in a determined period of time.
- `-p <pid>`: Prints an especific process information.
- `-f <pid>`: Prints the open file limits for a process.
- `-t`: Prints the name of the current kernel stack trace symbol of a process.

## Funtionalities

### System Information

- Type and CPU model, number of cores, caché L1 and L2.
- Kernel version.
- Time elapsed since OS started.
- List of filesystem supported by the kernel.
- Partitions list with their filesystem.
- CPU name and its actual date and hour.

### System Stadistics (-s)

- Amount of CPU time used by users, system and IDLE process.
- Number of change of context.
- Number of process created since OS started.

### System Stadistics in Intervals (-l <interval> <duration>)

- Number of disk petitions performed.
- Memory amount given to hardware.
- Memory available amount.
- List of one minute load averages.


## Examples

### Get system information

rdproc


### Get system stadistics

rdproc -s

### Get system stadistics in intervals

rdproc -l 2 100

### Get information process

rdproc -p 123

### Get open file limits of a process

rdproc -f 123

### Get the kernel stack trace of a process

rdproc -t

## Author

Nicolás Melia



