# -*- coding: utf-8 -*-
import tkinter as tk, random # Import des modules

number = random.randint(1, 50) # déf du nombre à deviner
compteur = 0
buttons = []

window = tk.Tk() # Création de la fenêtre

def theAmazingWaiting(message): # Changer le label par une fonction
    description.config(text=message, font=("Trebuchet MS",30))

def guessIt(result): # Trouve nombre script
    global compteur
    buttons[result-1].config(state='disabled', bg='#BBBB99') # Désactive les bouttons quand used
    if number == result: # Si le nombre entré est égale au nombre du random
        description.place(relx=0.5, rely=0.12, anchor='center')
        description.config(text="") # Effacer le label avant l'attente
        window.after(300,lambda: theAmazingWaiting("T'as gagné mon gros !\n\nLa réponse était : ")) # Attend x secondes avant la mise à jour du label (ms)
        for i in buttons:
            i.config(state='disabled')
    elif number < result:
        description.config(text="")
        window.after(300,lambda: theAmazingWaiting("Le nombre est inférieur !"))
    elif number > result:
        description.config(text="")
        window.after(300,lambda: theAmazingWaiting("Le nombre est supérieur !"))
    compteur += 1

window.title("TrouveNombre") # Création du titre
window.geometry('900x650')# Résolutions de la fenêtre
#window.resizable(False,False) # Empêche la fenêtre de changer sa dimension x y

description = tk.Label(window, text="") # Création du label
description.place(relx=0.5, rely=0.2, anchor='center')
description.config(text="Bienvenue dans le jeu trouve nombre\nle principe est de trouver un nombre compris\nentre 1 et 10 en un minimum de coup", font=('Impact',25))
window.update()

window.after(3000,description.config(text = "Entrez un nombre\n", font=('Trebuchet MS',30))) # Modification du label existant

zone = tk.Frame(window, background='blue')

zone.place(relx=0.5, rely=0.6, anchor='center')
for i in range(50):
    buttons.append(tk.Button(zone, text = i+1,command = lambda var = i+1:guessIt(var),width = 15, height = 2, bg='#BBBB77'))
    buttons[i].grid(row = 1+i//5, column = i%5)
window.mainloop() # Maintenance de la fenêtre

#description.config(text = "Entrez un nombre\n", font=('Trebuchet MS',30)) # Modification du label existant
#window.update() # Actualise la fenêtre
#time.sleep(3) # Met en pause la fenêtre pour x secondes
#window.update() # Actualise la fenêtre
# idée : son, image, limite entre 0 et 50, finir le jeu avec replay, pseudo, quitter, compteur, score avec time, desactiver le waiting, couleur autour du bouton, sauvegarde + backup, sons

"""
numberInput = tkinter.StringVar() #  Création de la variable de l'input
entree = tkinter.Entry(window, textvariable=numberInput, width=20) # Création de l'input

boutonValider=tkinter.Button(window, text="Valider", font = ('Trebuchet MS',30), command=test) # Création du bouton Valider
boutonValider.pack() #  Alignement du bouton au centre
entree.pack() # Alignement du input au centre

"""

"""
window.attributes("-fullscreen", 1) # Plein écran
try: # ajout d'une exception pour éviter le crash en cas de dossier déjà créer - CREE UN DOSSIER
    os.mkdir('TrouveNombreFile') # Création du dossier du jeu
except:
    "sinon j'ai faim là en plus c'est chaud j'ai gray tout le mcdo y a même plus un ptit big mac"

os.rename(fichier,repertoire) deplace un fichier a un autre 
directory = pathlib.Path(__file__).parent # Trouve le chemin du fichier TrouveNombre.py NECESSITE PATHLIB

policeType = ["Trebuchet MS","Comic sans MS","Impact","Verdana"]
policeSize = [0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200]
def tkinterResolutions(): # Fonction des fenetres tkinter
    window.maxsize(int(window.winfo_screenheight()),int(window.winfo_screenwidth())) # Définit la taille maximum
    window.maxsize(int(window.winfo_screenheight() // 8),int(window.winfo_screenwidth() // 8)) # minimumow.winfo_screenheight() // 8),int(window.winfo_screenwidth() // 8)) # minimum
"""


"""
    elif number < int(numberInput.get()):


def imageTelechargor3000(url, filename):
    urllib.request.urlretrieve(url, filename)


imageTelechargor3000("https://www.zupimages.net/up/19/44/9ndo.gif", "background.gif") # Download le background
background = tkinter.PhotoImage(file = "background.gif") # Création de l'image dans tk
background_label = tkinter.Label(window, image = background) # Déf du background dans un label
background_label.place(x=0, y=0, relwidth = 1, relheight = 1) # Place le background au milieu""" # fond d'écran

