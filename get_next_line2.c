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

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *get_next_line(int fd) {
  char *line = NULL;
  size_t line_capacity = 0;
  ssize_t line_length;
  char buffer[BUFFER_SIZE];
  size_t buffer_pos = 0;

  while (1) {
    ssize_t bytes_read = read(fd, buffer + buffer_pos, BUFFER_SIZE - buffer_pos);
    if (bytes_read == -1) {
      free(line);
      return NULL;
    } else if (bytes_read == 0) {
      if (line == NULL) {
        return NULL;
      } else {
        break;
      }
    }

    buffer_pos += bytes_read;

    for (size_t i = 0; i < buffer_pos; i++) {
      if (buffer[i] == '\n') {
        line_length = i + 1;
        line = realloc(line, line_capacity + line_length);
        if (line == NULL) {
          return NULL;
        }
        memcpy(line + line_capacity, buffer, line_length);
        line_capacity += line_length;
        memmove(buffer, buffer + line_length, buffer_pos - line_length);
        buffer_pos -= line_length;
        break;
      }
    }

    if (buffer[buffer_pos - 1] == '\n') {
      break;
    }

    line = realloc(line, line_capacity + BUFFER_SIZE);
    if (line == NULL) {
      return NULL;
    }
    memcpy(line + line_capacity, buffer, buffer_pos);
    line_capacity += BUFFER_SIZE;
    buffer_pos = 0;
  }

  line = realloc(line, line_capacity + buffer_pos);
  if (line == NULL) {
    return NULL;
  }
  memcpy(line + line_capacity, buffer, buffer_pos);
  line_capacity += buffer_pos;

  line = realloc(line, line_capacity + 1);
  if (line == NULL) {
    return NULL;
  }
  line[line_capacity] = '\0';

  return line;
  }
