def singleton(cls):
    instance = {}
    def getInstance(*args, **kw):
        if cls not in instance:
            instance[cls] = cls(*args, **kw)
        return instance[cls]
    return getInstance

@singleton
class SC:
    def __init__(self, num):
        self.num = num

    def foo(self):
        print 'SC.foo'

class C:
    def foo(self):
        print 'C.foo'

if __name__ == '__main__':
    c1 = C()
    c2 = C()
    print 'id of c1: ', id(c1)
    print 'id of c2: ', id(c2)
    sc1 = SC(1)
    sc2 = SC(2)
    print 'id of sc1: ', id(sc1)
    print 'id of sc2: ', id(sc2)
    print 'sc1.num: ', sc1.num
    print 'sc2.num: ', sc2.num

