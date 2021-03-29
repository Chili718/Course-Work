#
#Title: Successful Flight Project
#
#Name: Jon Tice
#
#Description: Prototype of the Successful Flight Project using
#selected GUI
#
#Class: CSCI431
#
#Date: 3/20/18
#
from tkinter import *

class Mode:

    def __init__(self, mde, message):
        self.mde = mde
        self.message = message
        choices.append(self)
        names.append(mde)
#
#Function Name: pMessage
#
#Description: prints selected message when button is pressed
#will later run either of the modes chosen
#
#Parameters: None
#
#Return Value: None
#

def pMessage():
    for x in choices:
        if x.mde == select.get():
            chosen.set(x.message)
#window itself with size, title, and resizable permissions
root = Tk()

root.title("A Successful Flight")

root.resizable(width = FALSE, height = FALSE)

root.geometry('800x300')
#lists that hold the mode name and mode choices
choices = []
names = []
#creating the two different modes
Mode("Automatic Selection", "Display Month and Supporting Statistics")
Mode("Specific Selection", "Display Evaluation Criteria")

select = StringVar()
select.set(names[0])
#menu showing the choices for modes to run
menu = OptionMenu(root, select, *names)
menu.pack()
#button for the confimation of the selected option from drop menu
choiceBtn = Button(root, text="Start", command = pMessage)
choiceBtn.pack()
#the variable that holds the dummy selection text
chosen = StringVar()
#text label of the selected option which will later be the function of that option
put = Label(root, textvariable = chosen)
put.pack()

root.mainloop()