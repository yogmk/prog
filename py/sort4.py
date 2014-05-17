#!/usr/bin/env python

def sort4(W,X,Y,Z):
    """sort4: sort 4 variables with if else statements"""
    w,x,y,z = W,X,Y,Z  # python's parallel assignment!

    while z<w or z<x or z<y or y<w or y<x or x<w:
        if w>=x:
            w,x=x,w
        if x>=y:
            x,y=y,x
        if y>=z:
            y,z=z,y

    print w,x,y,z            
    