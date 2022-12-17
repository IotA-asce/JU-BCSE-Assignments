class State:
    

        self.parent = None
        self.on_operator = None

    def __str__(self):
        return f"({self.x_pos},{self.y_pos})"

    def __repr__(self):
        return self.__str__()

    def __eq__(self, other):
        return self.y_pos == other.y_pos and \
               self.x_pos == other.x_pos

    def is_valid(self, maze):
        try:
            return maze[self.y_pos][self.x_pos] == 1
        except:
            return False