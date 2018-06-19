/* lower: zamień c na małą literę; tylko dla ASCII */
int lower(int c)
{
        if (c >= 'A' && c <= 'Z')
                return c + 'a' - 'A';
        else
                return c;

}
