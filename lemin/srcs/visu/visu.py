from tkinter import *
import fileinput
import time

def start_move_ants(paths, fenetre, canvas, room_id, img, ants_id):
    for path in paths:
        for ant in path:
            ant_nb = ant.split('-')[0][1:]
            room_name = ant.split('-')[1]
            origin = canvas.coords(ants_id[ant_nb])
            dest = canvas.coords(room_id[room_name])
            dest = (dest[0]+25, dest[1]+25)
            dx = dest[0] - origin[0]
            dy = dest[1] - origin[1]
            for x in range(30):
                canvas.move(ants_id[ant_nb], dx/30, dy/30)
                fenetre.update()

def start_visu(rooms, links, paths, start_room):
    resolution = 1100 / (max_coord - min_coord)
    fenetre = Tk()
    fenetre.title("Lem in")
    fenetre.geometry("1200x1300")

    canvas = Canvas(fenetre, width=1200, height=1200, background='black')
    canvas.pack()
    bouton=Button(fenetre, text="Fermer", command=fenetre.quit)
    bouton.pack()
    room_id = {}

#Create rooms
    for room in rooms:
        a = canvas.create_rectangle(room[1]*resolution, room[2]*resolution,
                room[1]*resolution+50,room[2]*resolution+50, fill='red')
        canvas.create_text(room[1]*resolution+25, room[2]*resolution+25,
                            text=room[0])
        room_id[room[0]] = a

#Create links between rooms
    for link in links:
        room1 = canvas.coords(room_id[link[0]])
        room2 = canvas.coords(room_id[link[1]])
        canvas.create_line(room1[0]+25, room1[1]+25, room2[0]+25, room2[1]+25,
                            fill='green')

#Create nb_ants ants on start room
    logo = PhotoImage(file='srcs/visu/ant.gif')
    ants_id = {}
    starting_room_coord = canvas.coords(room_id[start_room])
    for i in range(nb_ants):
        img = canvas.create_image(starting_room_coord[0]+25,
                                starting_room_coord[1]+25, image=logo)
        ants_id[str(i+1)] = img
    #fenetre.bind('<Button-1>', next_image(canvas, img, room1, room2))
    start_move_ants(paths, fenetre, canvas, room_id, img, ants_id)
    fenetre.mainloop()


data = open('solution','r').readlines()
data = [data[:-1] for data in data]
len_data = len(data)
nb_ants = int(data[0])

rooms = []
links = []
paths = []

min_coord = 3000000000
max_coord = 0

for i in range(1, len_data):
    split_room = data[i].split()
    if data[i] == '##start':
        start_room = data[i+1].split()[0]
    elif data[i][0] == '#':
        pass
    elif len(split_room) == 3:
        split_room[1], split_room[2] = int(split_room[1]), int(split_room[2])
        tmp = min(split_room[1], split_room[2])
        min_coord = tmp if min_coord > tmp else min_coord
        tmp = max(split_room[1], split_room[2])
        max_coord = tmp if max_coord < tmp else max_coord
        rooms.append(split_room)
    else:
        break

for x in range(i, len_data):
    split_link = data[x].split('-')
    if len(split_link) == 1:
        break
    elif data[x][0] == '#':
        pass
    else:
        links.append(split_link)

for j in range(x+1, len_data):
    paths.append(data[j].split())
start_visu(rooms, links, paths, start_room)
