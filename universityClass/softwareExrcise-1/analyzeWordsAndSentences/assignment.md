# 1.2

( a | b ) \* · c => (任意のaかbで構成される文字列) + c

( a \* | b \* )·c => (0個以上のa or 0個以上のb) + c

# 2.1

a · ( ε | a ) => a or aa, LETTER(a) CONC LPAR EPSILON VERT LETTER(a) RPAR

a | c, a | | c, a | | | c, ... => a · \\| + · c

(1) or (2) => \( · ( 1 | 2 ) · \)
