import argparse

clp = argparse.ArgumentParser(prog='sum',
                              description='Compute the digital root of a non-negative integer')

clp.add_argument('n', type=int, help='non-negative integer')

args = clp.parse_args()
n = args.n

def digital_root1(n):
    while n > 9:
        total = 0
        for c in str(n):
            total += int(c)
        n = total
    return(n)

def digital_root(n):
    return(n) if n < 10 else digital_root(sum(map(int, str(n))))

print(f'digital root of {args.n} is {digital_root(n)}')
