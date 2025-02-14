#include "TAArray.h"

TAArray::TAArray(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new TextArea*[capacity];
    for (int i = 0; i < capacity; ++i) {
        arr[i] = nullptr;
    }
}

TAArray::~TAArray() {
    for (int i = 0; i < size; ++i) {
        delete arr[i];
    }
    delete[] arr;
}

void TAArray::resize() {
    int newCapacity = capacity * 2;
    TextArea** resized = new TextArea*[newCapacity];

    for (int i = 0; i < size; ++i) {
        resized[i] = arr[i];
    }
    for (int i = size; i < newCapacity; ++i) {
        resized[i] = nullptr;
    }

    delete[] arr;
    arr = resized;
    capacity = newCapacity;
}

void TAArray::add(TextArea* ta) {
    if (size == capacity) {
        resize();
    }
    arr[size++] = ta;
}

bool TAArray::add(TextArea* ta, int index) {
    if (index < 0 || index > size) return false;
    if (size == capacity) resize();

    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
    }

    arr[index] = ta;
    size++;
    return true;
}

TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size) return nullptr;
    return arr[index];
}

TextArea* TAArray::get(const std::string& id) const {
    for (int i = 0; i < size; ++i) {
        if (arr[i] != nullptr && arr[i]->getId() == id) {
            return arr[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(const std::string& id) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] != nullptr && arr[i]->getId() == id) {
            TextArea* removed = arr[i];
            for (int j = i; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = nullptr;
            size--;
            return removed;
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= size) return nullptr;

    TextArea* removed = arr[index];
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = nullptr;
    size--;

    return removed;
}

int TAArray::getSize() const {
    return size;
}
