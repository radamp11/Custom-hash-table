import codecs
import sys

def g(text):
    replacements = {
        ".": ",",
    }
    text = "".join([replacements.get(c, c) for c in text])
    return text

filename_in = "result_delete53.txt"
filename_out = "result_delete53.txt"

with codecs.open(filename_in, 'r', encoding='utf8') as f:
    text = f.read()
text = g(text)

#print(text)
with codecs.open(filename_out, 'w', encoding='utf8') as f:
    f.write(text)
