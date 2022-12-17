from m_operator import Operator

def get_children(maze, current_state, operator_list):
    children = []

    for operator in operator_list:
        new_state = operator.operate(current_state)
        if (new_state.is_valid(maze)):
            new_state.on_operator = operator
            new_state.parent = current_state
            children.append(new_state)

    return children
    
def get_operator_list(operators):
    operator_list = []
    for operator in operators:
       operator_list.append(Operator(operator))
    return operator_list

def perform_BFS(maze, initial_state, final_states, operator_list):
    queue = [initial_state]
    explored_states = []

    terminal_states = []

    while (True):
        current_state = queue.pop(0)
        explored_states.append(current_state)

        if current_state in final_states:
            # return [current_state]
            terminal_states.append(current_state)
            if (len(queue) == 0):
                break
            else:
                continue

        children = get_children(maze, current_state, operator_list)
        for child in children:
            if child not in explored_states:
                queue.append(child)

        if (len(queue) == 0):
            break
    
    return terminal_states
