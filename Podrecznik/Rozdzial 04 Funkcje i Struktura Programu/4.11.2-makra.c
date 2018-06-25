#define  forever for(;;)  /* nieskończona pętla */
#define max(A, B) ((A) > (B) ? (A) : (B))
max(i++, j++) /* ŹLE */
#define square(x) x * x /* ŹLE */
np.: square(z+1);

#undef max
int max(A, B)
{

}

#define dprint(expr) printf(#expr " = %g\n", expr)  /* jeśli parametr poprzedzimy # to cały parametr będzie traktowany jako napis */
#define paste(front, back) front ## back  /* sklej początek z końcem */
paste(name, 1)  == name1;
