# Enumerate the sequence of all lowercase ASCII letters, starting from 1, using enumerate.

ASCII_LETTERS = []
le = 'a'
for i in range(26):
    ASCII_LETTERS.append(chr(ord(le)+i))

print(list(enumerate(ASCII_LETTERS, 1)))
