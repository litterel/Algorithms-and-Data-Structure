#ifndef MY_HEAP
#define MY_HEAP
#include <iostream>
template <typename T> class min_heap {
  private:
    // int size;
    int capacity;
    int size = 0;
    T *data;

    void shift_down(int root = 1) {
        int left, right, min_inx;
        while (root * 2 <= this->size) //当结点非树叶时进行下移
        {
            left = root * 2;
            right = std::min(root * 2 + 1, this->size);
            min_inx = left;
            //寻找叶节点中最大者
            if (this->data[left] > this->data[right])
                min_inx = right;
            //断是否需要置换
            if (this->data[root] > this->data[min_inx]) {
                std::swap(this->data[root], this->data[min_inx]);
                root = min_inx;
            } else
                break;
        }
    }

  public:
    min_heap(int capacity) {
        this->capacity = capacity;
        this->data = new T[capacity + 1];
    }
    min_heap(T arr[], int n) {
        this->capacity = n;
        this->data = new T[n + 1];
        this->size = n;
        for (int i = 0; i < n; i++)
            this->data[i + 1] = arr[i];

        for (int root = this->size / 2; root >= 1; root--)
            shift_down(root);
    }
    ~min_heap() { delete[] data; }

    void insert(T element) {
        if (this->size == this->capacity) {
            std::cout << "the minheap is out of capacity." << std::endl;
            return;
        }

        this->size += 1;
        this->data[size] = element;
        T temp_element = element;
        //用插入排序法自下而上对一条路径上的元素进行排序
        // int position = 1;
        int next_inx = size;
        int current_inx = size / 2;
        while (current_inx >= 1) {
            if (this->data[current_inx] > element) {
                this->data[next_inx] = this->data[current_inx];
                next_inx = current_inx;
                current_inx = current_inx / 2;
            } else
                break;
        }
        this->data[next_inx] = element;
    }

    T pop() {
        T temp = this->data[1];
        //最后一个元素放在首位，并将堆缩小一个元素
        this->data[1] = this->data[size];
        this->size -= 1;
        this->shift_down();
        return temp;
    }

    int get_size() { return this->size; }

    void display() {
        for (int i = 1; i <= size; i++) {
            std::cout << data[i] << ' ';
            if (i % 50 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
};

template <typename T> class max_heap {
  private:
    // int size;
    int capacity;
    int size = 0;
    T *data;

    void shift_down(int root = 1) {
        int left, right, max_inx;
        while (root * 2 <= this->size) //当结点非树叶时进行下移
        {
            left = root * 2;
            right = std::min(root * 2 + 1, this->size);
            max_inx = left;
            //寻找叶节点中最大者
            if (this->data[left] < this->data[right])
                max_inx = right;
            //断是否需要置换
            if (this->data[root] < this->data[max_inx]) {
                std::swap(this->data[root], this->data[max_inx]);
                root = max_inx;
            } else
                break;
        }
    }

    void shift_up(int node) {
        //用插入排序法自下而上对一条路径上的元素进行排序
        T temp_element = data[node];
        int next_inx = node;
        int current_inx = node / 2;
        while (current_inx >= 1) {
            if (this->data[current_inx] < temp_element) {
                this->data[next_inx] = this->data[current_inx];
                next_inx = current_inx;
                current_inx = current_inx / 2;
            } else
                break;
        }
        this->data[next_inx] = temp_element;
    }

  public:
    max_heap(int capacity) {
        this->capacity = capacity;
        data = new T[capacity + 1];
    }

    max_heap(T arr[], int n) {
        this->capacity = n;
        this->data = new T[n + 1];
        this->size = n;
        for (int i = 0; i < n; i++)
            this->data[i + 1] = arr[i];

        for (int root = this->size / 2; root >= 1; root--)
            shift_down(root);
    }

    ~max_heap() { delete[] data; }

    void insert(T element) {
        if (this->size == this->capacity) {
            std::cout << "the maxheap is out of capacity." << std::endl;
            return;
        }

        this->size += 1;
        this->data[size] = element;
        shift_up(size);
    }

    T pop() {
        T temp = this->data[1];
        //最后一个元素放在首位，并将堆缩小一个元素
        this->data[1] = this->data[size];
        this->size -= 1;
        this->shift_down();
        return temp;
    }

    int get_size() { return this->size; }

    void display() {
        for (int i = 1; i <= size; i++) {
            std::cout << data[i] << ' ';
            if (i % 50 == 0)
                std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif