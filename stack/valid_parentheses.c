#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char match[256] = {0};
static char stack[10000] = {0};
static int top = -1;

void initMatch(void) {
    match[')'] = '(';
    match[']'] = '[';
    match['}'] = '{';
}

void push( char c) {
    stack[++top] = c;
}

char pop(void) {
    if (top == -1) return '\0';
    return stack[top--];
}

bool isMatch(char close, char open) {
    return (match[(int)close] == open);
}

bool isValid(char* s) {
    top = -1;
    initMatch();
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if ((c == '(') || (c == '[') || (c == '{')) {
            push(c);
        } else {
            char top_char = pop();
            if (!isMatch((int)c, top_char)) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    initMatch();  // once only

    char *tests[] = {"()", "()[]{}", "(]", "([)]", "{[]}"};
    int n = 5;

    for (int i = 0; i < n; i++) {
        printf("%s → %s\n",
               tests[i],
               isValid(tests[i]) ? "true" : "false");
    }
    return 0;
}

