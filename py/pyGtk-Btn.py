#!/usr/bin/env python

import pygtk
pygtk.require('2.0')
import gtk

class HelloWorld:
    
    def hello (self, widget, data=None):
        print "Hello World"
        
    def delete_event (self, widget, event, data=None):
        print "delete_event occured"
        return False         # False will emit destroy signal (handled below), True will not.
        
    def destroy (self, widget, data=None):
        gtk.main_quit()
        
        
    def __init__(self):
        # 1. create window
        # 2. connect events
        # 3. decorate the window (set border, add objects)
        # 4. display
        
        self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        
        self.window.connect("delete_event", self.delete_event)
        self.window.connect("destroy", self.destroy)
        
        self.window.set_border_width(10)
        self.button = gtk.Button("Hello world")
        self.button.connect("clicked", self.hello, None)
        self.button.connect_object("clicked", gtk.Widget.destroy, self.window)
        self.window.add(self.button)
        
        self.button.show()
        self.window.show()
        
    
    def main(self):
        # all pyGTK apps must have a gtk.main()
        # control ends here and waitd for an event
        gtk.main()
        
        
    # if the prog/script is run outside the python interpreter..
if __name__ == "__main__":
        h = HelloWorld()
        h.main()
        
        
        
        
