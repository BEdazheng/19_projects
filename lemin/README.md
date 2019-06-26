# Lemin

Lemin is about finding the shortest solution for the ants to traverse an ant colony (or a graph) from one cell to another in as few turns as possible. We need to find the shortest path (and not the simplest) to achieve this.

Both the program input and output are text formatted and have a specific format. Input contains : number of ants, rooms, connections. Output contains : the input + the solution.

The constraints are:

* The project must be written in C language.
* An ant can only move once per turn.
* A cell can only contain up to one ant (except the start and end cells).
* Use the paths that take the fewest turn for the ants to go to the end room.

I used suurballe's algorithm's to find the K(2 or more) node-disjoint paths.
And for the path finding I used dijkstra and BFS.

# Rules

![Alt text](rules.png?raw=true "Rules")

# How to use it:

Clone the repo.
Go inside the repo (the program is already executed but you can make re if you want).

cat text_file &#124; ./lem-in.

To see the visualisation you have to put the output in a file called 'solution' like that.
Cat text_file &#124; ./lem-in > solution.
And then run.
srcs/visu/visu.py

Here is a visualisation (not done yet).

![](lemin.gif)
