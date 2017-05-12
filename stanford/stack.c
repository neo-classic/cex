void StackNew(stack *s)
{
    s->loglength = 0;
    s->alloclength = 4;
    s->elems = malloc(4 * sizeof(int));
    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
    free(s->elems);
}

void StackPush(stack *s, int value)
{
    if (s->loglength == s->alloclength) {
        s->alloclength *= 2;
        s->elems = realloc(s->elems, s->alloclength * sizeof(int));
        assert(s->elems != NULL);
    }
    s->elems[s->loglength] = value;
    s->loglength++;
}

int StackPop(stack *s)
{
    assert(s->loglength > 0);
    s->loglength--;
    return s->elems[s->loglength];
}