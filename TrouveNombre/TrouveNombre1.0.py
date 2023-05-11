# -*- coding: utf-8 -*-
import tkinter, random, time # Import des modules
window = tkinter.Tk() # Création de la fenêtre
number = random.randint(1, 10) # déf du nombre à deviner
compteur = 0

def theAmazingWaiting(message): # Changer le label par une fonction
    description.config(text = message, font=("Trebuchet MS",30))

def test(): # Trouve nombre script
    if number == int(numberInput.get()): # Si le nombre entré est égale au nombre du random
        description.config(text="") # Effacer le label
        window.after(300,lambda: theAmazingWaiting("T'as gagné mon gros !")) # Attend x secondes avant la mise à jour du label (ms)
    elif number < int(numberInput.get()):
        description.config(text="")
        window.after(300,lambda: theAmazingWaiting("Le nombre est inférieur !"))
    elif number > int(numberInput.get()):
        description.config(text="")
        window.after(300,lambda: theAmazingWaiting("Le nombre est supérieur !"))
    compteur += 1

window.title("TrouveNombre") # Création du titre
window.geometry('700x500') 
window.resizable(False, False)

numberInput = tkinter.StringVar() #  Création de la variable de l'input
entree = tkinter.Entry(window, textvariable=numberInput, width=20) # Création de l'input

description = tkinter.Label(window, text="Bienvenue dans le jeu trouve nombre\nle principe est de trouver un nombre compris\nentre 1 et 10 en un minimum de coup", font=('Impact',25)) # Création du label
description.pack() # Alignement du label au centre
description.place(x=350, y=250, anchor="center")

boutonValider=tkinter.Button(window, text="Valider", font = ('Trebuchet MS',30), command=test) # Création du bouton Valider
boutonValider.pack() #  Alignement du bouton au centre

window.update() # Actualise la fenêtre
#time.sleep(3) # Met en pause la fenêtre pour x secondes
description.config(text = "Entrez un nombre\n", font=('Trebuchet MS',30)) # Modification du label existant
entree.pack() # Alignement du input au centre
#window.update() # Actualise la fenêtre
time.sleep(1) # Met en pause la fenêtre pour x secondes
window.mainloop() # Maintenance de la fenêtre



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
def imageTelechargor3000(url, filename):
    urllib.request.urlretrieve(url, filename)


imageTelechargor3000("https://www.zupimages.net/up/19/44/9ndo.gif", "background.gif") # Download le background
background = tkinter.PhotoImage(file = "background.gif") # Création de l'image dans tk
background_label = tkinter.Label(window, image = background) # Déf du background dans un label
background_label.place(x=0, y=0, relwidth = 1, relheight = 1) # Place le background au milieu""" # fond d'écran

