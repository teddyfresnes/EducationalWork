# -*- coding: utf-8 -*-
"""
Created on Tue Nov 24 00:04:41 2020

@author: Teddy
"""
import tkinter as tk
import random


class Pendu(tk.Frame):

    def __init__(self):
        super().__init__()
        
        self.buttons = []
        self.word = self.initWord()
        self.hiddenWord = ["_" for character in self.word]        
        self.testedLettersNumber = 0
        self.testedLettersText = ''
        self.lifes = 11 
        
        self.testedLettersLabel = tk.Label(self)
        self.hiddenWordLabel = tk.Label(self)
        self.messageLabel = tk.Label(self)
        
        self.canvasArea = tk.Frame(self)
        self.drawing = tk.Canvas(self.canvasArea)
        self.leftarm = None
        self.rightarm = None
        self.leftleg = None
        self.rightarm = None
        
        self.initUI()
        

    def initUI(self):        
        
        self.master.title("Pendu")
        self.pack(fill=tk.BOTH, expand=True)
        self.configure(background='#F08080')

        self.columnconfigure(1, weight=1)
        self.columnconfigure(3, pad=7)
        self.rowconfigure(3, weight=1)
        self.rowconfigure(5, pad=7)

        self.hiddenWordLabel.config(text="Peux tu trouver le mot :   "+' '.join(self.hiddenWord), font='Arial', background='#F08080')
        self.hiddenWordLabel.grid(column=1, pady=3, padx=5, sticky='W')
        
        self.testedLettersLabel.config(font=('Impact',15), background='#F08080')
        self.testedLettersLabel.grid(column=3)
        
        self.messageLabel.config(text='Bienvenue dans un pendu vraiment pas piqué des hannetons!', font=('Monaco',10,'bold italic'), background='#F08080')
        self.messageLabel.grid(column=1, row=5, pady=3, padx=5, sticky='W')

        self.canvasArea.config(background='#a7f6d8')
        self.canvasArea.grid(row=1, column=1, columnspan=2, rowspan=4, padx=1, pady=1, sticky='NESW')
        
        self.drawing.config(width=450, height=410, highlightthickness=0, bg='#a7f6d8')
        self.drawing.grid(sticky='NESW')
        self.drawing.create_line(20, 420, 430, 420, width = 100.0, fill="#3e2723")

        button1 = tk.Button(self, text="Fermer", font=('Copperplate',10), command=self.close, bg='#FFA07A')
        button1.grid(row=5, column=3, padx=5)

        button2 = tk.Button(self, text="Rejouer", font=('Copperplate',10), command=self.replay, bg='#FFA07A')
        button2.grid(row=5, column=0, pady=5)
            
        buttonsArea = tk.Frame(self, background='#CD5C5C')
        buttonsArea.grid(row=1, column=0, padx=50)
        
        for i in range(len("ABCDEFGHIJKLMNOPQRSTUVWXYZ")):
            #   Pour créer les boutons de chaque lettres               
            col = i % 4
            if i > 23 : col = i % 4 + 1
            
            self.buttons.append(tk.Button(
                buttonsArea, text=chr(65+i), font='Impact', height = 1, width = 4, background='#BBBB77',
                command = lambda pushedbutton = chr(65+i): self.initGame(pushedbutton)
                ))     # Appele la fonction initGame pour chaque bouton
            self.buttons[i].grid(row = i//4, column = col, padx=8, pady=8, sticky='NESW')


    def initWord(self):
        """Génère un mot pour le pendu"""
        try: # permet l'importation du fichier words.txt si il existe
            textFile = open('words.txt','r')
            for num, textFile in enumerate(textFile, 2): # prend une ligne au hasard
                if random.randrange(num):
                    randomWord = textFile
            textFile.close()
            
        except FileNotFoundError: # Liste de mots au cas où il n'y a pas le fichier words.txt
            wordsListToBeSure = ["CONCOMBRE","CIMENT","PIZZA","PHOTOSYNTHESE","SUSHI","TEDDY","POKEMON","CERCLE","SKI","IGLOO","WHISKY","VODKA","CHIPS","MOTEUR","BATON","FIGURINE","TONDEUSE","PLANCHE","SOUCHE","COURROIE","TOURNEVIS","CUTTER","NOUILLE","CYANURE","INFECTION","DROGUE","POISON","PENDAISON","DEPENDANCE","ALCOOLIQUE","IVRE","BLESSURE","HAINE","CARNAGE","TRAHISON","LACHE"]
            randomWord = random.choice(wordsListToBeSure)
            
        return randomWord
        
        
    def initGame(self,pushedButton): #   équivalent de la fonction test
        
        self.buttons[ord(pushedButton)-65].configure(state="disable", background='#BBBB99', fg="#ffab91") # Désactive les boutons et change couleurs
        
        self.testedLettersNumber += 1   #   Affiche les lettres utilisés par colonne de 2
        if self.testedLettersNumber % 2 == 0:
            self.testedLettersText = self.testedLettersText + pushedButton + '\n'
        else:
            self.testedLettersText = self.testedLettersText + pushedButton + ' '
        self.testedLettersLabel.config(text=self.testedLettersText, fg="#3e2723")
        
        theLetterDoesNotExists = True
        
        if ''.join(self.hiddenWord) != self.word: 
                  
            for i in range(len(self.word)):
                
                if pushedButton == list(self.word)[i]:
                    
                    self.hiddenWord[i] = pushedButton
                    theLetterDoesNotExists = False
                    
                self.hiddenWordLabel.config(text=' '.join(self.hiddenWord), font='Allegro')
                self.hiddenWordLabel.grid(sticky='NESW')
                
            if theLetterDoesNotExists:
                
                self.lifes -= 1
                self.drawMyHangedMan(self.lifes, self.drawing)
        
        if ''.join(self.hiddenWord) == self.word:

            self.victory()
        

    def drawMyHangedMan(self, lifes, canvas):
        if lifes == 10:
            canvas.create_line(65, 370, 65, 20, width = 25.0, fill="#6b452a") # potence
        if lifes == 9:
            canvas.create_line(65, 20, 380, 20, width = 25.0, fill="#6b452a") # poutre
        if lifes == 8:
            canvas.create_line(65, 120, 165, 20, width = 25.0, fill="#6b452a") # renfort
        if lifes == 7:
            canvas.create_line(320, 33, 320, 90, width = 5.0, dash=(4, 2), fill="#c0a37f") # corde
        if lifes == 6:
            canvas.create_oval(290, 90, 350, 150, width = 2.0, fill="#f3ba74") # tete
        if lifes == 5:
            canvas.create_rectangle(300, 150, 340, 250, width = 1.0, fill="#d12a16") # corps
        if lifes == 4:
            self.leftarm = canvas.create_line(300, 150, 240, 225, width = 20.0, fill="#d12a16") # bras gauche
        if lifes == 3:
            self.rightarm = canvas.create_line(340, 150, 400, 225, width = 20.0, fill="#d12a16") # bras droit
        if lifes == 2:
            self.leftleg = canvas.create_line(310, 250, 295, 340, width = 20.0, fill="#5258b2") # jambe gauche
        if lifes == 1:
            self.rightleg = canvas.create_line(330, 250, 345, 340, width= 20.0, fill="#5258b2") # jambe droite
            
        if lifes > 1:
            self.messageLabel.config(text="Raté, essaye encore ! Il te reste "+ str(lifes-1) +" chances !")
        if lifes == 1:
            
            canvas.delete(self.leftarm)
            canvas.delete(self.rightarm)
            canvas.delete(self.leftleg)
            canvas.delete(self.rightleg)
            
            canvas.create_rectangle(300, 150, 280, 240, width = 1.0, fill="#d12a16") # bras gauche
            canvas.create_rectangle(340, 150, 360, 240, width = 1.0, fill="#d12a16") # bras droit
            canvas.create_rectangle(300, 250, 320, 330, width = 1.0, fill="#5258b2") # jambe gauche     
            canvas.create_rectangle(320, 250, 340, 330, width= 1.0, fill="#5258b2") # jambe droite
            
            canvas.create_line(305, 105, 315, 115, width= 2.0, fill="black") # oeil 1
            canvas.create_line(315, 105, 305, 115, width= 2.0, fill="black")
            
            canvas.create_line(330, 105, 340, 115, width= 2.0, fill="black") # oeil 2
            canvas.create_line(340, 105, 330, 115, width= 2.0, fill="black")
            
            self.lose()
            
            
    def victory(self):
        
        for i in self.buttons:
            i.configure(state="disable", background='#4ea84d', fg="#1ae109")
        
        self.messageLabel.config(text="Incroyable vous avez gagné(e) !")
        self.hiddenWordLabel.config(text=self.word, bg='#11e200')
        
        
    def lose(self):
        
        for i in self.buttons:
            i.configure(state="disable", background='#d84141', fg="#908787")
        
        self.messageLabel.config(text="Vous avez perdu...! On dirait bien qu'il est pendu! :(")
        self.hiddenWordLabel.config(text=self.word, bg='#ff0000')
        
        
    def close(self):
        self.destroy()
        
    
    def replay(self):
        self.destroy()
        Pendu()
            
            
def main():

    window = tk.Tk()
    window.geometry("900x500")
    window.resizable(width=0, height=0)
    application = Pendu()
    window.mainloop()


if __name__ == '__main__':
    main()
    
    
"""A ameliorer
- Filtres initwords anti minuscules et anti accents
- Ajout tableau scores à la fin du jeu avec fichier sauvegarde
- Réparer le bouton close
- Ajout image en fin de jeu
- Ajout bouton "?"
- Ajout menu
- Entrée mot manuel
- Trouver fichier avec mots
"""
