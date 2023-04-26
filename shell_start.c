#include "shell_general.h"
#include "shell_main.h"
#include "shell_text.h"

/**
 * start - Handle the mode
 * Description: Mode can be INTERACTIVE or NON_INTERACTIVE
 * @info: Struct containing information about the shell
 *
 * Return: Nothing
 **/
void start(general_t *info)
{
start_prompt(info);
}

