Syntax Analysis Phase

Output: Syntax errors with line numbers

Steps to Compile & Run
1) lex parser.l
2) yacc parser.y
3) gcc y.tab.c -ll -w
4) ./a.out test1.c
