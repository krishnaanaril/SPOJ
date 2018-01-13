import operator  
import sys

def sort_table(table, col=0):
    return sorted(table, key=operator.itemgetter(col))
    
if __name__ == '__main__':
    [n, m] = sys.stdin.readline().rstrip().split(' ')
    table = []
    for i in range(int(n)):
        table.append([int(x) for x in sys.stdin.readline().rstrip().split(' ')])
    k = sys.stdin.readline().rstrip();    
    for row in sort_table(table, int(k)):
        for column in row:
            sys.stdout.write("%s " %column)
        print ""
   
            
    
