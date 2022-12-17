from utils import get_operator_list, perform_BFS
from state import State

import numpy as np

# maze = np.array([[ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 ],
#                  [ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 ],
#                  [ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 ],
#                  [ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 ],
#                  [ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 ],
#                  [ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 ],
#                  [ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 ],
#                  [ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 ],
#                  [ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 ],
#                  [ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 ]])

maze = np.array([[ 1, 0, 0, 1, 0 ],
                 [ 1, 1, 1, 1, 1 ], 
                 [ 1, 0, 0, 1, 0 ], 
                 [ 1, 1, 1, 1, 1 ],
                 [ 1, 1, 0, 1, 1 ]])        

maze_rows, maze_columns = maze.shape

# Aim : To get from (0,0) to (9, 9)

operators = [
    "U",             # Go Up
    "D",             # Go Down
    "L",             # Go Left   
    "R",             # Go Right
]

def main():
    operator_list = get_operator_list(operators)

    initial_state = State(0, 0)
    final_states  = [ State(maze_rows-1, maze_columns-1) ]

    end_states = perform_BFS(maze, initial_state, final_states, operator_list)

    for k, end_state in enumerate(end_states):

        print(f"Approach: {k}")
        print("="*50)

        current_state = end_state
        state_list = []
        operator_seq = []

        while (current_state != initial_state):
            state_list.append(current_state)
            operator_seq.append(current_state.on_operator)
            current_state = current_state.parent

        state_list.reverse()
        operator_seq.reverse()

        for i, state in enumerate(state_list):
            print(f"{state.parent} + {operator_seq[i]} = {state}")

        print("="*50)

if __name__ == "__main__":
    main()