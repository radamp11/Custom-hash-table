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
        ".": "",
        "{": "",
        "}": "",
        "`": "",
        "\\": "",
        "_": "",
        "!": "",
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

filename = "text_file.txt"

with codecs.open(filename, 'r', encoding='utf8') as f:
    text = f.read()
text = g(text)
with codecs.open(filename, 'w', encoding='utf8') as f:
    f.write(text)

print(text)
