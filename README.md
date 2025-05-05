# Holberton school simple shell project
## (aka: Janky Shell™)

Janky Shell is a custom-built shell look-alike, designed to mirror some of the features contained in the UNIX Shell program. It was built as the final project in the C component of Holberton's Software Engineering course. It was built in two days and after more than a week of climbing mountains in New Zealand; as such, it is not great. We hope you enjoy.

## Key features
- the ability to handle all system calls that come standard in the UNIX Shell program
- argument handling for more granular control of these system calls
- shell built in commands:
	- env: displays user's environment
	- exit: exits Janky Shell
- support for interactive and non-interactive modes

### Installation
1. Go to the main page of this repo and click "<> Code"
2. Copy the link provided under HTTPS to clone using the web URL or, if you prefer to use GitHub's command line interface, copy the code provided in the GitHub CLI option
open terminal or equivalent.
3. Compile the code using gcc as shown
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
4. Enter Janky Shell by running ./hsh in your terminal, then follow the prompts, or else pipe commands to the program using something similar to the below code:
```
echo "ls" | ./hsh
```
5. Cross your fingers and hope that all goes according to plan

### Further reading
Greater detail about the commands available to users of Janky Shell can be found in the [man page](https://github.com/LetSamEqual/holbertonschool-simple_shell/blob/main/man_1_simple_shell).

### Authors
Sam Henderson
Anthony Hoang
