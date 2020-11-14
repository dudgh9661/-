N = 0
M = 0
initFuel = 0

map = []
def INIT():
    INPUT = input().split(" ")
    print(INPUT)
    N = int(INPUT[0])
    M = int(INPUT[1])
    initFuel = int(INPUT[2])

    map = [[0]*N for i in range(0, 5) ]

    for i in range(0, N):
        INPUT = input().split(" ")
        for j in range(0, N-1):
            map[i][j] = int(INPUT[j])
    print(map)
    print(N, M, initFuel)

def main():

    INIT()

main()