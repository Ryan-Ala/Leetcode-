typedef struct stack
{
    int val;
    struct stack* next;
}stack;

stack* Initstack()
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->next = NULL;
    return s;
}
void pushstack(stack** L, int x)
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->val = x;
    s->next = *L;
    *L = s;
}

void popstack(stack** L, int* x)
{
    *x = (*L)->val;
    stack* s = *L;
    *L = (*L)->next;
    free(s);
}

int emptystack(stack* L)
{
    if (L->next == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int longestValidParentheses(char* s) {
    int count = 0, max = 0;
    stack* con = Initstack();
    con->val = -1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ')')
        {
            if (emptystack(con))
            {
                pushstack(&con, i);
            }
            else
            {
                if (s[con->val] == '(')
                {
                    int x;
                    popstack(&con, &x);
                    x = con->val;
                    count = i - x;
                }
                else
                {
                    pushstack(&con, i);
                    continue;
                }
            }
        }
        else
        {
            pushstack(&con, i);
        }
        if (max < count)
            max = count;
    }
    return max;
}