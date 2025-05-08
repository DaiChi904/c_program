# 3.1

((a | b∗ ) | c)

```
VERT
├── LETTER(c)
└─ VERT
   ├── LETTER(a)
   └── AST
       └── LETTER(b)

```

(a|(b ∗ |c))

```
VERT
├── LETTER(a)
└── VERT
    ├── AST
    │   └── LETTER(b)
    └── LETTER(c)
```

# 3.2

a · b∗ => (a · (b∗))

- ab

a | b∗ => (a | (b∗))

- EMPTY

# 3.3

match to (a | b∗) | c and not match to a | (b∗ | c) => none

not match to (a | b∗) | c and match to a | (b∗ | c) => none

: two regular expressions above have same meanings; a or b\* or c

# 3.4

12+-3\*2+5

```
expr
├── term
│   └── factor
│       └── primary
│           └── NUMBER(12)
├── PLUS
└── expr
    ├── term
    │   ├── factor
    │   │   ├── MINUS
    │   │   └── primary
    │   │       └── NUMBER(3)
    │   ├── TIMES
    │   └── term
    │       └── factor
    │           └── primary
    │               └── NUMBER(2)
    ├── PLUS
    └── expr
        └── term
            └── factor
                └── primary
                    └── NUMBER(5)
```

# 3.5

// TODO Need to check and fix

```
regex       ::= union
union       ::= concat ('|' concat)*
concat      ::= repeat+
repeat      ::= atom ('*' | '+' | '?')?
atom        ::= LETTER | '(' regex ')'
```

# 3.6

1: `32 + 4 * 3` は `term PLUS expr` に分解できる。

```
expr
├── term: 32
├── PLUS
└── expr: 4 * 3
```

2: `expr` である `4 * 3` は `term` として解析される。`factor TIMES term` に分解

```
expr
├── term
│   └── factor
│       └── primary
│           └── 32
├── PLUS
└── expr
    └── term
        ├── factor
        │   └── primary
        │       └── 4
        ├── TIMES
        └── term
            └── factor
                └── primary
                    └── 3
```
