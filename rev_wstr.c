/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:43:49 by lusimon           #+#    #+#             */
/*   Updated: 2025/01/24 12:25:02 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_reverse(char *string)
{
	int start_word = 0;
	int end_word = 0;
	int current = 0;
	int i = 0;

	while(string[i] != '\0')
		i++;
	start_word = (i - 1); // we don't want the null terminator
	
	while (start_word >= 0)
	{
		end_word = start_word;
		current = start_word;
		while(start_word >= 0 && string[start_word] != ' ') //dont forget the string[start_word] != ' '
			start_word--;
		start_word++; // we don't want the white space 
		current = start_word;

		while(current <= end_word) // this allows us to write the word
		{
			write(1, &string[current], 1);
			current++;
		}
		if (start_word > 0) //if it is not the last word to write we want a space in between our words
		{
			write(1, " ", 1);
			start_word--; //Move to the actual space
		}
		start_word--; // Move to the previous end of word (skip the space)
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		print_reverse(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}