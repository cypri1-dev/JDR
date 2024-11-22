# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parse_chapters.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 14:29:06 by cyferrei          #+#    #+#              #
#    Updated: 2024/11/22 15:37:32 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

input_file = "./test.txt"

output_file = "./parsed_chapters.json"

out = ""

with open(output_file, 'w') as output:
	out += "{\n"
	with open(input_file, 'r') as file:
		it = 1 #initialize to first chapter
		chapter = ""
		for line in file:
			try:
				if (it != int(line)): #compare the iterator the got chapter number
					raise SequentialError("Logical error") #raise an execption in case it breaks the order
				
				if (it != 1):
					formatted_chapter = f'"' + chapter + f'",\n' 
					out += formatted_chapter
					chapter = ""
				it += 1
				
				line = line[:len(line) - 2]
				key = f'  "{line}":'
				out += key
				# print(line)
			except:
				line = line[:len(line) - 1]
				line += "\\n"
				chapter += line
		formatted_chapter = f'"' + chapter[3:] + f'"\n' 
		out += formatted_chapter
	out += "}\n"
	output.write(out)