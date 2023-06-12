def check(a: int, b: int, value: int) -> bool:
    highest_mult = b // value
    highest_mult *= value
    return a <= highest_mult

def compute_largest_k(a: int, b: int, base: int) -> int:
    largest_k = 0
    value = 1
    k = 0
    while(value <= b):
        value *= base
        if value > b:
            break
        k += 1
        if(check(a, b, value)):
            largest_k = k
    return largest_k

def solve(a: int, b: int) -> int:
    twos = compute_largest_k(a, b, 2)
    fives = compute_largest_k(a, b, 5)
    return min(twos, fives)

def main():
    a, b = map(int, input().split())
    print(solve(a, b))

if __name__ == '__main__':
    main()
