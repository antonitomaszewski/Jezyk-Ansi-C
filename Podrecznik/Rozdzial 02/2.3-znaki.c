
/* ósemkowe są postaci '\ooo' gdzie ooo to 1 lub 2 lub 3 cyfry ósemkowe (0...7) */
#define VTAB '\013' /* ASCII: pionowy tabulator ósemkowo*/
#define BELL '\007' /* ASCII: znak alarmu ósemkowo */

/* szesnastkowe są postaci '\xhh' gdzie hh oznacza co najmniej 1 cyfrę szesnastkową (0...9,a...f,A...F) */
#define VTAB '\xb'  /* ASCII: pionowy tabulatur szesnastkowo */
#define BELL '\x7'  /* ASCII: znak alarmu szesnastkowo */

Sekwencje specjalne języka C:
\a  - znak alarmu
\b  - znak cofania
\f  - znak nowej strony
\n  - znak nowego wiersza
\r  - znak powrotu karetki  // ???
\t  - znak tabulacji poziomej
\v  - znak tabulacji pionowej
\\  - znak \
\?  - znak zapytania
\'  - znak apostrofu
\"  - znak cudzysłowu
\ooo  - liczba ósemkowa
\xhh  - liczba szesnastkowa
