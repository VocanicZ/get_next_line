/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:18:37 by marvin            #+#    #+#             */
/*   Updated: 2022/11/04 22:18:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd) {
  static char buffer[BUFFER_SIZE];
  static size_t index = BUFFER_SIZE;
  static size_t length = 0;

  // Read more data from the file descriptor if the buffer is empty
  if (index >= length) {
    index = 0;
    length = read(fd, buffer, BUFFER_SIZE);
    if (length == 0) {
      return NULL; // EOF
    }
  }

  // Find the next newline character in the buffer
  size_t start = index;
  while (index < length && buffer[index] != '\n') {
    index++;
  }

  // Create a new string for the line
  size_t line_length = index - start;
  char *line = malloc(line_length + 1);
  strncpy(line, buffer + start, line_length);
  line[line_length] = '\0';

  // Advance the index past the newline character
  index++;

  return line;
}
