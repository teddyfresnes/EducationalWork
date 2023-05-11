# -*- coding: utf-8 -*-
import tkinter as tk, random, unicodedata

findIt = lambda word, letter: [i for i, check in enumerate(word) if check==letter] # fonction retourne emplacement lettre d'un mot

def test(pushedbutton):
    global theword, tirets, compteurTirets
    buttons[ord(pushedbutton)-65].configure(state="disable") # desactive le boutton quand cliqué
    if pushedbutton in theword: # si la lettre est dans le mot
        for i in findIt(theword, pushedbutton):
            tirets = tirets[:i] + pushedbutton + tirets[i+1:] # rempli les lettres
            compteurTirets += 1
        word_label.config(text = tirets) # modifie le label du mot
        if len(tirets) <= compteurTirets: # vérifie si le mot est complet
            message = tk.Label(window, text="Vous avez réussi à trouver le mot : "+theword+" !")
            message.grid(row=5, column=0, columnspan=26) # position du label
    

words = ["concombre","ciment","pizza","photosynthèse","sushi"] # liste des mots possible
words = [((unicodedata.normalize('NFD', x).encode('ascii', 'ignore')).decode("utf-8")).upper() for x in words] # enlève accent et met maj (encode en bytes et decode en utf8 comme avant / upper pour les majuscules)
theword = random.choice(words) # choisit un mot aléatoire dans la liste - Methode procédurale : theword = words[random.randint(0,len(words)-1)]

compteurTirets = 0

window = tk.Tk()
window.title("Pendu")
window.geometry('900x500') # dimensions de la fenetre
window.resizable(width=0, height=0) # empeche le changement de resolution


tirets = "-" * len(theword) # créé mot de tirets en fonction de la longueur du mot

word_label = tk.Label(window, text=tirets) # label du mot
word_label.grid(row=0, column=1000, columnspan=1000) # position du label


canvas_drawing = tk.Canvas(window, width=300, height=320)
canvas_drawing.grid(row=1, column=0, columnspan=26)

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

buttons = []
zone = tk.Frame(window, background='blue') # créer zone pour les boutons
zone.grid(row=1, column=1, columnspan=40)

for i in range(len(alphabet)):
    col = i%4
    if i > 23 : col = i%4+1 # Pour la dernière rangée, permet de mettre les 2 dernières lettres au milieu
    buttons.append(tk.Button(
        zone, text=chr(65+i),  height = 3, width = 8, command= #AFFICHE LA LETTRE SUR LE BOUTTON chr pour passer à la lettre suivante, impossible de faire i + a puisque a est str
        lambda pushedbutton = chr(65+i):test(pushedbutton))) # boucle de la fonction pour créer chaque bouton + pour désactiver le bouton en cas de click
    buttons[i].grid(row = i//4, column = col+1, padx=3, pady=3, sticky='NESW')

window.mainloop()

#        alphabet = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]

  