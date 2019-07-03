package com.superstudentregion.algorithm;

import java.lang.reflect.Array;
import java.util.Comparator;

/**
 * Create by StarkZhidian on 2019/7/1
 * Email: 1532033525@qq.com
 *
 * 最小堆的实现
 * @param <T> 堆储存的元素类型
 */
public class Heap<T> {
    /* 堆的容量 */
    private int capacity;
    /* 元素类型对应的类 */
    private Class<T> tClass;
    /*  根节点下标，为 0 */
    private final int rootIndex = 0;
    /* 储存元素的数组 */
    private T datas[];
    /* 当前的元素数目 */
    private int size;
    /* 用于确定元素顺序的比较器 */
    private Comparator<T> comparator;

    public Heap(int maxCapacity, Class<T> eleType) {
        this(maxCapacity, null, eleType);
    }

    public Heap(int maxCapacity, Comparator<T> comparator, Class<T> eleType) {
        if (maxCapacity <= 0) {
            throw new IllegalArgumentException();
        }
        capacity = maxCapacity;
        this.comparator = comparator;
        tClass = eleType;
        datas = (T[]) Array.newInstance(tClass, capacity);
    }

    public void insertEle(T ele) {
        if (ele == null) {
            throw new NullPointerException();
        }
        if (size < capacity) {
            datas[size] = ele;
            shiftUp(size++);
        } else {
            if (ele instanceof Comparable && ((Comparable) ele).compareTo(datas[rootIndex]) > 0) {
                datas[rootIndex] = ele;
                shiftDown(rootIndex);
            }
        }
    }

    public T getTop() {
        return size > 0 ? (T) datas[0] : null;
    }

    public T pop() {
        if (size > 0) {
            T res = (T) datas[0];
            datas[0] = datas[--size];
            shiftDown(rootIndex);
            return res;
        }
        return null;
    }

    public T[] heapSort() {
        int tSize = size;
        T[] eles = (T[]) Array.newInstance(tClass, tSize);
        T[] tObjs = (T[]) Array.newInstance(tClass, tSize);
        System.arraycopy(datas, 0, tObjs, 0, tSize);
        for (int i = 0; i < tSize; i++) {
            eles[i] = pop();
        }
        size = tSize;
        datas = tObjs;
        return eles;
    }

    public void display() {
        for (Object t : datas) {
            System.out.println(t);
        }
    }

    private void display1(int index) {
        if (index < 0 || index >= size) {
            return ;
        }
        System.out.println(datas[index]);
        display1((index << 1) + 1);
        display1((index << 1) + 2);
    }

    /**
     * 将下标为 index 的元素上调，以保证最小堆的特性
     *
     * @param index 要上调的元素下标
     */
    private void shiftUp(int index) {
        if (index < 0 || index >= size) {
            throw new IllegalStateException();
        }
        int currentIndex = index;
        int parentIndex;
        T parent;
        boolean needSwap;
        while (currentIndex != 0) {
            needSwap = false;
            parentIndex = (((currentIndex) & 1) == 1 ? currentIndex - 1 : currentIndex - 2) >> 1;
            // 利用元素自带比较器比较
            if (datas[currentIndex] instanceof Comparable) {
                if (((Comparable) datas[currentIndex]).compareTo(datas[parentIndex]) < 0) {
                    needSwap = true;
                }
            } else if (comparator != null && comparator.compare((T) datas[currentIndex], (T) datas[parentIndex]) < 0) {
                needSwap = true;
            }
            if (!needSwap) {
                break;
            }
            // 交换当前元素和父元素值
            parent = datas[parentIndex];
            datas[parentIndex] = datas[currentIndex];
            datas[currentIndex] = parent;
            currentIndex = parentIndex;
        }
    }

    /**
     * 将下标为 index 的元素节点下调，以保证最小堆的特性
     *
     * @param index 要下调的元素的下标
     */
    private void shiftDown(int index) {
        if (index < 0 || index >= size) {
            return ;
        }
        int minValueIndex = index;
        int leftChildIndex;
        int rightChildIndex;
        if ((leftChildIndex = (index << 1) + 1) < size) {
            minValueIndex = getMinValueIndex(minValueIndex, leftChildIndex);
        }
        if ((rightChildIndex = leftChildIndex + 1) < size) {
            minValueIndex = getMinValueIndex(minValueIndex, rightChildIndex);
        }
        // 如果当前最小的元素节点下标不等于当前元素下标，则交换两个节点值，并递归下调对应子元素
        if (minValueIndex != index) {
            swapIndexValue(minValueIndex, index);
            shiftDown(minValueIndex);
        }
    }

    private int getMinValueIndex(int index1, int index2) {
        if (index1 < 0 || index2 < 0 || index1 >= size || index2 >= size) {
            throw new IllegalStateException();
        }
        if (datas[index1] instanceof Comparable) {
            return ((Comparable) datas[index1]).compareTo(datas[index2]) < 0 ? index1 : index2;
        } else {
            return comparator.compare((T) datas[index1], (T) datas[index2]) < 0 ? index1 : index2;
        }
    }

    private void swapIndexValue(int index1, int index2) {
        if (index1 < 0 || index2 < 0 || index1 >= size || index2 >= size) {
            throw new IllegalStateException();
        }
        T t = datas[index1];
        datas[index1] = datas[index2];
        datas[index2] = t;
    }

    public static void main(String[] args) {
        Heap heap = new Heap<>(1000, Integer.class);
        for (int i = 0; i < 100; i++) {
            heap.insertEle(100 - i);
        }
        Integer[] objs = (Integer[]) heap.heapSort();
        for (int obj : objs) {
            System.out.println(obj);
        }
    }
}
