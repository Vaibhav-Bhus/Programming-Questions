if __name__ == '__main__':
    N = int(input())
    temp = []
    List = []

    for i in range(N):
        x = input().split()
        temp.append(x)

    for i in range(len(temp)):
        if temp[i][0] == 'insert':
            x = int(temp[i][1])
            y = int(temp[i][2])
            List.insert(x,y)
        elif temp[i][0] == 'print':
            print(List)
        elif temp[i][0] == 'remove':
            List.remove(int(temp[i][1]))
        elif temp[i][0] == 'append':
            List.append(int(temp[i][1]))
        elif temp[i][0] == 'sort':
            List.sort()
        elif temp[i][0] == 'pop':
            List.pop()
        elif temp[i][0] == 'reverse':
            List.reverse()
