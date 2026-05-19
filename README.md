*This project has been created as part of the 42 curriculum by atrombel and cgasser.*

* * * * *

Description
-----------

Minishell is a 42 School project consisting of recreating a simplified Unix shell inspired by Bash.

The project is an introduction to low-level Unix concepts such as:

-   process management,
-   signals,
-   file descriptors,
-   pipes and redirections,
-   environment variables,
-   terminal interaction.

The goal is to build a functional command-line interface capable of executing commands, handling pipes and redirections, managing environment variables, and reproducing the behavior of a real shell as closely as possible.

Beyond the technical aspect, the project aims to provide a deeper understanding of how a terminal shell works internally and to demystify --- or perhaps remystify --- the command line environment.

* * * * *

Project Architecture
--------------------

The project is divided into two main parts:

-   **Parsing**: analyzing and structuring the user input.
-   **Execution**: executing commands in the correct order while handling processes, pipes, and redirections.

The work was divided as follows:

-   **cgasser**: parsing and signal handling.
-   **atrombel**: execution and process management.

* * * * *

Parsing
-------

The parsing stage itself is divided into two successive steps:

### 1\. Lexing

The lexer analyzes the raw user input and categorizes each token as:

-   a redirection operator (`<`, `>`, `<<`, `>>`),
-   a pipe (`|`),
-   or a word (commands, arguments, filenames, etc.).

Quoted strings are preserved as single logical words.

### 2\. Parsing

The parser then organizes these tokens into command structures.

Each command structure groups:

-   the command name,
-   its arguments,
-   its redirections,
-   and the associated metadata required for execution.

When a pipe operator is encountered, a new command node is created and linked to the command list in execution order.

* * * * *

Instructions
------------

### Compilation

`bash make`

### Launch minishell

`bash ./minishell`

* * * * *

Resources
---------

### General Resources

-   GNU Readline Documentation\
    [https://tiswww.case.edu/php/chet/readline/readline.html](https://tiswww.case.edu/php/chet/readline/readline.html?utm_source=chatgpt.com)
-   signal(7) --- Linux manual page\
    [https://man7.org/linux/man-pages/man7/signal.7.html](https://man7.org/linux/man-pages/man7/signal.7.html?utm_source=chatgpt.com)
-   sigaction(2) --- Linux manual page\
    <https://man7.org/linux/man-pages/man2/sigaction.2.html>
-   exit(3) --- Linux manual page\
    <https://man7.org/linux/man-pages/man3/exit.3.html>
-   unset(1p) --- POSIX manual page\
    <https://man7.org/linux/man-pages/man1/unset.1p.html>
-   History of the Linux history command\
    <https://www.redhat.com/en/blog/history-command>
-   Understanding getenv()\
    <https://www.tutorialspoint.com/c_standard_library/c_function_getenv.htm>
-   PATH_MAX explanation\
    <https://eklitzke.org/path-max-is-tricky>
-   Minishell project article\
    <https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218>

* * * * *

AI Usage
--------

AI tools were used throughout the project primarily as learning and tutoring assistants rather than as code generators.

They were mainly used to:

-   explain Unix and shell-related concepts,
-   provide documentation and learning resources,
-   help debug difficult situations,
-   clarify signal handling and readline behavior,
-   review Makefiles and Git workflows,
-   improve technical understanding of parsing and process management,
-   and help format documentation.

All generated explanations and suggestions were manually reviewed, tested, and rewritten when necessary in order to fully understand and validate the final implementation.
