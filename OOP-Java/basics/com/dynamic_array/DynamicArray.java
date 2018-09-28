package com.dynamic_array;

public class DynamicArray {

    private int data[];
    private int nextIndex;

    public DynamicArray() {
        data = new int[25];
        nextIndex = 0;
    }

    public int size() {
        return nextIndex;
    }

    public void add(int element) {
        if (nextIndex == data.length) {
            restructure();
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    public void set(int index, int element) {
        if (index > nextIndex) {
            return;
        }
        if (index == nextIndex) {
            add(element);
        } else {
            data[index] = element;
        }
    }

    public int get(int index) {
        if (index > nextIndex) {
            //error out
            return -1;
        }
        return data[index];
    }

    public boolean isEmpty() {
        if (size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    public int removeLast() {
        if (size() == 0) {
            return -1;
        }
        int value = data[nextIndex - 1];
        data[nextIndex - 1] = 0;
        nextIndex--;
        return value;
    }

    private void restructure() {
        int[] temp = data;
        data = new int[2 * data.length];
        for (int i = 0; i < temp.length; i++) {
            data[i] = temp[i];
        }
    }
}
