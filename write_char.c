#include <unistd.h>
#include "main.h"
/**
* write_char - outputs characters
* @c: character to output
* Return: int
*/

int write_char(char c)

{

write(1, &c, 1);

return (1);

}


