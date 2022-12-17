import copy

class Operator:
    def __init__(self, op_type):
        self.op_type = op_type

    def __str__(self):
        return f"{self.op_type}"

    def __repr__(self):
        return self.__str__()

    def operate(self, state):

        new_state = copy.deepcopy(state)

        if (self.op_type == "U"):
            new_state.y_pos -= 1
        elif (self.op_type == "D"):
            new_state.y_pos += 1
        elif (self.op_type == "L"):
            new_state.x_pos -= 1
        elif (self.op_type == "R"):
            new_state.x_pos += 1

        return new_state