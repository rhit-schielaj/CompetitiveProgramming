import sys
input = ""
for line in sys.stdin:
     input += line

dict = {
        "you" : "u",
        "are" : "r",
        "be" : "b",
        "for" : "4",
        "four" : "4",
        "too" : "2",
        "and" : "&",
        "owe" : "o",
        "bea" : "b",
        "two" : "2",
        "why" : "y",
        "to" : "2",
        "sea" : "c",
        "won" : "1",
        "at" : "@",
        "one" : "1",
        "eye" : "i",
        "oh" : "o",
        "see" : "c",
        "bee" : "b",
}

i = 0
lines = input.split("\n")
words = []
for line in lines[1:]:
    if line != lines[len(lines) - 1]:
        line = line + "\n"
    for word in line.split(" "):
        newWord = word
        piecesToChange = []

        for i in range(len(newWord) - 1):
            for j in range(len(newWord), 0, -1):
                for piece in dict:
                    if piece == newWord[i:j+1]:
                        newWord = newWord[0:i] + dict[piece] + newWord[j+1:]
                    if piece.title() == newWord[i:j+1]:
                        newWord = newWord[0:i] + dict[piece].title() + newWord[j+1:]

        # newPiecesToChange = piecesToChange
        # for piece1 in piecesToChange:
        #     for piece2 in piecesToChange:
        #         if piece1 != piece2 and piece1 in piece2:
        #             newPiecesToChange.remove(piece1)

        # newWord = word
        # for piece in newPiecesToChange:
        #     if piece.istitle():
        #         newWord = newWord.replace(piece.title(), dict[piece.lower()].title())
        #     else:
        #         newWord = newWord.replace(piece, dict[piece])
                
        words.append(newWord)

output = ""
for word in words:
    word += " "
    output += word.replace("\n ", "\n")
    
print(output)