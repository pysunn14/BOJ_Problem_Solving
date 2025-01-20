def main():
    
    D = [0] * 1010
    D[1] = 0
    D[2] = 1
    D[3] = 1

    for i in range(4, 1001):
        if i % 2 == 0:
            D[i] = D[i-1] * 2 + 1
            
        else:
            D[i] = D[i-1] * 2 - 1

    try:
        while True:
            n = int(input())
            print(D[n])
            
    except EOFError:
        pass

if __name__ == "__main__":
    main()