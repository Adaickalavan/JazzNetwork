#Question 2

def fn(v, lst=[]):
    lst.insert(0,v)
    print(lst)
    print(hex(id(lst)))

def main():
    
    fn(23)
    fn(16,[1, 2])
    fn([10], [3, 4])
    fn([11])

if __name__ == "__main__":
    main()
