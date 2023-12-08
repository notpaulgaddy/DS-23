def full_justify(text, length):
    words = text.split()
    lines = []
    line = []
    line_length = 0
    for word in words:
        if line_length + len(word) + len(line) <= length:
            line.append(word)
            line_length += len(word)
        else:
            lines.append(line)
            line = [word]
            line_length = len(word)
    lines.append(line)
    justified_text = ''
    for line in lines[:-1]:
        if len(line) == 1:
            justified_text += line[0] + '\n'
        else:
            spaces_to_distribute = length - sum(len(word) for word in line)
            space_between_words = spaces_to_distribute // (len(line) - 1)
            extra_spaces = spaces_to_distribute % (len(line) - 1)
            for i, word in enumerate(line):
                justified_text += word
                if i < len(line) - 1:
                    justified_text += ' ' * \
                        (space_between_words + (1 if i < extra_spaces else 0))
            justified_text += '\n'
    last_line = ' '.join(lines[-1])
    justified_text += last_line + ' ' * (length - len(last_line))
    return justified_text


array = ["Here is an example of text justification.",
         "\n"]
for line in array:
    if line != "\n":
        print(full_justify(line, 16))
