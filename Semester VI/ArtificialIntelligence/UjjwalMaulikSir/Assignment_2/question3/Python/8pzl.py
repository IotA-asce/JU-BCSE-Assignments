import copy


class State:
    def __init__(self, i_pos, j_pos, puzzle):
        self.i_pos = i_pos
        self.j_pos = j_pos
        self.puzzle = puzzle

    def shift(self,direction):
        if direction == 1:
            # up
            i,j = self.searchVoid()
            if i-1 >= 0:
                temp = self.puzzle[i][j]
                self.puzzle[i][j] = self.puzzle[i-1][j]
                self.puzzle[i-1][j] = temp
                return self
            return None        
        elif direction == 2:
            #down
            i,j = self.searchVoid()
            if i+1 < 3:
                temp = self.puzzle[i][j]
                self.puzzle[i][j] = self.puzzle[i+1][j]
                self.puzzle[i+1][j] = temp
                return self
            return None
        elif direction == 3:
            #left
            i,j = self.searchVoid()
            if j-1 >= 0:
                temp = self.puzzle[i][j]
                self.puzzle[i][j] = self.puzzle[i][j-1]
                self.puzzle[i][j-1] = temp
                return self
            return None
        elif direction == 4:
            #right
            i,j = self.searchVoid()
            if j+1 < 3:
                temp = self.puzzle[i][j]
                self.puzzle[i][j] = self.puzzle[i][j+1]
                self.puzzle[i][j+1] = temp
                return self
            return None
    
    def validatePos(self,i,j):
        return ((i >= 0 and i < 3) and (j >= 0 and j < 3))

    def printState(self):
        for i in self.puzzle:
            line = ""
            for j in i:
                line += str(j) + " "
            print(line)
        print()

    def searchVoid(self):
        for i in range(len(self.puzzle)):
            for j in range(len(self.puzzle[0])):
                if self.puzzle[i][j] == 0:
                    return i,j

    def validateFinalState(self):
        checkResult = True
        for i in range(len(self.puzzle)):
            for j in range(len(self.puzzle)):
                if self.puzzle[i][j] != finalStateMatrix[i][j]:
                    checkResult = False
                    return checkResult
        return checkResult


def operate():
    # choice = input("Enter 'd' for dfs : ")
    state = State(0,0,[[0,1,2],[3,4,5],[6,7,8]])
    dfs(state, 0, 0, "start")

    print("\nSolutins found are \n")
    for i in range(len(solutions)):
        print("Depth: " + str(depths[i]) + ", trace : " + solutions[i])

    ascDepth = copy.deepcopy(depths)
    ascDepth.sort()
    index = depths.index(ascDepth[0])
    print("\n\n_______________________________________________________")
    print("MOST OPTIMUM PATH : ")
    print("Depth: " + str(depths[index]) + ", trace : " + solutions[index])


def dfs(state, direction, depth, trace):
    state1 = state
    if(state == None or depth > 5):
        return
    elif state != None:
        if(direction != 0):
            state1 = copy.deepcopy(state)
            state1.shift(direction)
            if state1.validateFinalState(): 
                solutions.append(trace)
                depths.append(depth)
        # print(trace)
        # state1.printState()            
        dfs( state1, 1, depth+1, trace + "->UP")
        dfs( state1, 2, depth+1, trace + "->DOWN")
        dfs( state1, 3, depth+1, trace + "->LEFT")
        dfs( state1, 4, depth+1, trace + "->RIGHT")



finalStateMatrix = [
    [3,1,2],
    [0,4,5],
    [6,7,8]
]

solutions = []
depths = []
        
operate()