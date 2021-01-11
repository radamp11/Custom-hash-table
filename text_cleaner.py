import codecs

def g(text):
    replacements = {
        "Ą": "A",
        "ą": "a",
        "Ć": "C",
        "ć": "c",
        "Ę": "E",
        "ę": "e",
        "Ł": "L",
        "ł": "l",
        "Ń": "N",
        "ń": "n",
        "Ó": "O",
        "ó": "o",
        "Ś": "S",
        "ś": "s",
        "Ż": "Z",
        "ż": "z",
        "Ź": "Z",
        "ź": "z",
        "\"": "",
        "\'": "",
        "{": "",
        "}": "",
        "`": "",
        "\\": "",
        "_": "",
        "@": "",
        "#": "",
        "$": "",
        "%": "",
        "^": "",
        "&": "",
        "*": "",
        "(": "",
        ")": "",
        "-": "",
        "+": "",
        "=": "",
        "[": "",
        "]": "",
        "|": "",
        ";": "",
        "<": "",
        ">": "",
        "/": "",
    }
    text = "".join([replacements.get(c, c) for c in text])
    return text

filename_in = "text_file.txt"
filename_out = "text.txt"

with codecs.open(filename_in, 'r', encoding='utf8') as f:
    text = f.read()
text = g(text)
with codecs.open(filename_out, 'w', encoding='utf8') as f:
    f.write(text)