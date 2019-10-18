# antialisedfontgenerator
Browser based tool to generate anti aliased fonts for embedded devices

To use:
https://joostn.github.io/antialisedfontgenerator/

Source: see gh-pages branch:
https://github.com/joostn/antialisedfontgenerator/tree/gh-pages

This is a quick hack to create anti-aliased bitmap fonts for use in microcontrollers. Enter the font name, pixel height, bits per pixel and which characters to create. The characters are written to an HTML canvas in your browser and pixels are read from there.

It outputs C data structures containing 1 big bitmap and an index for each character pointing to a section of the bitmap. I wrote this some time ago and dont use it anymore but perhaps it's useful to someone. 
jnucfonts.cpp shows how to get the rectangle for each character from the structs.