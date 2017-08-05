def sub(string, s1, s2, start = 0):
    i = string.find(s1, start)+1
    e = string.find(s2, i)
    if(i < start or i == -1 or e == -1):
        return "", start
    return string[i:e], e


class Dialog:
    def __init__(self, bg_image = "./Resources/img/k-on.jpg", char = None, line = "test"):
        self.bg_image = bg_image
        self.name = "paulo"
        self.line = line
    def from_file_string(self, string):
        self.name, ii = sub(string, '<', '>')
        self.bg_image, it = sub(string, '<', '>', ii)
        self.line, ie = sub(string, '"', '"', it)

    def __str__(self):
        return ("Nome: {0}\nImagem: {1}\nTexto: {2}".format(self.name, self.bg_image, self.line))
class Script():
    def __init__(self, dialogs):
        self.dialogs = dialogs
