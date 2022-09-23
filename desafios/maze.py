p = []
def print_maze(m):
    for v in m:
        print("".join(v))

    
maze = [
    "####################",
    "#i                 #",
    "### ###### # # ## ##",
    "# # #    # ### ## ##",
    "#     ## ##    ## ##",
    "#### ##  ## ###   ##",
    "#    ## # ###   # ##",
    "## #### # #   #   ##",
    "#  #      # ##### ##",
    "#### ###### ## ## ##",
    "####   #    #     ##",
    "########## #########",
]
maze = list(map(list, maze))
n, m = len(maze), len(maze[0])

for i, vi in enumerate(maze):
    for j, vj in enumerate(vi):
        if(vj == 'i'):
            p.append((i,j))
            break
    else:
        continue
    break

found = False

while not found:
    i,j = p[-1]
    maze[i][j] = '.'

    found = i == 0 or i == n-1 or j == 0 or j == m-1

    if not found:
        adjacent_positions = [
            (i-1,j), (i,j-1), (i+1, j), (i,j+1)
        ]

        pop = True

        for ai, aj in adjacent_positions:
            inside_matrix = i >= 0 and i < n and j >= 0 and j < m
            if inside_matrix and maze[ai][aj] == ' ':
                p.append((ai,aj))
                pop = False
        if pop:
            p.pop()
    print_maze(maze)
