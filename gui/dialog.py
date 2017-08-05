import gtk, cairo
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
# ---------------------------------------------------------------------------------------------------#

class Color(dict):
    def __init__(self, red=0, green=0, blue=0):
        self["red"] = self.color_convert(red)
        self["green"] = self.color_convert(green)
        self["blue"] = self.color_convert(blue)

    def color_convert(self, value):
        return value*65535/255

    @staticmethod
    def grey_scale(value):
        return Color(value, value, value)

    @staticmethod
    def red(value=255):
        return Color(red = value)

    @staticmethod
    def green(value=255):
        return Color(green = value)

    @staticmethod
    def blue(value=255):
        return Color(blue = value)

class diag_box(gtk.EventBox):

	def __init__(self, color):
		gtk.EventBox.__init__(self)
		self.modify_bg(gtk.STATE_NORMAL, gtk.gdk.Color(**color))
		self.get_window().set_opacity(0.1)

	def expose(self, widget, event):
		pass
		
class dialogo(gtk.EventBox):	
	def __init__(self, d, t):
		gtk.EventBox.__init__(self)
		self.set_visible_window(t)
		self.connect("expose-event", self.change_bg, d.bg_image)

	def change_bg(self, widget, event, img):
		pixbuf = gtk.gdk.pixbuf_new_from_file(img)
		widget.window.draw_pixbuf(widget.style.bg_gc[gtk.STATE_NORMAL],pixbuf,0,0,0,0)
		if(widget.get_child()!=None):
			widget.propagate_expose(widget.get_child(), event)
		return True

janela = gtk.Window()

d = Dialog()
d.from_file_string('<Moreira><../Resources/img/k-on.jpg>"Chamei o uber"')

c = Dialog()
c.from_file_string('<Moreira><../Resources/img/gambi.png>"Chamei 2 uber"')

a = dialogo(d, True)
b = dialogo(c ,False)

a.add(b)



janela.add(a)
janela.show_all()

gtk.main()