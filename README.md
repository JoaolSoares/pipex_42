<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/pipexm.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-115%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# pipex
The  sixth project from 42<br>
This project is about creating a pipe system between two processes. The first process will take the commands and arguments from the standard input, and the second process will take the commands and arguments from the standard output. The first process will execute the first command and pass the output to the second process, which will execute the second command and pass the output to the standard output.

## How to use
- Clone the repository
- Run `make` or `make bonus` to compile the executable
- Run `./pipex file1 cmd1 cmd2 file2` to execute the program

## Example
Two commands
``` bash
./pipex infile "ls -l" "wc -l" outfile
```

More than two commands (bonus)
``` bash
./pipex infile "ls -l" "grep a" "wc -l" outfile
```
