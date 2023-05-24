

# turns a string to a list
def str_to_list(string):
    first = []
    for letter in string:
        first.append(letter)
    return first
# some testing
x = ord("a")
d = chr(127)


word = (input("please enter phrase: "))
word = str_to_list(word)

# this block and for statement turns a list of characters into
# their corresponding ascii but rotated 13 characters forward.
phrase = []
for i in word:
    if ord(i) + 13 > 126:
        new = ord(i) + 13 - 126
        phrase.append(new)
    else:
        phrase.append(ord(i) + 13)

# generates a list with the rotated characters.
encryption = []
for k in phrase:
        if k < 31:
            encryption.append(chr(k + 31))
        else:
            encryption.append(chr(k))

for i in encryption:
    print(i, end="")

