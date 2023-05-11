# -*- coding: utf-8 -*-
"""
Created on Tue Nov 24 00:04:41 2020

@author: Teddy
"""
import tkinter as tk


class Pendu(tk.Frame):

    def __init__(self):
        super().__init__()

        self.initUI()


    def initUI(self):

        self.master.title("Pendu")
        self.pack(fill=tk.BOTH, expand=True)

        self.columnconfigure(1, weight=1)
        self.columnconfigure(3, pad=7)
        self.rowconfigure(3, weight=1)
        self.rowconfigure(5, pad=7)

        secretword = tk.Label(self, text="Peux tu trouver le mot :  ", font='Allegro')
        secretword.grid(column=1, pady=3, padx=5, sticky='W')

        canvasArea = tk.Frame(self, background='#a7f6d8')
        canvasArea.grid(row=1, column=1, columnspan=2, rowspan=4, padx=4, sticky='NESW') 

        button1 = tk.Button(self, text="Help")
        button1.grid(row=5, column=3, padx=5)

        button2 = tk.Button(self, text="OK")
        button2.grid(row=5, column=0, pady=5)
            
        buttonsArea = tk.Frame(self, background='#C0C0C0')
        buttonsArea.grid(row=1, column=0, padx=50)
        
        buttons = []
        
        for i in range(len("ABCDEFGHIJKLMNOPQRSTUVWXYZ")):          
            col = i % 4
            if i > 23 : col = i % 4 + 1
            
            buttons.append(tk.Button(
                buttonsArea, text=chr(65+i), font='Impact', height = 1, width = 4, background='#a2798f'))
            
            buttons[i].grid(row = i//4, column = col+1, padx=8, pady=8, sticky='NESW')


def main():

    window = tk.Tk()
    window.geometry("900x500")
    window.resizable(width=0, height=0)
    application = Pendu()
    window.mainloop()


if __name__ == '__main__':
    main()