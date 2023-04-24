#include "general.h"
#include "main.h"
#include "text.h"

/**
 * start - Handle the shell mode (interactive or non-interactive)
 *
 * @info: Pointer to a general_t struct containing shell information
 */
void start(general_t *info)
{
	/* Call start_prompt function to begin shell mode handling */
	start_prompt(info);
}
