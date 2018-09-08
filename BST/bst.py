class t_node():

    def __init__(self, key, value):
        self.key = key
        self.value = key
        self.left = self.right = None

    def copy(self, node):
        self.key = node.key
        self.value = node.value
        self.left = node.left
        self.right = node.right


class bst():

    def __init__(self):
        self.__size = 0
        self.__root = None

    def get_size(self):
        return self.__size

    def __insert(self, key, value, node: t_node):

        if node == None:
            node = t_node(key, value)
            self.__size += 1
            return node
        if key == node.key:
            node.key = key
            node.value = value
        elif key < node.key:
            node.left = self.__insert(key, value, node.left)
        else:
            node.right = self.__insert(key, value, node.right)
        return node

    def insert(self, key, value):
        self.__root = self.__insert(key, value, self.__root)

    def __pre_order(self, node: t_node):
        if node == None:
            return
        print(node.key, end=' ')
        self.__pre_order(node.left)
        self.__pre_order(node.right)

    def pre_order(self):
        self.__pre_order(self.__root)

    def __in_order(self, node: t_node):
        if node == None:
            return
        self.__in_order(node.left)
        print(node.key, end=' ')
        self.__in_order(node.right)

    def in_order(self):
        self.__in_order(self.__root)
